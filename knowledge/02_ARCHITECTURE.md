# Kiến trúc hệ thống

## Mục đích và phạm vi

Tài liệu này hợp nhất Block Diagram, Flowchart, Circuit Schematic và mô tả GPIO. “Kiến trúc hiện tại” dựa trên tài liệu bàn giao gần nhất, không phải xác nhận mạch thật. Xem [vấn đề/rủi ro](06_ISSUES.md), [source code](03_SOURCE_CODE.md) và [bối cảnh](00_PROJECT_CONTEXT.md).

## Phiên bản kiến trúc

| Phiên bản | Nội dung | Trạng thái |
|---|---|---|
| Thiết kế ban đầu | Sensor → ESP32 → local output + Wi‑Fi/MQTT → broker → Node-RED → dashboard/CSV | **FACT kế hoạch/diagram**, chưa xác minh triển khai: [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), mục 1; [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png); [SRC-008](../docs/design/source/BlockDiagram.drawio) |
| Firmware tại HEAD `db664d5` | Sensor/button → ESP32 → LCD/LED/2 buzzer/Servo; Serial; không network | **FACT trong code:** [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Tài liệu bàn giao 01/11/2026 | Giải thích cùng kiến trúc local, có Servo/button | **FACT theo tài liệu:** [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 1.3–8 |
| Mạch/runtime đã xác minh | Chưa có ảnh mạch, build/upload log hoặc test result | **UNKNOWN** |

## Block Diagram hiện tại

```text
LM35 (analog) ---------+
Flame DO (active LOW) -+                 +--> LED xanh/vàng/đỏ
MQ-2 DO (active LOW) --+--> ESP32 DevKit +--> LCD 16x2 I²C
Nút nhấn --------------+                 +--> Buzzer 1 + Buzzer 2
                                          +--> Servo SG90 (cửa mô hình)
```

**FACT:** Cấu trúc trên khớp code và hình nhúng “Sơ đồ khối hệ thống”. [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 6–27/153–192/350–400; [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), Hình 1/mục 4.

## GPIO theo tài liệu bàn giao

| Thiết bị | GPIO | Chế độ / chức năng | Trạng thái |
|---|---:|---|---|
| LM35 Vout | 34 | Analog input, 12-bit, `ADC_0db` | **FACT trong code**, dòng 11/139–150/221–223 |
| Flame Sensor DO | 19 | Digital input, active LOW | **FACT trong code**, dòng 9/34/270–272 |
| MQ-2 DO | 18 | Digital input, active LOW | **FACT trong code**, dòng 10/35/273–274 |
| LED xanh | 23 | SAFE | **FACT trong code**, dòng 17/184–191 |
| LED vàng | 25 | WARNING | **FACT trong code**, dòng 18/170–183 |
| LED đỏ | 26 | DANGER | **FACT trong code**, dòng 19/162–169 |
| Buzzer 1 | 27 | Liên tục khi DANGER | **FACT trong code**, dòng 14/167/175/189 |
| Buzzer 2 | 15 | 500 ms ON/OFF khi WARNING; liên tục khi DANGER | **FACT trong code**, dòng 15/50–51/167–182 |
| Servo SG90 | 32 | 50 Hz; 0° đóng, 90° mở | **FACT trong code**, dòng 26/37–40/253–259 |
| Nút nhấn | 33 | `INPUT_PULLUP`; toggle khi không DANGER | **FACT trong code**, dòng 27/43–48/203/367–400 |
| LCD SDA | 21 | I²C data | **FACT trong code**, dòng 22/225–227 |
| LCD SCL | 22 | I²C clock | **FACT trong code**, dòng 23/225–227 |

Nguồn code cho toàn bảng: [SRC-023](../src/FireDetectionSingleFinal.ino). Bảng khớp tài liệu bàn giao [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 5; **UNKNOWN:** chưa đối chiếu wiring thật.

## Flowchart và luật trạng thái

```text
Đọc sensor
  ├─ flame_detected OR smoke/gas_detected OR T >= 45°C
  │    └─ DANGER: LED đỏ, buzzer 1+2 liên tục, cửa mở 90°
  └─ không DANGER
       ├─ T >= 40°C
       │    └─ WARNING: LED vàng, buzzer 2 ngắt quãng 500 ms
       └─ SAFE: LED xanh, cả hai buzzer tắt

Nếu không DANGER và nút được debounce hợp lệ:
  đảo cửa 0° <-> 90°
```

**FACT trong code:** ưu tiên `DANGER → WARNING → SAFE`; alarm không latch, nhưng biến `doorOpen` giữ cửa mở sau `DANGER` cho tới khi nhấn nút lúc không nguy hiểm. [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 278–300/350–400. Điều này khớp [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 6–8.

## Luồng dữ liệu

| Bước | Luồng | Ghi chú |
|---|---|---|
| 1 | Môi trường → sensor | LM35 analog; Flame/MQ-2 digital threshold |
| 2 | Sensor → ESP32 | ADC GPIO34; digital GPIO19/18 |
| 3 | ESP32 → state | So sánh 40/45°C và cờ active LOW |
| 4 | State → output | LED, buzzer, LCD, Servo |
| 5 | Nút → cửa | Chỉ cho phép toggle nếu không DANGER |

Nguồn: [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 4.1, 6 và 7.

## MQTT/Node-RED

- **FACT (thiết kế cũ):** Project plan và diagram có Wi‑Fi/MQTT, MQTT Broker, Node-RED, Web Dashboard và CSV logging. [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), mục 1 và bước 6–8; [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png); [SRC-007](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png); [SRC-008](../docs/design/source/BlockDiagram.drawio).
- **FACT (scope gần nhất):** Tài liệu bàn giao nói Web Dashboard không thuộc phạm vi và khả năng Wi‑Fi của ESP32 không chứng minh nhóm đã truyền Internet; MQTT/Node-RED/Blynk chỉ là future work nếu chưa tích hợp. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 1.3 và 10.2.
- **FACT (code):** Firmware không include hay gọi Wi‑Fi/MQTT; không có Node-RED flow trong repository. [SRC-023](../src/FireDetectionSingleFinal.ino), toàn file.
- **UNKNOWN:** Không có broker URL, topic, credential, Node-RED flow, firmware networking hoặc ảnh dashboard. Không ghi thông tin giả định vào report.

## Khác biệt giữa thiết kế và hiện trạng mô tả

| Hạng mục | Nguồn cũ | Nguồn gần nhất | Kết luận |
|---|---|---|---|
| Cloud | MQTT/Node-RED/dashboard/CSV | Không có dashboard/cloud | **CONFLICT:** report theo scope gần nhất trừ khi có bằng chứng mới |
| Buzzer | Một buzzer trong block/schematic | Hai buzzer, GPIO27 và GPIO15 | **CONFLICT:** schematic cần cập nhật/xác minh |
| Nút nhấn | Không có trong block diagram cũ | GPIO33, manual door control | **CONFLICT:** block diagram cũ thiếu input |
| LED pin | Schematic hình thể hiện D23→green, D26→yellow, D25→red | Bàn giao: D23 green, D25 yellow, D26 red | **CONFLICT:** cần đối chiếu dây/code [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>), [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) |
| Flowchart | Mỗi nhánh gửi MQTT/dashboard | Local outputs, không cloud | **CONFLICT:** flowchart cũ không khớp scope |
| Servo | README Final nói “không dùng servo” | Code include `ESP32Servo`, attach GPIO32 và điều khiển cửa | **CONFLICT:** code và tài liệu bàn giao có Servo; README cần chỉnh/giải trình [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md), [SRC-023](../src/FireDetectionSingleFinal.ino) |

## Chi tiết implementation ảnh hưởng kiến trúc

- LCD không dùng `LiquidCrystal_I2C`; code tự phát lệnh 4-bit qua `Wire`, dò `0x27` rồi `0x3F`, I²C 100 kHz. **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 53–135/225–251.
- Nhiệt độ là trung bình 10 lần `analogReadMilliVolts()`, mỗi lần cách 5 ms; quy đổi `mV/10`. **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 139–150.
- Buzzer WARNING dùng `millis()` nên không block 500 ms; vòng lặp vẫn có khoảng trễ tối thiểu khoảng 100 ms từ 10×5 ms và `delay(50)`, chưa tính I²C/Serial. **FACT về code, INFERENCE về chu kỳ:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 142–145/177–182/347.
- `updateDoor(danger)` được gọi hai lần trong mỗi `loop()` (trước xác định chuỗi status và sau Serial). **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 283 và 345. **INFERENCE:** lời gọi thứ hai dư thừa và cần review ảnh hưởng debounce; chưa có test chứng minh lỗi.

## Circuit Schematic và an toàn điện

- **FACT:** Schematic cũ cấp rail `+5V` cho Servo, LM35, MQ-2 và Flame Sensor; tín hiệu DO được vẽ nối về GPIO18/19; chỉ có ghi chú công thức chia áp bên cạnh, không thể hiện rõ divider trên đường tín hiệu. [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>).
- **FACT:** Tài liệu bàn giao cảnh báo GPIO ESP32 dùng logic 3,3 V; nếu module cấp 5 V cho DO gần 5 V thì không được nối trực tiếp, phải đo/kiểm tra và dùng divider/level shifting phù hợp. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 5.1.
- **FACT:** Servo không được lấy nguồn từ GPIO; các thiết bị giao tiếp phải chung GND. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 5.1.
- **UNKNOWN:** Giá trị điện trở LED/divider, nguồn Servo/MQ-2/LCD, dòng buzzer, transistor/flyback protection và địa chỉ LCD 0x27/0x3F.

## Nguồn tham khảo

- [SRC-004 — Tài liệu bàn giao](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx)
- [SRC-005 — Block Diagram cũ](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png)
- [SRC-006 — Circuit Schematic cũ](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>)
- [SRC-007 — Flowchart cũ](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png)
- [SRC-008 — draw.io editable](../docs/design/source/BlockDiagram.drawio)
- [SRC-023 — Firmware candidate](../src/FireDetectionSingleFinal.ino)
- [SRC-025 — Final README](../IOT102-G2-Fire-Detection-System/Final/README.md)

## Thông tin chưa xác minh

Mọi GPIO, mức điện áp, nguồn, ngưỡng sensor và output behavior cần đối chiếu đồng thời với `.ino` cuối, schematic đã sửa và mạch thật.
