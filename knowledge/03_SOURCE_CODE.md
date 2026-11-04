# Source code và triển khai kỹ thuật

## Mục đích và phạm vi

Tài liệu này là context chính để giải thích firmware, phân biệt implementation với kế hoạch và xác định phần chưa được build/test. Liên quan: [kiến trúc](02_ARCHITECTURE.md), [tiến độ](05_PROGRESS.md), [issues](06_ISSUES.md), [report guide](07_REPORT_GUIDE.md).

## Firmware được phát hiện

| Thuộc tính | Giá trị | Trạng thái |
|---|---|---|
| File | `IOT102-G2-Fire-Detection-System/Final/FireDetectionFinal/FireDetectionSingleFinal.ino` | **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Vị trí | Repository con, **không nằm trong `src/`** | **FACT:** `src/` chỉ có [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) |
| Quy mô | 401 dòng, 7.740 byte | **FACT** |
| Git | branch `main`, HEAD `db664d5`, 26/10/2026 21:04 +07; working tree sạch khi khảo sát | **FACT từ Git read-only**; không có release tag/phê duyệt nhóm |
| SHA-256 | `681712ce81bd67daadc0714de5cd460289291cd0cf0ed5f6e713fd5058a5eafc` | Dùng nhận diện snapshot khảo sát |
| Trạng thái | Candidate firmware hiện tại | **UNKNOWN:** chưa có build/upload/test log; tên `Final` không chứng minh đã nghiệm thu |

Repository còn có README gốc [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), README Final [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) và [`.gitignore`](../IOT102-G2-Fire-Detection-System/.gitignore) [SRC-026].

## Ngôn ngữ, framework và thư viện

| Thành phần | Bằng chứng | Kết luận |
|---|---|---|
| Arduino C++ | `.ino`, `setup()`, `loop()`, API Arduino | **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino) |
| `Arduino.h` | `#include <Arduino.h>` | **FACT**, version **UNKNOWN**; dòng 2 |
| `Wire.h` | I²C LCD tự triển khai | **FACT**, version theo core **UNKNOWN**; dòng 3/61–135 |
| `ESP32Servo.h` | Servo object, 50 Hz, attach GPIO32 | **FACT**, version **UNKNOWN**; dòng 4/40/253–259 |
| Board | README yêu cầu `ESP32 Dev Module` | **FACT theo hướng dẫn:** [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) |

Không có `platformio.ini`, Arduino CLI config, lockfile, library manifest hoặc version pin. README hướng dẫn Verify/Upload nhưng không phải log chứng minh đã build. [SRC-024](../IOT102-G2-Fire-Detection-System/README.md)

## GPIO và cấu hình

| Thiết bị | GPIO | Cấu hình trong code | Dòng |
|---|---:|---|---:|
| Flame DO | 19 | `INPUT`, active LOW | 9, 34, 200, 270–272 |
| MQ-2 DO | 18 | `INPUT`, active LOW | 10, 35, 201, 273–274 |
| LM35 OUT | 34 | `INPUT`, ADC 12-bit, `ADC_0db` | 11, 139–150, 202, 221–223 |
| Buzzer 1 | 27 | `OUTPUT`; liên tục khi DANGER | 14, 167/175/189, 206 |
| Buzzer 2 | 15 | `OUTPUT`; 500 ms ON/OFF WARNING, liên tục DANGER | 15, 50–51, 168/177–182, 207 |
| LED xanh | 23 | SAFE | 17, 187 |
| LED vàng | 25 | WARNING | 18, 173 |
| LED đỏ | 26 | DANGER | 19, 165 |
| LCD SDA/SCL | 21/22 | I²C 100 kHz | 22–23, 225–227 |
| Servo | 32 | 50 Hz, pulse 500–2400 µs, 0°/90° | 26, 37–40, 253–259 |
| Button | 33 | `INPUT_PULLUP`, nhấn LOW, debounce 50 ms | 27, 43–48, 203, 367–400 |

Nguồn toàn bảng: [SRC-023](../src/FireDetectionSingleFinal.ino). Pin map khớp tài liệu bàn giao [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), nhưng chưa khớp hoàn toàn schematic cũ [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>).

## Ngưỡng và thuật toán

- `TEMP_WARNING = 40.0°C`, `TEMP_DANGER = 45.0°C`. **FACT:** dòng 31–32.
- `danger = flameDetected || smokeDetected || temperature >= 45°C`. **FACT:** dòng 278–281.
- Nếu DANGER: LED đỏ + cả hai buzzer HIGH; cửa bị ép mở. **FACT:** dòng 162–169/367–372.
- Nếu không DANGER và `temperature >= 40°C`: LED vàng, buzzer 1 tắt, buzzer 2 luân phiên mỗi 500 ms bằng `millis()`. **FACT:** dòng 170–183.
- Còn lại SAFE: LED xanh, hai buzzer tắt. **FACT:** dòng 184–191.
- Không có hysteresis, latching alarm, calibration table, sensor-fault detection hoặc MQ-2 warm-up state trong code. **FACT về sự vắng mặt**; tác động cần thí nghiệm.

## Vai trò của hàm

| Hàm | Vai trò thực tế | Lưu ý |
|---|---|---|
| `setup()` | Serial 115200; pin modes/default output; ADC; I²C/LCD; attach Servo và đóng cửa; lấy button state ban đầu | Dòng 196–263; LCD tự dò 0x27 rồi 0x3F |
| `loop()` | Đọc sensor; tính danger/status; xử lý cửa; điều khiển LED/buzzer; cập nhật LCD/Serial; delay 50 ms | Dòng 267–348 |
| `readTemperature()` | Trung bình 10 lần `analogReadMilliVolts()`, cách 5 ms; `°C = mV/10` | Dòng 139–150; calibration **UNKNOWN** |
| `controlOutputs()` | Mapping state → LED/buzzer | Dòng 155–192 |
| `checkI2C()` | Probe địa chỉ LCD | Dòng 63–66 |
| `lcdExpanderWrite()`…`lcdPrintLine()` | Driver LCD1602/PCF8574 4-bit tự viết, mỗi dòng 16 ký tự | Dòng 68–135; mapping backpack cần xác minh |
| `setDoor()` | Chỉ ghi Servo khi trạng thái cửa đổi; cập nhật `doorOpen` | Dòng 352–365 |
| `updateDoor()` | DANGER ép mở; debounce button; toggle cửa nếu không DANGER | Dòng 367–400 |

## Luồng chạy chính

```text
setup
  -> Serial/GPIO/ADC/I2C
  -> dò LCD 0x27 hoặc 0x3F
  -> attach Servo, đóng cửa

loop
  -> đọc Flame/MQ-2/LM35
  -> tính DANGER
  -> updateDoor(DANGER)
  -> chọn chuỗi DANGER/WARNING/SAFE
  -> LED + buzzer
  -> LCD + Serial
  -> updateDoor(DANGER) lần 2
  -> delay(50 ms)
```

**FACT:** `updateDoor()` bị gọi hai lần ở dòng 283 và 345. **INFERENCE:** lời gọi thứ hai dư thừa, tăng khó khăn khi reasoning về debounce; do `stableButtonState` chỉ đổi một lần nên chưa đủ bằng chứng để kết luận sẽ double-toggle. Cần test button ở ranh giới 50 ms.

## Tính năng có/không có trong code

| Tính năng | Trạng thái |
|---|---|
| LM35, Flame, MQ-2 | **Có trong code** |
| LCD I²C | **Có trong code**; tự dò 0x27/0x3F |
| 3 LED, 2 buzzer | **Có trong code** |
| Servo + manual button | **Có trong code** |
| Serial monitoring | **Có trong code**, 115200 baud |
| Wi‑Fi | **Không có trong code** |
| MQTT | **Không có trong code** |
| Node-RED/dashboard/CSV logging | **Không có trong repository firmware** |
| Web/mobile | **Không có** |
| Automated/unit tests | **Không có** |

## Mâu thuẫn code–tài liệu

| Nội dung | Nguồn A | Nguồn B | Kết luận |
|---|---|---|---|
| Servo | Code dùng `ESP32Servo`, GPIO32 và button GPIO33 [SRC-023] | Final README nói “không dùng … servo” [SRC-025] | **CONFLICT:** implementation tĩnh có Servo; README sai hoặc lỗi thời; quyết định nhóm **UNKNOWN** |
| Tên sketch | File thực là `FireDetectionSingleFinal.ino` [SRC-023] | Hai README trỏ `FireDetectionFinal.ino` [SRC-024], [SRC-025] | **CONFLICT:** hướng dẫn mở file không khớp filesystem |
| Cloud | Plan/diagram có MQTT/Node-RED [SRC-002], [SRC-005], [SRC-007], [SRC-008] | Code không có network [SRC-023] | **FACT:** chưa triển khai trong firmware hiện tại; future scope **UNKNOWN** |
| Buzzer | Schematic cũ một buzzer [SRC-006] | Code hai buzzer GPIO27/15 [SRC-023] | **CONFLICT:** schematic lỗi thời |
| LED vàng/đỏ | Schematic thể hiện D26 vàng/D25 đỏ [SRC-006] | Code D25 vàng/D26 đỏ [SRC-023] | **CONFLICT:** cần đối chiếu dây thật; code khớp handover [SRC-004] |

## Rủi ro static analysis

- **P0/UNKNOWN:** GPIO18/19 có thể nhận mức DO gần 5 V nếu module cấp 5 V; code không thể bảo vệ phần cứng. Xem [06_ISSUES.md](06_ISSUES.md).
- **P1:** `updateDoor()` gọi hai lần mỗi loop; cần test debounce.
- **P1:** Không có hysteresis quanh 40/45°C; có thể rung state khi nhiệt độ nhiễu. Đây là **INFERENCE** cần log kiểm chứng.
- **P1:** Không có warm-up/fault handling cho MQ-2 và sensor disconnect.
- **P2:** Dùng Arduino `String` lặp trong loop cho LCD/Serial; rủi ro phân mảnh heap dài hạn là **INFERENCE**, cần soak test chứ không kết luận lỗi.
- **P2:** LCD driver giả định mapping PCF8574 cụ thể; địa chỉ đúng chưa đảm bảo mapping backpack đúng.
- `.gitignore` bỏ qua `*.csv`; dataset cần nơi quản lý/đóng gói khác để không bị bỏ sót. [SRC-026](../IOT102-G2-Fire-Detection-System/.gitignore)

## Build và test

- README hướng dẫn Arduino IDE, board `ESP32 Dev Module`, Verify/Upload và Serial 115200. [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md)
- **CONFLICT/build risk:** thư mục sketch `FireDetectionFinal/` không trùng tên file chính `FireDetectionSingleFinal.ino`; README trỏ file cũ `FireDetectionFinal.ino`. Cần Verify thực tế trước khi ghi hướng dẫn build.
- **UNKNOWN:** Arduino IDE, ESP32 core, `ESP32Servo` version, compile flags và library compatibility.
- **UNKNOWN:** Code đã compile/upload/chạy thành công hay chưa; repository không có `.elf/.bin`, CI, build log hoặc test log.
- Không chạy firmware hay script trong quá trình phân tích này.

## Nguồn tham khảo

- [SRC-023 — Firmware](../src/FireDetectionSingleFinal.ino)
- [SRC-024 — Repository README](../IOT102-G2-Fire-Detection-System/README.md)
- [SRC-025 — Final README](../IOT102-G2-Fire-Detection-System/Final/README.md)
- [SRC-026 — `.gitignore`](../IOT102-G2-Fire-Detection-System/.gitignore)
- [SRC-004 — Tài liệu bàn giao](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx)

## Thông tin chưa xác minh

Phê duyệt chính thức của firmware, khả năng build/upload/runtime, version thư viện, wiring thật, mức điện áp, địa chỉ/mapping LCD, calibration LM35, threshold/warm-up sensor và mọi kết quả test.
