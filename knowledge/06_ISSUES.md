# Vấn đề, rủi ro và quyết định cần chốt

## Mục đích và phạm vi

Tài liệu này tập trung các mâu thuẫn và rủi ro được phát hiện khi đối chiếu nguồn. Ưu tiên: `P0` cần xử lý trước khi cấp nguồn/demo; `P1` cần xử lý trước OPA/Final; `P2` cần làm rõ để tăng chất lượng. Xem [kiến trúc](02_ARCHITECTURE.md), [tiến độ](05_PROGRESS.md) và [yêu cầu](01_REQUIREMENTS.md).

## Danh sách issue

| ID | Ưu tiên | Loại | Vấn đề / bằng chứng | Hành động/tiêu chí đóng |
|---|---|---|---|---|
| ISS-01 | **P0** | An toàn điện | Schematic vẽ sensor dùng rail `+5V` và DO về GPIO18/19; divider chỉ là ghi chú, không thể hiện rõ trên dây. ESP32 dùng logic 3,3 V. [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>); cảnh báo [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 5.1 | Đo DO max; đọc datasheet/module; thêm divider/level shifter nếu cần; cập nhật schematic trước cấp nguồn |
| ISS-02 | **P0** | Firmware/evidence | Đã có `.ino` nhưng không có xác nhận release, compile/upload log hoặc version Arduino core/ESP32Servo. [SRC-023](../src/FireDetectionSingleFinal.ino) | Nhóm xác nhận snapshot; pin dependency versions; lưu build/upload log |
| ISS-03 | **P0** | Kiểm thử | TC01–TC08 để trống; không có kết quả, log, ảnh mạch hay video. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 9.2 | Test an toàn, ghi actual/pass-fail, timestamp, evidence; không tuyên bố “works/accurate” trước khi hoàn tất |
| ISS-04 | **P1** | Scope | Kế hoạch/diagram có MQTT, Node-RED, dashboard, CSV; handover nói local-only. [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png), [SRC-007](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png), [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) | Nhóm/giảng viên chốt scope; đồng bộ report/diagram/code; cloud chưa có bằng chứng chỉ ghi future work |
| ISS-05 | **P1** | Schematic | Schematic/block cũ có một buzzer; handover có hai buzzer GPIO27/15. [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png), [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>), [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) | Đối chiếu code/mạch; cập nhật block/schematic/BOM |
| ISS-06 | **P1** | GPIO | Schematic thể hiện D23→green, D26→yellow, D25→red; handover ghi D23 green, D25 yellow, D26 red. [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>), [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), bảng GPIO | Kiểm tra constants và dây thật; sửa nguồn sai; test từng LED |
| ISS-07 | **P1** | Nguồn/công suất | Nguồn Servo, MQ-2, LCD và buzzer chưa xác nhận; Servo không được cấp từ GPIO, cần GND chung. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 5.1–5.2 | Lập power budget, chọn nguồn, xác nhận GND, driver/flyback theo loại tải, đo sụt áp/reset |
| ISS-08 | **P1** | Course version | Summer yêu cầu đủ 5 kỹ thuật, dataset/video bắt buộc; Fall cho phép theo đề tài và chuyển dataset/video optional, thêm AI deliverables. [SRC-003](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>), [SRC-001](../CF_IOT102_FA26.docx) | Dùng Fall 2026; xác nhận LMS/giảng viên nếu có yêu cầu lớp riêng |
| ISS-09 | **P1** | Submission | Course plan vừa nêu `AI_Audit_Log/`, vừa ghi Audit Log trong `Documents/`. [SRC-001](../CF_IOT102_FA26.docx), mục 6 và 13.4 | Hỏi giảng viên/LMS; lưu file riêng trong cả package nếu được phép, tránh thiếu nộp |
| ISS-10 | **P1** | Research | Chưa có Mini-LR, 6–10 paper, research gap/RQ, protocol/metrics/raw data. Course yêu cầu research/quantitative evidence. [SRC-001](../CF_IOT102_FA26.docx), mục 2.2, 5–6 | Chốt RQ, chọn metric, phương pháp test, nguồn học thuật; thu raw data trước khi viết Results |
| ISS-11 | **P2** | Sensor validity | Flame/MQ-2 dùng DO chỉ cho trạng thái threshold, không phải cường độ/nồng độ; threshold module chưa ghi. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 2.1 và 10.1 | Ghi đúng giới hạn; lưu cách chỉnh threshold; không báo ppm/accuracy nếu không có calibration |
| ISS-12 | **P2** | LM35/ADC | Công thức gần đúng 10 mV/°C nhưng accuracy phụ thuộc nguồn, ADC và calibration. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 2.2/10.1 | Ghi conversion code, ADC reference/attenuation, so sánh thiết bị tham chiếu, uncertainty |
| ISS-13 | **P2** | Alarm semantics | Alarm state không latch; cửa lại giữ mở. Người dùng có thể hiểu nhầm “reset”. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 6.2–7.2 | Dùng đúng tên `Manual Door Control Button`; mô tả persistence rõ trong flowchart/UI/report |
| ISS-14 | **P2** | Template contamination | Report template và hình trong thư mục template là hệ tưới nước/Arduino Uno, không phải dự án cháy. [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>), [SRC-018](../references/IOT102_Final_Project_Report_Template/Block_diagram.png), [SRC-019](../references/IOT102_Final_Project_Report_Template/Circuit_Schematic.jpg) | Chỉ tái dùng cấu trúc; thay toàn bộ placeholder, hình và nội dung mẫu |
| ISS-15 | **P2** | Safety claims | Prototype chưa được kiểm định PCCC; tạo lửa/khói độc để test có rủi ro. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 9.3 và 10 | Test theo hướng dẫn lab, không dùng làm bảo vệ thực; thêm disclaimer trong report/demo |
| ISS-16 | **P1** | Code/documentation | Final README nói không dùng Servo và hai README trỏ sai tên sketch; code có Servo/button và tên `FireDetectionSingleFinal.ino`. [SRC-023](../src/FireDetectionSingleFinal.ino), [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) | Nhóm chốt scope; cập nhật README ở workflow riêng; không dùng hướng dẫn sai trong report |
| ISS-17 | **P1** | Firmware | `updateDoor(danger)` được gọi hai lần mỗi vòng lặp. [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 283/345 | Code review và test button/debounce; chỉ sửa firmware khi nhóm yêu cầu |
| ISS-18 | **P1** | Firmware/experiment | Không có hysteresis, MQ-2 warm-up/fault state hoặc sensor-disconnect handling trong code. [SRC-023](../src/FireDetectionSingleFinal.ino) | Thiết kế experiment về state chattering, startup và sensor faults; ghi limitation nếu giữ thiết kế |
| ISS-19 | **P2** | Data management | `.gitignore` bỏ qua `*.csv`, trong khi course cần experimental evidence và kế hoạch cũ có CSV logging. [SRC-026](../IOT102-G2-Fire-Detection-System/.gitignore), [SRC-001](../CF_IOT102_FA26.docx) | Chọn kho dữ liệu/package nộp rõ ràng; tránh bỏ sót raw data khi commit |
| ISS-20 | **P1** | Build structure | Folder sketch là `FireDetectionFinal/` nhưng file `.ino` chính là `FireDetectionSingleFinal.ino`; hai README lại yêu cầu file `FireDetectionFinal.ino` đã không còn. [SRC-023](../src/FireDetectionSingleFinal.ino), [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) | Verify bằng Arduino IDE/toolchain; thống nhất folder/file theo convention trong workflow sửa source được phê duyệt; lưu build log |

## Các quyết định nhóm cần thống nhất

- [ ] Scope final: local-only hay bổ sung MQTT/dashboard?
- [ ] Một hay hai buzzer; loại active/passive; cần driver nào?
- [ ] Pin map cuối và pin nào đang đấu thực tế?
- [ ] Cách bảo vệ GPIO18/19 khỏi mức 5 V?
- [ ] Nguồn riêng/chung cho Servo/MQ-2/LCD/buzzer và power budget?
- [ ] Ý nghĩa cửa mở trong mô hình và hành vi sau `DANGER`?
- [ ] Research Question và metrics nào đo được an toàn?
- [ ] Cấu trúc nộp AI Audit Log theo LMS?

## Rủi ro firmware cần review khi có code

Static analysis [SRC-023](../src/FireDetectionSingleFinal.ino) cho kết quả:

- ADC dùng 12-bit, `ADC_0db` và `analogReadMilliVolts()`; độ chính xác/calibration vẫn **UNKNOWN**.
- Active LOW được triển khai cho Flame/MQ-2; tương thích wiring/module thật **UNKNOWN**.
- Buzzer 500 ms dùng `millis()` non-blocking; vòng lặp vẫn có delay đọc LM35 và `delay(50)`.
- Debounce 50 ms với `INPUT_PULLUP` và nhấn LOW; `updateDoor()` bị gọi hai lần nên cần test timing thực.
- Không có hysteresis/filtering state quanh 40/45°C ngoài trung bình 10 mẫu LM35.
- Không có sensor fault/disconnect handling; trạng thái fail-safe thực tế **UNKNOWN**.
- `millis()` overflow và state transition có được xử lý không? **UNKNOWN**.

## Nguồn tham khảo

- [SRC-001 — Course plan](../CF_IOT102_FA26.docx)
- [SRC-003 — Yêu cầu Summer cũ](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>)
- [SRC-004 — Tài liệu bàn giao](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx)
- [SRC-005–SRC-008 — Diagram](08_SOURCE_INDEX.md)
- [SRC-023–SRC-026 — Firmware repository](08_SOURCE_INDEX.md)

## Thông tin chưa xác minh

Owner, due date và trạng thái xử lý từng issue chưa có. Không đóng issue chỉ dựa trên trao đổi miệng; cần artefact/test evidence.
