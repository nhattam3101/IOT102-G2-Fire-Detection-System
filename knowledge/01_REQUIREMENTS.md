# Yêu cầu môn học và deliverables

## Mục đích và phạm vi

Tài liệu này tổng hợp yêu cầu IOT102 Fall 2026, các milestone và checklist nộp bài. Nguồn Summer 2026 chỉ dùng để nhận diện thay đổi lịch sử. Liên quan: [kế hoạch dự án](04_PROJECT_PLAN.md), [tiến độ](05_PROGRESS.md), [hướng dẫn báo cáo](07_REPORT_GUIDE.md).

## Nguyên tắc ưu tiên nguồn

- **FACT:** [SRC-001](../CF_IOT102_FA26.docx) là kế hoạch **Fall 2026**, nên được ưu tiên cho học kỳ hiện tại.
- [SRC-003](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>) là yêu cầu **Summer 2026** và chỉ là nguồn lịch sử.
- **UNKNOWN:** Repository không có syllabus/LMS export hoặc ngày lịch cụ thể; cần đối chiếu LMS/giảng viên trước khi nộp.

## Yêu cầu kỹ thuật

**FACT:** Fall 2026 cho phép nhóm chọn các yêu cầu phù hợp đặc thù đề tài; không bắt buộc mọi project đồng thời có wireless, sensor, data processing, visualization và actuator. Điều bắt buộc là architecture hợp lý và research/quantitative evaluation phù hợp. Web/mobile là bonus. [SRC-001](../CF_IOT102_FA26.docx), mục 4.

Các nhóm khả năng kỹ thuật được course plan nêu:

1. Wireless: Wi‑Fi/Bluetooth/LoRa/MAVLink.
2. Sensor acquisition.
3. Data processing.
4. Data visualization.
5. Actuator control.
6. Web/mobile app — bonus.

**CONFLICT:** Summer 2026 yêu cầu “đầy đủ” 5 mục đầu; project plan cũng dẫn lại yêu cầu này. Fall 2026 đã nới theo đặc thù đề tài. [SRC-003](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>), mục II; [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), mục 4; [SRC-001](../CF_IOT102_FA26.docx), mục 4.

## Đối chiếu yêu cầu với firmware hiện có

| Nhóm yêu cầu | Bằng chứng hiện có | Đánh giá |
|---|---|---|
| Sensor acquisition | LM35 GPIO34, Flame GPIO19 và MQ-2 GPIO18 được đọc trong `loop()` | **FACT trong code** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 269–276; runtime **UNKNOWN** |
| Data processing | Logic DANGER/WARNING/SAFE với ngưỡng 45/40°C | **FACT trong code** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 278–300 |
| Local visualization | LCD 16×2 và ba LED | **FACT trong code** [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 61–135/153–192/302–313 |
| Actuator control | Servo GPIO32 và nút GPIO33 | **FACT trong code**, nhưng README mâu thuẫn [SRC-023](../src/FireDetectionSingleFinal.ino), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) |
| Wireless communication | Không có include/API Wi‑Fi hay MQTT | **FACT: chưa triển khai trong firmware** [SRC-023](../src/FireDetectionSingleFinal.ino) |
| Web/mobile | Không có trong firmware/repository | **FACT: chưa triển khai**; đây là bonus theo Fall 2026 |
| Quantitative evaluation | Không có dataset/test result | **UNKNOWN/chưa có bằng chứng**, có nguy cơ thiếu deliverable bắt buộc [SRC-001](../CF_IOT102_FA26.docx), mục 6 |

**INFERENCE:** Với Fall 2026, thiếu wireless có thể chấp nhận nếu architecture và evaluation phù hợp được giảng viên chấp thuận; không thể tự kết luận project đã đáp ứng course requirement chỉ từ code.

## Milestone

| Milestone | Thời điểm | Nội dung đánh giá / minh chứng | Nguồn |
|---|---:|---|---|
| OPA1 | Tuần 7 | Demo hardware + sensor; trình bày 10–15 phút và Q&A; review Block Diagram, Circuit Schematic, Flowchart cơ bản, prototype cơ bản | **FACT:** [SRC-001](../CF_IOT102_FA26.docx), mục 5 và 7.1 |
| OPA2 | Tuần 9 | Demo end-to-end; trình bày 15 phút; Draft Paper v1 gồm Introduction, Literature Review, Methodology, Result; báo cáo tiến độ/peer review | **FACT:** [SRC-001](../CF_IOT102_FA26.docx), mục 5 và 7.1 |
| Final | Tuần 11 | Live demo, trình bày 20 phút + Q&A, Final Report 5–8 trang IEEE, source repository, evidence/metrics; poster/video chỉ tùy chọn nếu không có yêu cầu khác | **FACT:** [SRC-001](../CF_IOT102_FA26.docx), mục 5–7 |

**UNKNOWN:** Không có deadline theo ngày/tháng trong file; chỉ có số tuần.

## Deliverables Fall 2026

| Deliverable | Hình thức | Mốc | Bắt buộc? | Nguồn |
|---|---|---|---|---|
| Prototype hoàn chỉnh | Demo live | Final tuần 11 | Có | [SRC-001](../CF_IOT102_FA26.docx), mục 6 |
| Final Report + AI Usage Declaration cuối bài | PDF, IEEE, 5–8 trang | Final | Có | [SRC-001](../CF_IOT102_FA26.docx), mục 6 và 12 |
| Research/Experimental Evidence | Metrics, biểu đồ, đánh giá định lượng trong report | OPA2 & Final | Có | [SRC-001](../CF_IOT102_FA26.docx), mục 6 |
| Source Code / Repository | GitHub/GitLab: code, schematic, README | Final | Có | [SRC-001](../CF_IOT102_FA26.docx), mục 6 |
| Presentation / Demo / Viva | PPTX/PDF + trình bày | OPA1, OPA2, Final | Có | [SRC-001](../CF_IOT102_FA26.docx), mục 6–7 |
| AI Usage Declaration | Nằm **trong từng report** OPA1/OPA2/Final | Mỗi báo cáo | Có | [SRC-001](../CF_IOT102_FA26.docx), mục 12 |
| AI Audit Log | File riêng `.pdf/.docx/.md`, khoảng 3–5 decision tiêu biểu | Final | Có; thiếu thì tiêu chí AI Verification 20 điểm = 0 | [SRC-001](../CF_IOT102_FA26.docx), mục 6, 7.2 và 13 |
| Dataset | Định dạng/thời lượng phù hợp đề tài | OPA2 & Final | Optional/theo đề tài | [SRC-001](../CF_IOT102_FA26.docx), mục 6 |
| Video demo ≤5 phút | MP4/link | Final | Optional | [SRC-001](../CF_IOT102_FA26.docx), mục 6 |
| Poster | PDF/in | Final | Optional | [SRC-001](../CF_IOT102_FA26.docx), mục 6 |

**CONFLICT lịch sử:** Summer 2026 coi dataset 3–7 ngày và video demo là bắt buộc; Fall 2026 chuyển chúng thành optional/theo đề tài, đồng thời bổ sung AI declaration/audit. [SRC-003](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>), mục III; [SRC-001](../CF_IOT102_FA26.docx), mục 6.

## Rubric Final (100 điểm)

| Tiêu chí | Điểm |
|---|---:|
| Final Report Document | 15 |
| Presentation | 10 |
| Block Diagram | 10 |
| Flowchart | 10 |
| Demonstration | 20 |
| AI Output Verification / Validation | 20 |
| Q&A / Oral Viva | 15 |
| **Tổng** | **100** |

**FACT:** Điểm từng thành viên phụ thuộc đóng góp; hội đồng gồm hai giảng viên, điểm hai người không lệch quá 20/100. [SRC-001](../CF_IOT102_FA26.docx), mục 7.2–7.3.

## Cấu trúc nộp bài

Tên folder được nêu: `26FA_[ClassName]_[GroupCode]_IOT102_FinalReport`, ví dụ `26FA_SE1830_G1_IOT102_FinalReport`. Các nhánh: `Documents/`, `AI_Audit_Log/`, `VideoDemo/` (optional), `SourceCode/`. [SRC-001](../CF_IOT102_FA26.docx), mục 6.

**CONFLICT nội bộ:** Cuối mục 13.4 của cùng nguồn lại nói AI Audit Log nộp trong `Documents/`, trong khi mục 6 chỉ định `AI_Audit_Log/`. Cần hỏi giảng viên/LMS; không tự chọn cấu trúc trước khi nộp. [SRC-001](../CF_IOT102_FA26.docx), mục 6 so với mục 13.4.

## Checklist bắt buộc

### OPA1

- [ ] Block Diagram khớp scope hiện tại (không còn cloud nếu chưa làm).
- [ ] Circuit Schematic khớp code và mạch thật, gồm đủ hai buzzer nếu thực tế dùng hai.
- [ ] Flowchart khớp logic hiện tại.
- [ ] Prototype cơ bản có thể demo; lưu ảnh/video/log làm bằng chứng.
- [ ] Presentation 10–15 phút + chuẩn bị Q&A.
- [ ] AI Usage Declaration nằm trong OPA1 report.

### OPA2

- [ ] Demo end-to-end theo scope đã chốt.
- [ ] Draft Paper v1: Introduction, Literature Review, Methodology, Result.
- [ ] Có evidence/metrics ban đầu; không để số liệu tự tạo.
- [ ] Báo cáo tiến độ và peer review.
- [ ] AI Usage Declaration nằm trong OPA2 report.

### Final

- [ ] Prototype demo live ổn định.
- [ ] Final Report PDF, IEEE, 5–8 trang; có AI Usage Declaration.
- [ ] Metrics/biểu đồ/test case có dữ liệu thật.
- [ ] Repository có source cuối, schematic đúng, README/build instructions.
- [ ] Slides + trình bày 20 phút + chuẩn bị Viva/Q&A.
- [ ] AI Audit Log file riêng, khoảng 3–5 engineering decisions với verification/evidence.
- [ ] Sửa/giải trình README đang sai tên sketch và mâu thuẫn về Servo; không sửa source gốc trong knowledge task. [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md)
- [ ] Kiểm tra yêu cầu LMS về dataset/video/poster và cấu trúc folder.
- [ ] Bảng đóng góp thành viên tổng 100% nếu dùng mẫu report. [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>), bảng Author's contribution.

## Nguồn tham khảo

- [SRC-001 — Kế hoạch Fall 2026](../CF_IOT102_FA26.docx)
- [SRC-003 — Định hướng Summer 2026](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>)
- [SRC-009 — Mẫu report LaTeX](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>)
- [SRC-023 — Firmware candidate](../src/FireDetectionSingleFinal.ino)

## Thông tin chưa xác minh

- Deadline theo ngày lịch, link nộp LMS và format chính xác từng OPA.
- Dataset/video/poster có bị giảng viên lớp yêu cầu bổ sung hay không.
- AI Audit Log phải đặt trong `AI_Audit_Log/` hay `Documents/`.
