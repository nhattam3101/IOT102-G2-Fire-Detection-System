# Bối cảnh dự án

## Mục đích và phạm vi

Tài liệu này cung cấp context tối thiểu về đề tài, mục tiêu, phạm vi và nguyên lý hoạt động. Nó phân biệt thiết kế được ghi trong tài liệu với trạng thái đã được kiểm chứng. Xem thêm [kiến trúc](02_ARCHITECTURE.md), [source code](03_SOURCE_CODE.md), [tiến độ](05_PROGRESS.md) và [chỉ mục nguồn](08_SOURCE_INDEX.md).

## Tóm tắt điều hành

| Thuộc tính | Nội dung | Trạng thái và nguồn |
|---|---|---|
| Môn/học kỳ | IOT102, Fall 2026 | **FACT:** [SRC-001](../CF_IOT102_FA26.docx), mục tiêu và lộ trình |
| Nhóm | G2 | **FACT:** [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), đầu tài liệu |
| Tên đề tài | *IoT-Based Fire Detection and Warning System* | **FACT:** [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), phần mở đầu; [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), trang đầu |
| Controller | ESP32 Dev Module/DevKit | **FACT trong code/README:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 2–4/196–263; [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) |
| Firmware candidate | `FireDetectionSingleFinal.ino`, HEAD `db664d5` ngày 26/10/2026 | **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino); **UNKNOWN:** chưa có release tag/phê duyệt chính thức |
| Phạm vi được code hóa | Prototype cảnh báo tại chỗ; sensor + LCD/LED/2 buzzer + Servo/button; không Wi‑Fi/MQTT/Node-RED | **FACT trong code:** [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Mức hoàn thiện thực tế | Có firmware và hướng dẫn nạp; chưa đủ bằng chứng xác nhận build, wiring và test | **UNKNOWN:** không có build/upload log, ảnh mạch thật, dataset hoặc test result |

## Mục tiêu

**FACT (đã hiện diện trong code):** ESP32 đọc LM35, Flame DO và MQ-2 DO; phân loại `SAFE/WARNING/DANGER`; điều khiển LCD, ba LED, hai buzzer, Servo và nút nhấn. [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 6–55, 137–192 và 265–400. Điều này xác nhận implementation tĩnh, không xác nhận phần cứng đã chạy.

**FACT (mục tiêu môn học):** Final Project cần có architecture hợp lý, prototype/demo, báo cáo IEEE, bằng chứng nghiên cứu/thực nghiệm định lượng, source repository, presentation/Q&A và hồ sơ sử dụng AI. Không bắt buộc mọi đề tài đồng thời có đủ wireless, sensor, visualization và actuator nếu đặc thù đề tài không phù hợp. [SRC-001](../CF_IOT102_FA26.docx), mục 4, 6 và 7.

## Phạm vi hiện tại

### Trong phạm vi gần nhất

- LM35 được đọc bằng `analogReadMilliVolts()` trung bình 10 mẫu; Flame/MQ-2 là digital active LOW. **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 34–35 và 139–150/269–276.
- Ngưỡng `WARNING=40°C`, `DANGER=45°C`; DANGER cũng kích hoạt bởi Flame/MQ-2. **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 31–35 và 278–297.
- Đầu ra cục bộ: LCD I²C, LED xanh/vàng/đỏ, hai buzzer, Servo. **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 13–27 và 153–192/302–313/350–400.
- Nút GPIO33 dùng `INPUT_PULLUP`, debounce 50 ms và toggle cửa khi không DANGER. **FACT:** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 43–48/203/367–400.

### Ngoài phạm vi gần nhất

- Web Dashboard, MQTT, Node-RED, cloud logging và remote control. **FACT (tài liệu bàn giao loại khỏi phạm vi):** [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 1.3 và 10.2.
- Thiết bị PCCC thương mại/chứng nhận. Prototype không được dùng làm hệ thống bảo vệ cháy thực tế. **FACT:** [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), cảnh báo mục 10.

## Thành phần và chức năng chính

| Thành phần | Chức năng được mô tả | Mức xác minh |
|---|---|---|
| ESP32 DevKit | Đọc input, quyết định trạng thái, điều khiển output | **FACT trong code**, runtime **UNKNOWN** [SRC-023](../src/FireDetectionSingleFinal.ino) |
| LM35 | ADC 12-bit, attenuation `ADC_0db`, trung bình 10 phép đo mV, chia 10 để ra °C | **FACT trong code**; hiệu chuẩn **UNKNOWN** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 139–150/221–223 |
| Flame Sensor | DO active LOW trên GPIO19 | **FACT trong code**; ngưỡng module **UNKNOWN** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 9/34/269–272 |
| MQ-2 | DO active LOW trên GPIO18 | **FACT trong code**; warm-up/threshold **UNKNOWN** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 10/35/273–274 |
| LCD/LED/buzzer | LCD tự dò 0x27 rồi 0x3F; ba LED và hai buzzer theo state | **FACT trong code**, test **UNKNOWN** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 53–135/155–192/225–251 |
| Servo SG90 | 50 Hz, pulse 500–2400 µs, góc 0°/90°; DANGER ép mở | **FACT trong code**, test **UNKNOWN** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 37–40/253–259/350–400 |

## Nguyên lý hoạt động tổng quát

1. ESP32 đọc LM35, Flame Sensor và MQ-2. [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 269–276.
2. Nếu có lửa **hoặc** khí/khói **hoặc** `T ≥ 45°C`, chọn `DANGER`: LED đỏ, hai buzzer liên tục, Servo mở 90°. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), bảng mục 6.1.
3. Nếu không `DANGER` nhưng `T ≥ 40°C`, chọn `WARNING`: LED vàng, buzzer 2 kêu ngắt quãng 500 ms. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 6.1 và 8.4.
4. Còn lại chọn `SAFE`: LED xanh, hai buzzer tắt. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 6.1.
5. Trạng thái cảnh báo được tính lại mỗi vòng lặp, không latch `DANGER`; riêng cửa vẫn mở sau khi hết nguy hiểm và cần nút nhấn để đóng. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 6.2 và 7.2.

## Thông tin đã xác nhận và chưa xác nhận

### Đã xác nhận ở mức repository

- Có course plan, project plan, tài liệu bàn giao, diagram, template/tutorial và repository firmware. [SRC-001]–[SRC-026], xem [08_SOURCE_INDEX.md](08_SOURCE_INDEX.md).
- Tài liệu bàn giao mới nhất ghi ngày 01/11/2026 và nói rõ không thay source code, ảnh mạch hay kết quả test thật. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), phần hướng dẫn.

### Mâu thuẫn

- **CONFLICT:** Kế hoạch và diagram cũ có Wi‑Fi/MQTT/Node-RED/dashboard/CSV, trong khi tài liệu bàn giao loại các phần này khỏi phạm vi. [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), mục 1; [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png); [SRC-007](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png); [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 1.3.
- **CONFLICT:** Diagram/schematic cũ mô tả một buzzer; tài liệu bàn giao mô tả hai buzzer. [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png); [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>); [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), bảng GPIO.
- **CONFLICT:** [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) nói firmware không dùng Servo, trong khi [SRC-023](../src/FireDetectionSingleFinal.ino) include `ESP32Servo`, attach GPIO32 và xử lý GPIO33. Code xác nhận Servo được triển khai tĩnh nhưng chưa chứng minh phần cứng hoạt động.

### Chưa xác minh

- **UNKNOWN:** [SRC-023] có phải bản được nhóm chính thức phê duyệt hay không; khả năng compile/upload và phiên bản Arduino core/ESP32Servo.
- **UNKNOWN:** Pin mapping và wiring thật có khớp bảng hay không.
- **UNKNOWN:** Nguồn cấp, mức logic, điện trở, LCD I²C address, đặc tính buzzer và nguồn Servo.
- **UNKNOWN:** Bất kỳ test case, metric, accuracy, response time, false alarm, uptime hay dataset nào.
- **UNKNOWN:** Phân công thành viên, deadline theo ngày lịch và repository GitHub/GitLab.

## Nguồn tham khảo

- [SRC-001 — Course plan Fall 2026](../CF_IOT102_FA26.docx)
- [SRC-002 — Project plan](../docs/project/IOT102_Fire_Detection_Project_Plan.docx)
- [SRC-004 — Tài liệu bàn giao](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx)
- [SRC-005–SRC-008 — Diagram](08_SOURCE_INDEX.md)
- [SRC-023 — Firmware candidate](../src/FireDetectionSingleFinal.ino)

## Thông tin chưa xác minh

Các mục `UNKNOWN` ở trên là điều kiện cần thu thập trước khi khẳng định hệ thống đã hoàn thành.
