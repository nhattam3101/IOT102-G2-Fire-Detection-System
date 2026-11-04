# IoT-Based Fire Detection and Warning System

**FINAL PROJECT REPORT — IOT102 (Fall 2026)**

| Field | Information |
|---|---|
| University | FPT University |
| Class | SE2027 |
| Group | G2 |
| Instructor | Nguyễn Đức Lợi (Nguyen Duc Loi) |
| Location | Ho Chi Minh City, Vietnam |
| Date | November 2026 |

### Group members

| Member | Student ID | Contribution |
|---|---|---|
| Hoang Nhat Tam | SE202018 | Project coordination, research and report writing |
| Phan Tan Hung | SE201027 | Firmware, integration and software testing |
| Le Vo Tuan Kiet | SE203376 | Hardware assembly, wiring and prototype verification |

The team proposes an equal contribution share (approximately 33.33% per member), subject to team confirmation.

> **Report status:** Full Markdown draft migrated from `IOT102_G2_main_order_fixed.tex`. Not yet a submission-ready, experimentally validated report. Prototype photo and quantitative measurements remain unavailable; report all eight cases as *team-reported functional PASS*, not 100% detection accuracy.

---

# Abstract

Fire incidents can cause significant damage to human life and property when early warning mechanisms are unavailable or ineffective. This project presents an ESP32-based fire detection and warning prototype integrating an LM35 temperature sensor, an MQ-2 smoke/gas sensor, and a flame sensor. The system employs a rule-based detection algorithm to classify environmental conditions into three states: SAFE, WARNING, and DANGER. Local feedback is provided through an LCD1602 display, three status LEDs, and an active buzzer. An SG90 servo motor simulates automatic door opening during dangerous conditions, while a push button supports manual door control when the system is not in the DANGER state. The prototype was evaluated using eight predefined functional test scenarios covering sensor detection, state transitions, and door-control behavior. All eight scenarios were reported as passing during group testing. The current implementation operates locally without cloud connectivity. Future development may include remote monitoring, improved sensor calibration, and false-alarm reduction techniques.

**Keywords:** Internet of Things, ESP32, Fire Detection, MQ-2, LM35, Flame Sensor, Early Warning System.

# Introduction

Fire detection and early warning play an important role in protecting residential environments, workplaces, and other indoor facilities. Undetected flames, abnormal temperature increases, and smoke or gas accumulation may lead to hazardous conditions. Early recognition of these indicators can support faster responses and reduce potential risks.

Traditional fire warning systems commonly depend on individual sensing mechanisms or local alarms. However, environmental disturbances such as cooking smoke may trigger unwanted warnings, while a single sensor may not adequately represent different fire conditions [1, 2]. Recent studies have investigated multisensor detection and more advanced classification methods to improve fire monitoring.

This project develops a low-cost fire detection and warning prototype using an ESP32 microcontroller. Three sensing components are integrated: an LM35 temperature sensor, an MQ-2 smoke/gas sensor, and a flame sensor. The ESP32 processes their readings locally and determines one of three operating states: SAFE, WARNING, or DANGER.

In addition to visual and audible warnings, the system uses an SG90 servo motor to demonstrate an automatic door-opening mechanism. A physical push button allows manual control when no dangerous condition is active.

The main objectives of this project are to:

1.  Integrate temperature, smoke/gas, and flame detection using an ESP32.

2.  Implement a three-level warning algorithm based on sensor signals.

3.  Provide local warnings through LEDs, an LCD, and a buzzer.

4.  Demonstrate automatic and manual door-control behavior.

5.  Verify system functionality through predefined test scenarios.

The present implementation focuses on local monitoring and actuator control. Wireless monitoring and configurable warning policies are considered future improvements rather than completed features.

## Related Work

Several studies have explored multisensor approaches to fire detection.

Yu et al. [1] investigated real-time fire alarm technology using signal similarity between multiple detectors. Their work combined temporal signal alignment and correlation analysis to support fire-event classification.

Fathoni et al. [2] proposed a multisensor fire and hazardous-gas detection system using an artificial neural network based on a Radial Basis Function Network. Their system processed flame, gas, temperature, and humidity information.

Purba et al. [3] developed an ESP32-based multi-hazard monitoring system using a hierarchical decision-tree approach. The system classified environmental conditions into SAFE, ALERT, and DANGER states.

Ramadani [4] presented an ESP32-based early fire detection system integrating flame and gas sensors with Blynk monitoring and Telegram notifications. This work demonstrates an approach to extending local detection with remote monitoring capabilities.

Other studies have examined gas sensor calibration, temporal signal analysis, and fuzzy-logic-based hazard assessment [5–7].

Compared with these approaches, the proposed G2 prototype employs a simpler rule-based algorithm. This design reduces implementation complexity and does not require a machine-learning training dataset. However, its fixed thresholds and digital detection inputs may be susceptible to environmental interference and false alarms.

# Methods and Materials

## System Architecture

The proposed prototype consists of three main functional layers: sensor acquisition, local processing, and warning/actuation.

The sensing layer includes the LM35 temperature sensor, MQ-2 smoke/gas sensor, and flame sensor. These devices provide environmental information to the ESP32 microcontroller.

The processing layer evaluates sensor inputs using a prioritized rule-based algorithm. The result determines the current warning state.

The output layer includes three LEDs, an active buzzer, a 16x2 I2C LCD, and an SG90 servo motor. The manual push button provides an additional input for door control.

Figure 1 illustrates the system architecture. Remote monitoring components present in the proposed architecture are not part of the implemented firmware.

**Figure 1. System architecture of the ESP32-based fire detection prototype. Cloud monitoring is a proposed future extension.**

![System architecture of the ESP32-based fire detection prototype. Cloud monitoring is a proposed future extension.](src/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png)

> **Image status:** Existing diagram includes proposed MQTT/Node-RED/dashboard; do not describe those as implemented.

## Hardware Components

The main controller is an ESP32 DevKit board with a 30-pin configuration and USB Type-C connection. Its GPIO interfaces support digital sensor input, analog measurement, I2C communication, and actuator control.

Table 1 summarizes the main components.

**Table 1. Main Hardware Components**

| **Component** | **Function**                                    |
|:--------------|:------------------------------------------------|
| ESP32 DevKit  | Central processing and control unit.            |
| LM35          | Measures temperature through an analog voltage. |
| MQ-2          | Provides a digital smoke/gas detection signal.  |
| Flame Sensor  | Provides a digital flame detection signal.      |
| LCD1602 I2C   | Displays sensor information and system status.  |
| Three LEDs    | Indicate SAFE, WARNING, and DANGER.             |
| Active Buzzer | Generates audible warning signals.              |
| SG90 Servo    | Simulates automatic door opening.               |
| Push Button   | Allows manual door control.                     |


## Circuit Design and GPIO Mapping

The prototype uses dedicated ESP32 GPIO pins for sensor inputs and output devices.

The final firmware pin assignments are summarized in Table 2.

**Table 2. ESP32 GPIO Assignments**

| **Device / Signal**         | **ESP32 GPIO** |
|:----------------------------|:---------------|
| LM35 Analog Output          | GPIO34         |
| MQ-2 Digital Output         | GPIO18         |
| Flame Sensor Digital Output | GPIO19         |
| LCD I2C SDA                 | GPIO21         |
| LCD I2C SCL                 | GPIO22         |
| Active Buzzer Control       | GPIO15         |
| Manual Button               | GPIO33         |
| SG90 Servo Signal           | GPIO32         |
| Green LED                   | GPIO25         |
| Yellow LED                  | GPIO26         |
| Red LED                     | GPIO27         |


The ESP32 development board receives a 5 V input supply. In the assembled prototype, the LM35 and active buzzer are powered from the board’s 3.3 V output. The buzzer was operated at a reduced supply voltage to lower the sound level during classroom demonstrations.

The nominal LM35 supply requirements and the operating range of the buzzer require separate verification against their respective component specifications. In addition, voltage levels from 5 V sensor modules and I2C pull-up connections must be checked for compatibility with ESP32 GPIO inputs.

Figure 2 presents the circuit schematic. It should be verified against the physical wiring before final submission.

**Figure 2. Circuit schematic and GPIO connections of the ESP32 prototype.**

![Circuit schematic and GPIO connections of the ESP32 prototype.](src/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png)

> **Image status:** Circuit is not independently electrically verified; check GPIO, 3.3V/5V logic, sensor supply and physical wiring.

## Sensor Data Processing

The LM35 generates an analog output voltage proportional to temperature, with a nominal scale factor of 10 mV per degree Celsius.

The temperature is calculated as:

$$T = \frac{V_{\mathrm{mV}}}{10}$$

where $T$ is the estimated temperature in degrees Celsius and $V_{\mathrm{mV}}$ is the measured sensor output voltage in millivolts.

The ESP32 firmware uses `analogReadMilliVolts()` to obtain voltage readings. Ten samples are collected, with a 5 ms delay after each reading, and their average is used to calculate temperature.

This averaging approach helps reduce random measurement fluctuations. However, it does not replace independent sensor calibration. ADC calibration and noise are discussed in the official Espressif documentation [8].

The MQ-2 and flame sensor modules are read through digital output pins. Both signals are treated as active LOW in the firmware. Therefore, a LOW input indicates an activated detection condition.

## Fire Detection Algorithm

The fire detection algorithm categorizes environmental conditions into three states: SAFE, WARNING, and DANGER.

Two temperature thresholds are configured:

$$T_{\mathrm{warning}} = 40^\circ C$$

$$T_{\mathrm{danger}} = 43^\circ C$$

The DANGER condition is defined as:

$$D = F \lor S \lor (T \geq 43)$$

where $F$ represents flame detection, $S$ represents MQ-2 detection, and $T$ represents the estimated temperature in degrees Celsius.

If $D$ is true, the system enters DANGER.

Otherwise, a temperature of at least $40^\circ C$ activates WARNING.

If neither condition is satisfied, the system remains in SAFE.

Table 3 summarizes the corresponding outputs.

**Table 3. System Warning States**

| **State** | **Condition**                                               | **Output Behavior**                             |
|:----------|:------------------------------------------------------------|:------------------------------------------------|
| SAFE      | No danger; temperature below 40°C                    | Green LED ON; buzzer OFF                        |
| WARNING   | No danger; temperature at least 40°C                 | Yellow LED ON; intermittent buzzer              |
| DANGER    | Flame OR MQ-2 detection OR temperature at least 43°C | Red LED ON; continuous buzzer; door forced OPEN |


The intermittent warning signal follows a nominal 500 ms ON and 500 ms OFF pattern. During DANGER, the buzzer remains continuously activated.

The SG90 servo is commanded to 90 degrees when DANGER is detected. Manual closing is disabled while the danger condition remains active.

When DANGER clears, the current door state is retained until a valid manual button action occurs.

The button is configured with `INPUT_PULLUP` and a 50 ms debounce interval.

Figure 3 illustrates the main decision flow.

**Figure 3. Fire detection and actuator control flowchart based on the final firmware.**

![Fire detection and actuator control flowchart based on the final firmware.](src/BlockDiagram_IOT102_G2-FlowChart.drawio.png)

> **Image status:** Represents SAFE/WARNING/DANGER with thresholds 40C and 43C.

## Software Implementation

The firmware is developed in the Arduino programming environment using the ESP32 hardware platform.

During initialization, the program configures GPIO directions, the ADC, I2C communication, serial communication, and servo control.

The LCD1602 is accessed through I2C using GPIO21 as SDA and GPIO22 as SCL. The firmware checks the common PCF8574 addresses 0x27 and 0x3F.

The main execution loop repeatedly performs sensor acquisition, state classification, warning output updates, button processing, and LCD/Serial status reporting.

Serial communication operates at 115200 baud and provides information for observing sensor and system states.

The implemented firmware does not include WiFi communication, MQTT, Node-RED, Blynk, or cloud logging.

# Results and Discussion

## Experimental Procedure

The prototype was evaluated through eight predefined functional test scenarios.

The objective of these tests was to verify whether the system produced the expected warning state and actuator behavior under selected input conditions.

The group reported that all eight scenarios behaved as expected.

The evaluation focused on functional behavior rather than statistical fire-detection performance.

## Functional Testing Results

Table 4 summarizes the test scenarios and their reported results.

**Table 4. Functional Test Results**

| **ID** | **Test Scenario**                                    | **Expected Behavior**                       | **Result** |
|:-------|:-----------------------------------------------------|:--------------------------------------------|:-----------|
| TC01   | Normal temperature, no flame or gas/smoke detection  | SAFE; green LED ON                          | PASS       |
| TC02   | Temperature in warning range; no other danger signal | WARNING; yellow LED and intermittent buzzer | PASS       |
| TC03   | Temperature at least 43°C                     | DANGER; continuous alarm                    | PASS       |
| TC04   | Flame sensor activated                               | DANGER; door opens                          | PASS       |
| TC05   | MQ-2 digital detection activated                     | DANGER; door opens                          | PASS       |
| TC06   | Manual button pressed during DANGER                  | Door remains open                           | PASS       |
| TC07   | Danger condition removed                             | Door retains its open state                 | PASS       |
| TC08   | Manual button pressed during SAFE                    | Door toggles position                       | PASS       |


All eight predefined functional scenarios were reported as passing during prototype testing.

This result indicates that the observed behavior matched the expected outcomes for the selected scenarios.

However, functional test completion should not be interpreted as a measured 100% fire-detection accuracy.

A statistically meaningful accuracy evaluation would require additional labeled fire and non-fire samples, repeated trials, and analysis of false-positive and false-negative events.

## Prototype Demonstration

The physical prototype integrates sensors, warning indicators, an LCD, and the SG90 door mechanism.

A photograph of the completed hardware will be inserted in the final report after the demonstration images have been collected.

**Figure 4. Physical prototype of the ESP32-based fire detection system.**

![Physical prototype of the ESP32-based fire detection system.](src/prototype.png)

> **Image status:** PLACEHOLDER ONLY: actual photo to be added.

## Discussion

The experimental observations support the basic functionality of the three-state warning mechanism and servo-control logic.

One advantage of the proposed design is that warning decisions are processed directly on the ESP32. Consequently, the local alarm does not require Internet connectivity.

The prioritized DANGER condition also allows the system to respond when a single sensor reports a potentially hazardous event.

However, the same design may trigger unwanted alarms when smoke or gas detection is caused by non-fire activities.

Research on multisensor fusion and signal analysis has demonstrated alternative approaches to distinguishing fire conditions from environmental interference [1, 5, 6].

The present prototype does not implement those advanced classification techniques. Instead, it prioritizes simplicity and functional demonstration.

Additional limitations include the absence of independently measured response latency, sensor accuracy, false-alarm rate, and long-term reliability data.

The assembled LM35 supply configuration and the interface voltage levels of 5 V modules also require hardware-level verification.

Furthermore, the servo represents a small-scale demonstration mechanism rather than a certified emergency door-control system.

# Conclusion

This project developed an ESP32-based fire detection and warning prototype using LM35, MQ-2, and flame sensors.

A rule-based algorithm classifies environmental conditions into SAFE, WARNING, and DANGER states.

The system provides local visual and audible warnings through three LEDs, an LCD1602 display, and an active buzzer.

An SG90 servo motor demonstrates automatic door opening during dangerous conditions, while a push button supports manual control outside the DANGER state.

The group reported successful functional behavior across eight predefined test scenarios.

The prototype demonstrates the feasibility of integrating multiple sensors, local warning indicators, and actuator control using ESP32. It is an educational prototype and has not been validated as a certified fire-safety device.

Future work may include sensor calibration, response-time measurement, false-alarm evaluation, adaptive warning policies, and remote monitoring through platforms such as Blynk.

These enhancements should preserve local safety functions even if network connectivity is unavailable.

# Author Contributions

All three members contributed equally to the project, with complementary responsibilities.

**Hoang Nhat Tam (SE202018):** Project coordination, task allocation, literature research, report preparation, and design review.

**Phan Tan Hung (SE201027):** ESP32 firmware development, sensor integration, warning logic, debugging, and functional testing.

**Le Vo Tuan Kiet (SE203376):** Hardware assembly, wiring, prototype integration, actuator testing, and hardware troubleshooting.

All members participated in system review, functional evaluation, and demonstration preparation.

## References

1. **`yu2023multidetector`** — M. Yu, H. Yuan, K. Li, and J. Wang, “Research on multi-detector real-time fire alarm technology based on signal similarity,” *Fire Safety Journal*, vol. 136, Art. no. 103724, 2023. doi: 10.1016/j.firesaf.2022.103724.
2. **`fathoni2025multisensor`** — K. Fathoni, A. F. Suni, N. Iksan, and M. S. Aziz, “Multisensor Integration in Early Fire and Gas Detection Based on Artificial Neural Network,” *Edu Komputika Journal*, vol. 12, no. 2, pp. 157–167, 2025. doi: 10.15294/edukom.v12i2.27436.
3. **`purba2026smartsafety`** — J. Purba, D. Kiswanto, J. B. Henrydunan, and R. Dly, “Smart Safety Room: ESP32 Decision Tree-Based Multi-Hazard Detection System,” *Journal of Artificial Intelligence and Engineering Applications*, vol. 5, no. 2, pp. 2627–2637, 2026. doi: 10.59934/jaiea.v5i2.1947.
4. **`ramadani2026blynk`** — N. Ramadani, “IoT-Based Early Fire Detection System using Flame and Gas Sensors with Telegram Bot and Blynk Dashboard Integration,” *Journal of Artificial Intelligence and Engineering Applications*, vol. 6, no. 1, pp. 603–612, 2026. doi: 10.59934/jaiea.v6i1.2805.
5. **`solorzano2022gas`** — A. Solorzano et al., “Early fire detection based on gas sensor arrays: Multivariate calibration and validation,” *Sensors and Actuators B: Chemical*, 2022. doi: 10.1016/j.snb.2021.130961.
6. **`nakip2021rtpnn`** — M. Nakip, C. Guzelis, and O. Yildiz, “Recurrent Trend Predictive Neural Network for Multi-Sensor Fire Detection,” *IEEE Access*, vol. 9, pp. 84204–84216, 2021. doi: 10.1109/ACCESS.2021.3087736.
7. **`rehman2021smartfire`** — A. Rehman et al., “Smart Fire Detection and Deterrent System for Human Savior by Using Internet of Things (IoT),” *Energies*, vol. 14, no. 17, Art. no. 5500, 2021. doi: 10.3390/en14175500.
8. **`espressif_adc_calibration`** — Espressif Systems, “Analog to Digital Converter (ADC) Calibration Driver,” *ESP-IDF Programming Guide*. [Online]. Available: `https://docs.espressif.com/projects/esp-idf/`

# AI Usage Declaration

Generative Artificial Intelligence (AI), particularly ChatGPT by OpenAI, was used as a supporting tool during the development and documentation of this project.

AI assistance was primarily used for exploring scientific literature, understanding technical concepts, reviewing system architecture, discussing sensor integration and fire detection logic, and improving the organization and academic language of the final report.

The project team critically reviewed AI-generated suggestions against the implemented source code, hardware design, technical documentation, and available functional testing results. AI-generated content was not automatically accepted as technically correct.

In particular, the team distinguished between implemented features and proposed future improvements, including remote monitoring through IoT platforms such as Blynk.

All final design decisions, implementation activities, experimental observations, and conclusions remain the responsibility of the project members.

Selected AI-assisted decisions, verification activities, and reflections are documented separately in the AI Audit Log.

---

## Codex editing notes (not part of the submitted report)

- Treat the last reviewed ESP32 firmware as the source of truth: GPIO34 LM35, GPIO18 MQ-2 digital, GPIO19 flame digital, GPIO21/22 LCD I2C, GPIO15 buzzer, GPIO33 button, GPIO32 servo, GPIO25/26/27 green/yellow/red LEDs.
- Thresholds: WARNING at 40°C; DANGER if flame OR MQ-2 detection OR temperature >=43°C. Button cannot close the door during DANGER.
- Preserve the distinction between *implemented local functionality* and proposed MQTT/Node-RED/Blynk/cloud extensions.
- Maintain the four figure slots/paths above. `src/prototype.png` is missing until the team provides an actual photo.
- Do not invent temperature readings, response times, false-alarm rates, calibration values, or external-app functionality.
- The circuit graphic was AI-generated and still requires electrical verification; MCU GPIOs are not 5V tolerant; check LM35 3.3V supply against exact model datasheet and current consumption of buzzer/servo.
- Before exporting to LaTeX/IEEE, review figure placement, 5–8-page course constraints, citation bibliographic correctness and final AI Audit Log separately.
- AI Audit Log is separate from this Final Project Report, while AI Usage Declaration belongs in the report.
