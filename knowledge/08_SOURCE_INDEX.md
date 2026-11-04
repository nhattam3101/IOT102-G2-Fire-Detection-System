# Chỉ mục nguồn

## Mục đích và phạm vi

File này ánh xạ Source ID tới toàn bộ 26 file được khảo sát trong `Project` (không tính các thư mục `.git` và output `knowledge/`). Trạng thái “đọc được” chỉ nói về khả năng trích xuất/kiểm tra file, không xác nhận nội dung kỹ thuật là đúng với phần cứng thật.

Liên quan: [bối cảnh](00_PROJECT_CONTEXT.md), [yêu cầu](01_REQUIREMENTS.md), [kiến trúc](02_ARCHITECTURE.md), [source code](03_SOURCE_CODE.md), [tiến độ](05_PROGRESS.md).

| ID | Đường dẫn gốc | Loại tài liệu | Nội dung chính | Độ tin cậy / Trạng thái |
|---|---|---|---|---|
| [SRC-001] | [`CF_IOT102_FA26.docx`](../CF_IOT102_FA26.docx) | Course Requirements | Kế hoạch PBL+RBL Fall 2026, tuần 1–11, deliverables, rubric, AI declaration/audit | **Cao cho học kỳ hiện tại**; DOCX hợp lệ; metadata tạo/sửa 03/09/2026 |
| [SRC-002] | [`IOT102_Fire_Detection_Project_Plan.docx`](../docs/project/IOT102_Fire_Detection_Project_Plan.docx) | Project Proposal / Plan | Scope dự kiến G2: ESP32, ba cảm biến, MQTT/Node-RED, actuator và kế hoạch 10 bước | **Trung bình**; kế hoạch, không phải bằng chứng hoàn thành; DOCX hợp lệ |
| [SRC-003] | [`ĐỊNH HƯỚNG ĐỀ TÀI.docx`](<../ĐỊNH HƯỚNG ĐỀ TÀI.docx>) | Course Requirements | Yêu cầu Summer 2026, 5 nhóm đề tài, 5 yêu cầu kỹ thuật, deliverables cũ | **Nguồn lịch sử**; DOCX hợp lệ; bị [SRC-001] thay đổi một số yêu cầu |
| [SRC-004] | [`src/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx`](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) | Source Code / Technical Implementation | Tài liệu bàn giao 01/11/2026: phạm vi local, GPIO, state logic, pseudocode, test case trống | **Cao nhất cho thiết kế gần nhất**, nhưng tự tuyên bố không thay source/mạch/test thật; DOCX hợp lệ, 2 hình nhúng đã kiểm tra |
| [SRC-005] | [`example/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png`](../docs/design/exports/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png) | System Architecture / Diagrams | Sơ đồ khối G2 có ESP32, sensor/actuator, MQTT, Node-RED, web dashboard, CSV | **Thiết kế cũ/mâu thuẫn hiện trạng**; ảnh đọc được |
| [SRC-006] | [`example/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png`](<../docs/design/exports/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png>) | System Architecture / Diagrams | Sơ đồ điện ESP32, GPIO, 5 V, một buzzer, LED, sensor, LCD, servo, nút | **Cần sửa/xác minh**; ảnh đọc được; có mâu thuẫn GPIO/số buzzer và rủi ro mức áp |
| [SRC-007] | [`example/BlockDiagram_IOT102_G2-FlowChart.drawio.png`](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png) | System Architecture / Diagrams | Luồng SAFE/WARNING/DANGER và gửi MQTT/dashboard | **Thiết kế cũ/mâu thuẫn hiện trạng**; ảnh đọc được |
| [SRC-008] | [`example/26FA_SE2027_Group02_IOT102_FinalReport/BlockDiagram.drawio`](../docs/design/source/BlockDiagram.drawio) | System Architecture / Diagrams | File draw.io editable có sensor, ESP32, output và cloud MQTT/Node-RED/dashboard/CSV | **Bản thiết kế editable cũ**; XML đọc được |
| [SRC-009] | [`example/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex`](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>) | Report / Presentation | Mẫu IEEE one-column: Introduction, Methods, Results, Discussion, Conclusion, contribution | **Mẫu tham khảo**, không phải báo cáo dự án; đọc được |
| [SRC-010] | [`example/IOT102_Final_Project_Report_Template/Bib_references.bib`](../references/IOT102_Final_Project_Report_Template/Bib_references.bib) | Examples / References | 8 mục BibTeX về IoT/ML/network | **Tham khảo mẫu**; chưa chứng minh liên quan trực tiếp đề tài cháy; đọc được |
| [SRC-011] | [`example/IOT102_Final_Project_Report_Template/arduino tutorial Lab 1 lab 4.pdf`](<../references/IOT102_Final_Project_Report_Template/arduino tutorial Lab 1 lab 4.pdf>) | Examples / References | 37 trang: Arduino cơ bản, blink, analog input, if, millis, hàm I/O | **Tài liệu học tập**; PDF đọc được; không phải code dự án |
| [SRC-012] | [`example/IOT102_Final_Project_Report_Template/shematic.pdf`](../references/IOT102_Final_Project_Report_Template/shematic.pdf) | Examples / References | Sơ đồ mẫu tưới nước/HC-05/I²C/button/water-flow | **Không thuộc đề tài cháy**; PDF 1 trang đọc được, có cảnh báo render nhỏ từ parser nhưng nội dung chính trích xuất được |
| [SRC-013] | [`example/IOT102_Final_Project_Report_Template/5a_Blink an LED_Digital Write.docx`](<../references/IOT102_Final_Project_Report_Template/5a_Blink an LED_Digital Write.docx>) | Examples / References | Arduino Blink, LED và `digitalWrite` | **Tài liệu mẫu**; DOCX hợp lệ |
| [SRC-014] | [`example/IOT102_Final_Project_Report_Template/Slot8_Serial_Input.docx`](../references/IOT102_Final_Project_Report_Template/Slot8_Serial_Input.docx) | Examples / References | Arduino serial input và `switch/case` điều khiển 5 LED | **Tài liệu mẫu**; DOCX hợp lệ |
| [SRC-015] | [`example/IOT102_Final_Project_Report_Template/Slot9_Blink_Without_Delay.docx`](../references/IOT102_Final_Project_Report_Template/Slot9_Blink_Without_Delay.docx) | Examples / References | Blink không chặn bằng `millis()` | **Có thể tham khảo timing buzzer**, không phải code dự án; DOCX hợp lệ |
| [SRC-016] | [`example/IOT102_Final_Project_Report_Template/Slot9_Debounce.docx`](../references/IOT102_Final_Project_Report_Template/Slot9_Debounce.docx) | Examples / References | Debounce nút nhấn bằng `millis()` | **Có thể tham khảo debounce**, không phải code dự án; DOCX hợp lệ |
| [SRC-017] | [`example/IOT102_Final_Project_Report_Template/Arduino_Uno.jpg`](../references/IOT102_Final_Project_Report_Template/Arduino_Uno.jpg) | Examples / References | Ảnh Arduino Uno | **Ảnh minh họa mẫu**; đọc được; controller dự án là ESP32 |
| [SRC-018] | [`example/IOT102_Final_Project_Report_Template/Block_diagram.png`](../references/IOT102_Final_Project_Report_Template/Block_diagram.png) | Examples / References | Sơ đồ hệ thống tưới nước Arduino/NodeMCU/ThingSpeak | **Không thuộc đề tài cháy**; ảnh đọc được |
| [SRC-019] | [`example/IOT102_Final_Project_Report_Template/Circuit_Schematic.jpg`](../references/IOT102_Final_Project_Report_Template/Circuit_Schematic.jpg) | Examples / References | Hình đấu nối hệ thống tưới nước | **Không thuộc đề tài cháy**; ảnh đọc được |
| [SRC-020] | [`example/IOT102_Final_Project_Report_Template/IoT_Components.jpg`](../references/IOT102_Final_Project_Report_Template/IoT_Components.jpg) | Examples / References | Hình minh họa device–gateway–cloud–analytics–UI | **Hình khái niệm chung**; ảnh đọc được |
| [SRC-021] | [`example/IOT102_Final_Project_Report_Template/Untitled Sketch_bb.png`](<../references/IOT102_Final_Project_Report_Template/Untitled Sketch_bb.png>) | Examples / References | Ảnh PNG sơ đồ mẫu kích thước cực rộng `132063×3708` | **Đọc một phần**; nhận diện được PNG/kích thước nhưng công cụ xem ảnh báo không hỗ trợ dữ liệu; không suy đoán chi tiết |
| [SRC-022] | [`~$T102_Fire_Detection_Project_Plan.docx`](<../~$T102_Fire_Detection_Project_Plan.docx>) | Other / Unclassified | File tạm/lock tên gần giống project plan | **Không đọc được**; 162 byte, không phải ZIP/DOCX hợp lệ; không dùng làm nguồn |
| [SRC-023] | [`IOT102-G2-Fire-Detection-System/Final/FireDetectionFinal/FireDetectionSingleFinal.ino`](../src/FireDetectionSingleFinal.ino) | Source Code / Technical Implementation | Firmware Arduino/ESP32: sensor, ADC LM35, LCD I²C, LED, hai buzzer, Servo và nút nhấn | **Nguồn code trực tiếp cao nhất**; 401 dòng; HEAD `db664d5` ngày 26/10/2026; SHA-256 `681712ce…a5eafc`; chưa có build/test log |
| [SRC-024] | [`IOT102-G2-Fire-Detection-System/README.md`](../IOT102-G2-Fire-Detection-System/README.md) | Source Code / Technical Implementation | README gốc repository, hướng dẫn chọn ESP32 Dev Module và Verify/Upload | **Đọc được nhưng link sketch sai tên**; không phải bằng chứng build thành công |
| [SRC-025] | [`IOT102-G2-Fire-Detection-System/Final/README.md`](../IOT102-G2-Fire-Detection-System/Final/README.md) | Source Code / Technical Implementation | GPIO, state rules, hướng dẫn Arduino IDE, Serial 115200 | **Đọc được nhưng mâu thuẫn code về Servo và sai tên sketch** |
| [SRC-026] | [`IOT102-G2-Fire-Detection-System/.gitignore`](../IOT102-G2-Fire-Detection-System/.gitignore) | Source Code / Technical Implementation | Bỏ qua build output, CSV, credential headers và file môi trường | **Đọc được**; lưu ý `*.csv` bị ignore có thể làm dataset không được version-control |

## Thống kê khảo sát

- Tổng file: **26**.
- Đọc/kiểm tra đầy đủ: **24**.
- Đọc một phần: **1** — [SRC-021].
- Không đọc được: **1** — [SRC-022].
- Phát hiện **1 firmware `.ino`** và 3 file hỗ trợ repository; chưa phát hiện dataset, log build/kiểm thử, báo cáo cuối hoặc slide dự án.

## Phân loại theo nhóm

| Nhóm | Source ID |
|---|---|
| Course Requirements | SRC-001, SRC-003 |
| Project Proposal / Plan | SRC-002 |
| Research Materials | SRC-001 (quy trình/yêu cầu); chưa có literature review riêng |
| System Architecture / Diagrams | SRC-005–SRC-008 |
| Source Code / Technical Implementation | SRC-004, SRC-023–SRC-026 |
| Report / Presentation | SRC-009; chưa có báo cáo/slides dự án |
| Examples / References | SRC-010–SRC-021 |
| Other / Unclassified | SRC-022 |

## Nguồn tham khảo

Các đường dẫn trong bảng là nguồn gốc trực tiếp.

## Thông tin chưa xác minh

- Hash/version chính thức và quan hệ phiên bản giữa các ảnh sơ đồ chưa được ghi trong nguồn.
- [SRC-021] cần mở bằng công cụ ảnh có khả năng xử lý canvas cực lớn nếu thực sự cần dùng.
- [SRC-023] là file hiện tại tại HEAD `db664d5`, nhưng không có release tag hay văn bản phê duyệt để kết luận đây là quyết định chính thức cuối cùng của nhóm.
