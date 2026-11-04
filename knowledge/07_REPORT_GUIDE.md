# Hướng dẫn xây dựng báo cáo

## Mục đích và phạm vi

Tài liệu này chuyển yêu cầu môn học và template thành checklist viết báo cáo cho hệ thống cảnh báo cháy. Không cung cấp số liệu giả và không coi text mẫu là kết quả. Xem [yêu cầu](01_REQUIREMENTS.md), [kiến trúc](02_ARCHITECTURE.md), [tiến độ](05_PROGRESS.md) và [issues](06_ISSUES.md).

## Format bắt buộc/đề xuất

- **FACT:** Final Report PDF, IEEE, 5–8 trang, có AI Usage Declaration ở cuối. [SRC-001](../CF_IOT102_FA26.docx), mục 2.2, 6 và 12.
- **FACT:** Template dùng `IEEEtran`, tùy chọn `conference, onecolumn`, và cấu trúc Introduction → Methods and Materials → Results and Discussion → Conclusion → contribution → bibliography. [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>).
- **UNKNOWN:** Giảng viên có yêu cầu dùng chính xác file template này hay template mới trên LMS; cần xác nhận trước khi dàn trang cuối.

## Cấu trúc nội dung đề xuất

| Report Section | Available Context | Missing Evidence | Source ID |
|---|---|---|---|
| Title/Authors | Có tên đề tài và nhóm G2 | Lớp, MSSV, email, tên thành viên | [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx) |
| Abstract | Có problem, scope, thành phần và thuật toán; có mẫu diễn đạt | Kết quả đo thật và kết luận dựa trên số liệu | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Introduction | Có objective, scope local, limitations và course context | Citation học thuật cho motivation; scope được nhóm/giảng viên duyệt | [SRC-001](../CF_IOT102_FA26.docx), [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) |
| Related Work / Background | Có danh sách BibTeX mẫu và tài liệu kỹ thuật nội bộ | 6–10 bài trực tiếp về fire detection/multi-sensor/ESP32; full-text review; research gap/RQ | [SRC-001](../CF_IOT102_FA26.docx), [SRC-010](../references/IOT102_Final_Project_Report_Template/Bib_references.bib) |
| Methods — System Model | Có block diagram local trong handover và code input→process→output | Block Diagram cập nhật, bỏ cloud nếu scope local được chốt | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Methods — Hardware | Có BOM, GPIO code/handover và schematic cũ | Schematic đúng hai buzzer/LED pins/level shift; datasheet; power budget; ảnh mạch | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Methods — Algorithm | Có ngưỡng, priority state, buzzer timing, door persistence và debounce trong code | Flowchart cập nhật; quyết định về double `updateDoor()` và hysteresis | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-007](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Methods — Software | Có sketch 401 dòng, hàm, thư viện và README nạp firmware | ESP32 core/ESP32Servo versions; compile/upload log; README đúng tên/Servo | [SRC-023](../src/FireDetectionSingleFinal.ino), [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) |
| Experimental Setup | Có TC01–TC08 expected và hành vi code | Protocol an toàn, thiết bị tham chiếu, repetitions, sample size, metric definitions | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Results | Chỉ có expected behavior, chưa có actual result | Raw log/data, pass/fail, response time, false alarm/missed detection, ảnh/video/biểu đồ | [SRC-001](../CF_IOT102_FA26.docx), [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) |
| Discussion | Có limitations từ code: digital DO, ADC, không hysteresis/fault handling/network | Phân tích dựa trên kết quả thật; so sánh related work | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Conclusion/Future Work | Có ranh giới local prototype và danh sách nâng cấp | Kết luận phải chờ result; quyết định cloud/servo chính thức | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Author Contribution | Có mẫu bảng tổng 100% | Phân công và tỷ lệ thật | [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>) |
| AI Usage Declaration | Có mẫu và quy định bắt buộc | Khai báo đúng công cụ/mục đích cho từng report | [SRC-001](../CF_IOT102_FA26.docx) |
| Appendix/Repository | Có `.ino`, README và `.gitignore` | Schematic cuối, build instructions đúng, test evidence, dependency versions | [SRC-023](../src/FireDetectionSingleFinal.ino)–[SRC-026](../IOT102-G2-Fire-Detection-System/.gitignore) |

## Research Question và metrics

**UNKNOWN:** Chưa có RQ trong repository. Không tự gán RQ vào báo cáo. Có thể dùng các câu hỏi sau làm đề xuất thảo luận nội bộ, không coi là đã duyệt:

- **INFERENCE/đề xuất:** Hệ thống ba mức có phản hồi nhất quán và response time bao nhiêu dưới các stimulus đã kiểm soát?
- **INFERENCE/đề xuất:** Trung bình 10 mẫu LM35 nhưng không có hysteresis ảnh hưởng thế nào tới state chattering quanh 40°C/45°C? Khoảng trống xuất phát từ [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 139–150/278–297.
- **INFERENCE/đề xuất:** False alarm/missed detection của logic OR ba sensor trong test set được định nghĩa là bao nhiêu?
- **INFERENCE/đề xuất:** Cơ chế button debounce 50 ms hoạt động ổn định ra sao khi `updateDoor()` được gọi hai lần mỗi loop?

Metric chỉ được báo cáo khi có định nghĩa, thiết bị đo, số lần lặp, raw data và cách tính. Course yêu cầu quantitative evaluation phù hợp đề tài, không áp đặt cùng dataset cho mọi project. [SRC-001](../CF_IOT102_FA26.docx), mục 4 và 6.

## Test evidence tối thiểu

Từ test matrix của [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 9.2:

| TC | Scenario | Evidence nên lưu |
|---|---|---|
| TC01 | `T < 40°C`, không lửa/khí | Nhiệt độ/log + LED xanh + buzzer tắt |
| TC02 | Khoảng `42°C`, sensor số không kích hoạt | Nhiệt độ + LED vàng + timing buzzer 2 |
| TC03 | `T ≥ 45°C` | Nhiệt độ + LED đỏ + hai buzzer + Servo 90° |
| TC04 | T thấp, Flame active LOW | Digital log + DANGER/door |
| TC05 | T thấp, MQ-2 active LOW | Digital log + DANGER/door |
| TC06 | DANGER và nhấn nút đóng | Video/log chứng minh cửa vẫn mở |
| TC07 | Hết DANGER, chưa nhấn nút | Alarm đổi state nhưng cửa giữ mở |
| TC08 | Không DANGER, nhấn nút | Video nhiều lần + debounce/toggle 0°↔90° |

Không dùng lửa thật trong không gian kín hoặc tạo khói độc chỉ để lấy minh chứng; tuân thủ hướng dẫn phòng thí nghiệm. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 9.3.

## Cách sử dụng nguồn hiện có

- [SRC-001](../CF_IOT102_FA26.docx): yêu cầu/rubric, không phải citation khoa học cho sensor.
- [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx): mô tả nội bộ để dựng Methods/checklist; phải đối chiếu code và mạch.
- [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>): chỉ lấy cấu trúc/LaTeX; thay placeholder và ví dụ tưới nước.
- [SRC-010](../references/IOT102_Final_Project_Report_Template/Bib_references.bib): bibliography mẫu; chỉ giữ mục đã đọc và thực sự trích dẫn. Các mục hiện có không trực tiếp tạo thành Literature Review cảnh báo cháy.
- [SRC-011]–[SRC-016]: tutorial lập trình nền tảng; không phải evidence implementation.
- [SRC-018](../references/IOT102_Final_Project_Report_Template/Block_diagram.png), [SRC-019](../references/IOT102_Final_Project_Report_Template/Circuit_Schematic.jpg): hình tưới nước, phải loại khỏi report dự án.
- [SRC-023](../src/FireDetectionSingleFinal.ino): nguồn primary cho Methods/Software và thuật toán; không phải nguồn học thuật hay evidence runtime.

## Phân loại nguồn nghiên cứu hiện có

| Nhóm | Nguồn | Có thể dùng thế nào |
|---|---|---|
| Candidate academic bibliography | [SRC-010](../references/IOT102_Final_Project_Report_Template/Bib_references.bib) có 8 mục conference/journal | Chỉ là metadata; phải đọc full text và kiểm tra relevance. Mục environmental monitoring có thể cung cấp background IoT; các mục traffic sign, waste, MAC, speech emotion không trực tiếp hỗ trợ fire detection |
| Course/internal documents | [SRC-001](../CF_IOT102_FA26.docx), [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) | Yêu cầu, design rationale và nội dung nội bộ; không thay citation khoa học/datasheet |
| Technical implementation | [SRC-023](../src/FireDetectionSingleFinal.ino)–[SRC-026](../IOT102-G2-Fire-Detection-System/.gitignore) | Primary evidence cho code/config; không chứng minh hiệu năng |
| Tutorials | [SRC-011]–[SRC-016] | Giải thích Arduino, `millis()`, debounce; không phải related work của đề tài |
| Template/examples | [SRC-009], [SRC-012], [SRC-017]–[SRC-021] | Format/minh họa; không dùng làm evidence hệ thống cháy |

### Chủ đề cần nghiên cứu thêm khi được yêu cầu

1. Multi-sensor fire/smoke detection và fusion rule cho temperature–flame–gas.
2. Đặc tính, calibration, cross-sensitivity và warm-up của MQ-2; giới hạn Flame Sensor DO.
3. ESP32 ADC calibration/uncertainty khi đọc LM35.
4. Threshold selection, hysteresis/filtering và đánh giá false alarm/missed detection.
5. Fail-safe behavior, sensor fault detection và tiêu chuẩn an toàn liên quan prototype.
6. Thiết kế nguồn/level shifting 5 V↔3,3 V và power integrity cho Servo/MQ-2.

Chưa thực hiện Internet search trong lần cập nhật này; không thêm citation khoa học mới.

## Những claim không được viết nếu chưa có bằng chứng

- “Hệ thống hoạt động ổn định/chính xác/real-time”.
- Accuracy, precision, response time, false-alarm rate hoặc uptime cụ thể.
- “Cloud monitoring”, MQTT, Node-RED, Blynk hoặc remote control đã triển khai.
- MQ-2 đo được ppm hoặc Flame Sensor đo cường độ định lượng khi chỉ dùng DO.
- Hệ thống phù hợp tiêu chuẩn PCCC hoặc có thể bảo vệ công trình thật.
- Tất cả test “Passed” khi bảng actual còn trống.

Nguồn cảnh báo: [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 1.3, 9, 10 và 11.2.

## AI Usage Declaration và AI Audit Log

- Declaration phải nằm cuối **mỗi** report OPA1/OPA2/Final, kể cả không dùng AI. [SRC-001](../CF_IOT102_FA26.docx), mục 12.
- Audit Log là file riêng, khoảng 3–5 engineering decisions tiêu biểu; mỗi entry gồm AI output → verification/validation → student decision → evidence/test → final result. [SRC-001](../CF_IOT102_FA26.docx), mục 13.
- Không biến toàn bộ chat history thành audit log; tập trung quyết định kỹ thuật và cách nhóm kiểm chứng.
- Thiếu Audit Log làm tiêu chí AI Verification/Validation 20 điểm bị 0. [SRC-001](../CF_IOT102_FA26.docx), rubric mục 7.2.

## Checklist trước khi nộp

- [ ] Report 5–8 trang, IEEE, PDF và đúng template LMS.
- [ ] Mọi hình/table có caption, source hoặc “authors' own work”.
- [ ] Diagram khớp source/mạch thật và scope local/cloud đã chốt.
- [ ] Results chỉ chứa dữ liệu thật, có raw evidence truy ngược.
- [ ] Discussion nêu limitations và prototype disclaimer.
- [ ] Reference nào cũng được trích dẫn trong bài và đã đọc.
- [ ] Author contribution là dữ liệu thật, tổng 100%.
- [ ] AI Usage Declaration ở cuối report.
- [ ] AI Audit Log nộp riêng đúng vị trí LMS.
- [ ] Source code/schematic/README trong repository Final.

## Nguồn tham khảo

- [SRC-001 — Yêu cầu và rubric Fall 2026](../CF_IOT102_FA26.docx)
- [SRC-004 — Tài liệu bàn giao](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx)
- [SRC-009 — Mẫu báo cáo LaTeX](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>)
- [SRC-010 — BibTeX mẫu](../references/IOT102_Final_Project_Report_Template/Bib_references.bib)
- [SRC-023 — Firmware candidate](../src/FireDetectionSingleFinal.ino)

## Thông tin chưa xác minh

RQ, literature review, experimental protocol, actual results, author contribution, template LMS cuối và toàn bộ số liệu định lượng.
