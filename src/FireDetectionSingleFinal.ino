
#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>

// ============ PIN DEFINITIONS ============

// Sensors
#define FLAME_PIN 19
#define MQ2_PIN 18
#define LM35_PIN 34

// Output devices
#define BUZZER_PIN 15

#define LED_GREEN 25
#define LED_YELLOW 26
#define LED_RED 27

// LCD I2C
#define SDA_PIN 21
#define SCL_PIN 22

// Servo & Button
#define SERVO_PIN 32
#define BUTTON_PIN 33

// ============ CONFIGURATION ============

const float TEMP_WARNING = 40.0;
const float TEMP_DANGER = 43.0;

const int FLAME_ACTIVE = LOW;
const int MQ2_ACTIVE = LOW;

// Door angles
const int DOOR_CLOSE_ANGLE = 0;
const int DOOR_OPEN_ANGLE = 90;
Servo doorServo;
bool doorOpen = false;

// Button debounce
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long DEBOUNCE_DELAY = 50;

// Warning buzzer: 500ms ON, 500ms OFF
const unsigned long BUZZER_INTERVAL = 500;

// LCD configuration
uint8_t lcdAddress = 0x27;
bool lcdAvailable = false;

#define LCD_RS 0x01
#define LCD_EN 0x04
#define LCD_BL 0x08

// ============ LCD FUNCTIONS ============

bool checkI2C(uint8_t address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission() == 0;
}

void lcdExpanderWrite(uint8_t data) {
  Wire.beginTransmission(lcdAddress);
  Wire.write(data | LCD_BL);
  Wire.endTransmission();
}

void lcdPulse(uint8_t data) {
  lcdExpanderWrite(data | LCD_EN);
  delayMicroseconds(1);

  lcdExpanderWrite(data & ~LCD_EN);
  delayMicroseconds(50);
}

void lcdWrite4Bits(uint8_t data, uint8_t mode) {
  lcdPulse((data & 0xF0) | mode);
}

void lcdSend(uint8_t data, uint8_t mode) {
  lcdWrite4Bits(data & 0xF0, mode);
  lcdWrite4Bits((data << 4) & 0xF0, mode);
}

void lcdCommand(uint8_t command) {
  lcdSend(command, 0);

  if (command == 0x01 || command == 0x02) {
    delay(2);
  }
}

void lcdWriteChar(char character) {
  lcdSend((uint8_t)character, LCD_RS);
}

void lcdInitialize() {
  delay(50);

  lcdPulse(0x30);
  delay(5);

  lcdPulse(0x30);
  delayMicroseconds(150);

  lcdPulse(0x30);
  delayMicroseconds(150);

  lcdPulse(0x20);

  lcdCommand(0x28);
  lcdCommand(0x0C);
  lcdCommand(0x06);
  lcdCommand(0x01);
}

void lcdPrintLine(int row, String message) {
  if (!lcdAvailable) return;

  lcdCommand(row == 0 ? 0x80 : 0xC0);

  for (int i = 0; i < 16; i++) {
    if (i < message.length()) {
      lcdWriteChar(message[i]);
    } else {
      lcdWriteChar(' ');
    }
  }
}

// ============ READ TEMPERATURE ============

float readTemperature() {
  uint32_t total = 0;

  for (int i = 0; i < 10; i++) {
    total += analogReadMilliVolts(LM35_PIN);
    delay(5);
  }

  float voltageMv = total / 10.0;

  // LM35: 10mV = 1 degree Celsius
  return voltageMv / 10.0;
}

// ============ OUTPUT CONTROL ============

void controlOutputs(bool danger, float temperature) {

  // Turn off LEDs
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  if (danger) {

    // DANGER: Red LED + continuous buzzer
    digitalWrite(LED_RED, HIGH);

    digitalWrite(BUZZER_PIN, HIGH);
  }
  else if (temperature >= TEMP_WARNING) {

    // WARNING: Yellow LED
    digitalWrite(LED_YELLOW, HIGH);

    // Intermittent buzzer using millis()
    bool buzzerState =
        (millis() / BUZZER_INTERVAL) % 2 == 0;

    digitalWrite(BUZZER_PIN,
                 buzzerState ? HIGH : LOW);
  }
  else {

    // SAFE: Green LED, both buzzers OFF
    digitalWrite(LED_GREEN, HIGH);

    digitalWrite(BUZZER_PIN, LOW);
  }
}

// ============ SETUP ============

void setup() {
  Serial.begin(115200);

  // Sensor inputs
  pinMode(FLAME_PIN, INPUT);
  pinMode(MQ2_PIN, INPUT);
  pinMode(LM35_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Outputs
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  // Initial state
  digitalWrite(BUZZER_PIN, LOW);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  // ADC setup
  analogReadResolution(12);
  analogSetPinAttenuation(LM35_PIN, ADC_0db);

  // I2C initialization
  Wire.begin(SDA_PIN, SCL_PIN);
  Wire.setClock(100000);

  if (checkI2C(0x27)) {
    lcdAddress = 0x27;
    lcdAvailable = true;
  }
  else if (checkI2C(0x3F)) {
    lcdAddress = 0x3F;
    lcdAvailable = true;
  }

  if (lcdAvailable) {
    Serial.print("LCD found at 0x");
    Serial.println(lcdAddress, HEX);

    lcdInitialize();

    lcdPrintLine(0, "FIRE DETECTION");
    lcdPrintLine(1, "SYSTEM START");

    delay(2000);
  }
  else {
    Serial.println("LCD NOT FOUND!");
  }

  // Servo configuration
  doorServo.setPeriodHertz(50);
  doorServo.attach(SERVO_PIN, 500, 2400);

  // Initially closed
  doorServo.write(DOOR_CLOSE_ANGLE);
  doorOpen = false;

  lastButtonReading = digitalRead(BUTTON_PIN);
  stableButtonState = lastButtonReading;
}

// ============ MAIN LOOP ============

void loop() {

  // 1. Read sensors
  bool flameDetected =
      digitalRead(FLAME_PIN) == FLAME_ACTIVE;

  bool smokeDetected =
      digitalRead(MQ2_PIN) == MQ2_ACTIVE;

  float temperature = readTemperature();

  // 2. Determine danger
  bool danger = flameDetected ||
                smokeDetected ||
                temperature >= TEMP_DANGER;
  
  updateDoor(danger);


  // 3. Determine status
  String status;

  if (danger) {
    status = "DANGER";
  }
  else if (temperature >= TEMP_WARNING) {
    status = "WARNING";
  }
  else {
    status = "SAFE";
  }

  // 4. Control LED and buzzer
  controlOutputs(danger, temperature);

  // 5. LCD display
  String line1 = "Temp: " +
                 String(temperature, 1) + " C";

  String line2 = "F:" +
                 String(flameDetected ? 1 : 0) +
                 " S:" +
                 String(smokeDetected ? 1 : 0) +
                 " " + status;

  lcdPrintLine(0, line1);
  lcdPrintLine(1, line2);

  // 6. Serial Monitor
  Serial.println("====== FIRE SYSTEM ======");

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.print("Flame: ");
  Serial.println(flameDetected ? "YES" : "NO");

  Serial.print("Smoke: ");
  Serial.println(smokeDetected ? "YES" : "NO");

  Serial.print("Status: ");
  Serial.println(status);

  Serial.print("Buzzer D15: ");

  if (danger) {
    Serial.println("CONTINUOUS");
  }
  else if (temperature >= TEMP_WARNING) {
    Serial.println("INTERMITTENT");
  }
  else {
    Serial.println("OFF");
  }

  Serial.println("=========================");
  
  updateDoor(danger);

  delay(50);
}

// ============== SERVO SETUP ===============

void setDoor(bool open) {

  if (doorOpen == open) return;

  doorOpen = open;

  if (open) {
    doorServo.write(DOOR_OPEN_ANGLE);
    Serial.println("DOOR OPEN");
  } else {
    doorServo.write(DOOR_CLOSE_ANGLE);
    Serial.println("DOOR CLOSED");
  }
}

void updateDoor(bool danger) {

  // DANGER always forces the door open
  if (danger) {
    setDoor(true);
  }

  // Read button
  bool reading = digitalRead(BUTTON_PIN);

  // Detect button signal change
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // Debounce button
  if (millis() - lastDebounceTime >= DEBOUNCE_DELAY) {

    if (reading != stableButtonState) {
      stableButtonState = reading;

      // A new press (LOW)
      if (stableButtonState == LOW) {

        // Manual control only outside DANGER
        if (!danger) {
          setDoor(!doorOpen);
        }
      }
    }
  }

  lastButtonReading = reading;
}

