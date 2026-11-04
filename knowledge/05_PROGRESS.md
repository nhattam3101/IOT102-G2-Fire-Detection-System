# Tiến độ có minh chứng

## Mục đích và phạm vi

Tài liệu này chỉ đánh dấu trạng thái dựa trên artefact trong repository. Có file thiết kế/source mô tả không đồng nghĩa code đã build, phần cứng đã chạy hay bài đã được duyệt. Xem [kế hoạch](04_PROJECT_PLAN.md), [vấn đề](06_ISSUES.md) và [chỉ mục nguồn](08_SOURCE_INDEX.md).

## Quy ước trạng thái

- **Có artefact:** File tồn tại và đọc được; chưa chắc được duyệt/đúng phiên bản.
- **Được mô tả, chưa xác minh:** Nguồn nói đã có thiết kế/sketch nhưng thiếu source/test/evidence.
- **Chưa tìm thấy:** Không có artefact trong phạm vi khảo sát.
- Không dùng `Done` nếu chưa có bằng chứng kết quả.

## Bảng tiến độ

| Hạng mục | Trạng thái | Minh chứng | Điều còn thiếu |
|---|---|---|---|
| Course requirements Fall 2026 | **Có artefact** | [SRC-001](../CF_IOT102_FA26.docx) | Xác nhận LMS/deadline ngày lịch |
| Project proposal/plan | **Có artefact** | [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx) | Approval và scope cuối |
| Block Diagram | **Có artefact nhưng lỗi thời/mâu thuẫn** | [SRC-005](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png), [SRC-008](../docs/design/source/BlockDiagram.drawio) | Loại cloud nếu không làm; thêm button/2 buzzer |
| Circuit Schematic | **Có artefact nhưng chưa xác minh** | [SRC-006](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>) | Sửa 2 buzzer, LED pin, level shifting, power; đối chiếu mạch thật |
| Flowchart | **Có artefact nhưng lỗi thời** | [SRC-007](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png) | Loại MQTT/dashboard; thêm button/door persistence nếu đúng code |
| Tài liệu bàn giao/technical explanation | **Có artefact** | [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) | Không thay code/mạch/test thật |
| Firmware ESP32 | **Có source candidate, chưa xác minh runtime** | [SRC-023](../src/FireDetectionSingleFinal.ino), HEAD `db664d5` | Xác nhận nhóm, dependency versions, compile/upload log |
| Wiring/prototype | **Được mô tả, chưa xác minh** | Pin table và checklist trong [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) | Ảnh mạch, BOM, đo áp, pin audit |
| Local SAFE/WARNING/DANGER | **Có trong code, chưa xác minh runtime** | [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 278–300/155–192 | TC01–TC08 có actual result |
| Servo/manual button/debounce | **Có trong code, chưa xác minh runtime** | [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 253–263/350–400 | Test cửa/button; giải quyết README mâu thuẫn và double call |
| MQTT/Node-RED/dashboard | **Không có trong firmware** | Static analysis [SRC-023](../src/FireDetectionSingleFinal.ino); scope local [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) | Chỉ khôi phục nếu có quyết định + implementation evidence |
| README firmware | **Có nhưng không nhất quán** | [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md) | Sửa tên sketch; thống nhất Servo với code |
| Dataset/metrics/charts | **Chưa tìm thấy** | Không có file tương ứng | Protocol đo, raw data, analysis |
| Literature Review/RQ | **Chưa tìm thấy** | Course chỉ nêu yêu cầu [SRC-001](../CF_IOT102_FA26.docx) | 6–10 paper, gap, RQ, novelty |
| OPA1 presentation/report | **Chưa tìm thấy** | — | Slides/report/declaration/demo evidence |
| OPA2 draft/progress | **Chưa tìm thấy** | — | Draft v1, evidence, progress report |
| Final Report | **Chưa tìm thấy** | Chỉ có template [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>) | Nội dung dự án và build PDF |
| Final slides/video/poster | **Chưa tìm thấy** | — | Theo requirement hiện hành |
| Source repository/README | **Có local Git repository nhưng README lỗi thời** | [SRC-023](../src/FireDetectionSingleFinal.ino)–[SRC-026](../IOT102-G2-Fire-Detection-System/.gitignore) | Remote/public link chưa xác minh; sửa tên sketch/Servo; thêm schematic, versions và build log |
| AI Usage Declaration | **Chưa tìm thấy** | Chỉ có mẫu trong [SRC-001](../CF_IOT102_FA26.docx) | Chèn vào từng report |
| AI Audit Log | **Chưa tìm thấy** | Chỉ có hướng dẫn trong [SRC-001](../CF_IOT102_FA26.docx) | File riêng 3–5 decisions |

## Những phần đã hoàn thành có minh chứng

Chỉ có thể xác nhận việc **tạo artefact**, không xác nhận hoàn thành chức năng:

- Course plan Fall 2026 và định hướng Summer 2026 đã có. [SRC-001](../CF_IOT102_FA26.docx), [SRC-003](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>).
- Project plan G2 đã có. [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx).
- Có Block Diagram, Circuit Schematic, Flowchart dạng ảnh và Block Diagram draw.io editable. [SRC-005]–[SRC-008].
- Có tài liệu bàn giao giải thích scope local, GPIO, logic, test cases dự kiến và limitations. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx).
- Có firmware Arduino/ESP32 401 dòng triển khai sensor, state logic, LCD, LED, hai buzzer, Servo/button và Serial. [SRC-023](../src/FireDetectionSingleFinal.ino). Đây là minh chứng implementation tĩnh, không phải minh chứng chạy thành công.
- Có hướng dẫn chọn ESP32 Dev Module và nạp bằng Arduino IDE, nhưng tên sketch trong hướng dẫn sai. [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md).
- Có template report và tutorial tham khảo. [SRC-009]–[SRC-020].

## Những phần đang làm

**UNKNOWN:** Không có task tracker, commit history trong phạm vi được đọc hoặc trạng thái thành viên, nên không thể xác nhận mục nào “đang làm”. Tài liệu bàn giao có checklist chưa tích và bảng test result để trống; đây là dấu hiệu công việc còn cần thực hiện, không phải bằng chứng đang được xử lý. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 9.2 và Phụ lục B.

## Chưa thực hiện hoặc chưa xác minh

- [ ] Scope cuối được nhóm/giảng viên xác nhận.
- [x] Có source `.ino` candidate; [ ] xác nhận phiên bản cuối và bổ sung compile/upload log.
- [ ] Mạch thật khớp code/schematic; đo mức DO 3,3 V an toàn.
- [ ] TC01–TC08 có actual result, ảnh/log/video.
- [ ] Metrics định lượng và dataset/raw log.
- [ ] Literature Review, research gap và RQ.
- [ ] OPA1/OPA2 artefacts.
- [ ] Final Report, repository README, slides và demo package.
- [ ] AI Usage Declaration và AI Audit Log.

## Cổng chuyển trạng thái

Một tính năng chỉ nên chuyển sang “đã xác minh” khi có tối thiểu:

1. source/config cùng version;
2. artefact build/upload hoặc wiring audit;
3. test case có input, expected, actual, pass/fail;
4. evidence (log/ảnh/video/raw data);
5. reviewer/ngày kiểm tra.

## Nguồn tham khảo

- [SRC-001 — Course plan](../CF_IOT102_FA26.docx)
- [SRC-002 — Project plan](../docs/project/IOT102_Fire_Detection_Project_Plan.docx)
- [SRC-004 — Handover/checklist/test cases](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx)
- [SRC-005–SRC-009 — Diagram/template](08_SOURCE_INDEX.md)
- [SRC-023–SRC-026 — Firmware repository](08_SOURCE_INDEX.md)

## Thông tin chưa xác minh

Tiến độ thực tế theo người, ngày, milestone và kết quả demo không có trong nguồn.
