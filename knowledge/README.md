# Knowledge base dự án IoT102

## Mục đích và phạm vi

Knowledge base này tóm tắt các tài liệu và hiện vật đang có trong thư mục `Project` để thành viên mới, người quản lý và trợ lý AI tra cứu nhanh mà không phải đọc lại toàn bộ DOCX/PDF. Nội dung chỉ phản ánh bằng chứng có trong repository tại thời điểm khảo sát; không chứng minh phần cứng đã chạy hay tính năng đã được kiểm thử.

> **Lưu ý sau khi sắp xếp (04/11/2026):** các đường dẫn tới artefact còn tồn tại đã được cập nhật theo cấu trúc mới. Một số nguồn từng có trong workspace khảo sát ban đầu (course plan, repository README cũ và lock file Word) không có trong thư mục Project hiện tại; các liên kết đó được giữ lại như dấu vết lịch sử và có thể không mở được.

**Cập nhật:** 03/11/2026 (Asia/Ho_Chi_Minh)  
**Phạm vi khảo sát:** 26 file ngoài các thư mục `.git` và ngoài `knowledge/`.  
**Kết quả đọc:** 24 file đọc/kiểm tra đầy đủ, 1 file kiểm tra một phần, 1 file không đọc được. Chi tiết tại [08_SOURCE_INDEX.md](08_SOURCE_INDEX.md).

## Quy ước độ chắc chắn

- **FACT:** Nội dung có nguồn trực tiếp. Với mô tả tính năng, điều này chỉ có nghĩa là *tài liệu khẳng định như vậy*, không mặc nhiên là phần cứng đã được xác minh.
- **INFERENCE:** Suy luận hợp lý từ một hay nhiều nguồn, cần xác nhận.
- **UNKNOWN:** Chưa có đủ tài liệu hoặc bằng chứng.
- **CONFLICT:** Các nguồn không thống nhất; giữ nguyên khác biệt để nhóm quyết định.

Mỗi nguồn dùng ID dạng `[SRC-001]`. Bảng ánh xạ ID, đường dẫn, phân loại và trạng thái nằm trong [08_SOURCE_INDEX.md](08_SOURCE_INDEX.md).

## Thứ tự đọc đề xuất

1. [00_PROJECT_CONTEXT.md](00_PROJECT_CONTEXT.md) — hiểu đề tài, phạm vi và trạng thái xác minh.
2. [01_REQUIREMENTS.md](01_REQUIREMENTS.md) — yêu cầu Fall 2026, OPA1/OPA2/Final và checklist.
3. [02_ARCHITECTURE.md](02_ARCHITECTURE.md) — kiến trúc, GPIO và đối chiếu thiết kế–firmware.
4. [03_SOURCE_CODE.md](03_SOURCE_CODE.md) — firmware thực tế, hàm, luồng chạy và giới hạn xác minh.
5. [04_PROJECT_PLAN.md](04_PROJECT_PLAN.md) — lộ trình, phụ thuộc và đầu việc.
6. [05_PROGRESS.md](05_PROGRESS.md) — phần đã có minh chứng, chưa xác minh và còn thiếu.
7. [06_ISSUES.md](06_ISSUES.md) — rủi ro, mâu thuẫn và quyết định cần chốt.
8. [07_REPORT_GUIDE.md](07_REPORT_GUIDE.md) — hướng dẫn hoàn thiện báo cáo từ bằng chứng thật.
9. [08_SOURCE_INDEX.md](08_SOURCE_INDEX.md) — truy ngược về nguồn gốc.

## Cách dùng

### Thành viên mới

Đọc theo thứ tự trên. Firmware candidate hiện tại là [SRC-023](../src/FireDetectionSingleFinal.ino), nhưng vẫn phải đối chiếu mạch thật và log build/test trước khi kết luận hệ thống chạy. Không dùng các hình trong `example/IOT102_Final_Project_Report_Template/` làm thiết kế của dự án: đó là ví dụ Arduino/tưới nước, không phải hệ thống cảnh báo cháy. [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>)

### ChatGPT/Codex

Nạp `README.md`, `00_PROJECT_CONTEXT.md`, file chuyên đề liên quan và `08_SOURCE_INDEX.md`. Khi trả lời:

- giữ nguyên nhãn `FACT/INFERENCE/UNKNOWN/CONFLICT`;
- không biến “có trong kế hoạch/tài liệu bàn giao” thành “đã chạy thành công”;
- ưu tiên course plan Fall 2026 cho yêu cầu; dùng firmware [SRC-023](../src/FireDetectionSingleFinal.ino) cho hành vi được code hóa và tài liệu bàn giao [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx) cho diễn giải;
- không coi tên thư mục `Final` hoặc commit mới nhất là phê duyệt chính thức của nhóm;
- yêu cầu bằng chứng mới nếu câu hỏi liên quan code cuối, dây mạch thật, test, số liệu hoặc cloud.

### Người quản lý

Dùng [05_PROGRESS.md](05_PROGRESS.md) làm bảng kiểm trạng thái và [06_ISSUES.md](06_ISSUES.md) làm danh sách quyết định/rủi ro. Chỉ chuyển mục sang hoàn thành sau khi có artefact hoặc kết quả kiểm thử được liên kết.

## Nhóm tài liệu phát hiện

| Nhóm | Nội dung |
|---|---|
| Course Requirements | Kế hoạch triển khai IOT102 Fall 2026; định hướng Summer 2026 cũ |
| Project Proposal / Plan | Kế hoạch hệ thống phát hiện và cảnh báo cháy nhóm G2 |
| System Architecture / Diagrams | Block Diagram, Circuit Schematic, Flowchart và draw.io |
| Source Code / Technical Implementation | Một sketch ESP32 401 dòng, hai README, `.gitignore` và tài liệu bàn giao |
| Report / Presentation | Mẫu báo cáo LaTeX và BibTeX; chưa có báo cáo/slides dự án |
| Research Materials | Tài liệu course yêu cầu literature review; chưa có bài nghiên cứu riêng của đề tài |
| Examples / References | Tutorial Arduino, debounce, blink, sơ đồ tưới nước mẫu |
| Other / Unclassified | Lock file Word không đọc được |

## Giới hạn dữ liệu

- **FACT tại thời điểm khảo sát:** Firmware ban đầu nằm trong repository con `IOT102-G2-Fire-Detection-System/`. Sau khi sắp xếp workspace, bản firmware hiện có nằm tại [`src/FireDetectionSingleFinal.ino`](../src/FireDetectionSingleFinal.ino), còn tài liệu bàn giao nằm trong `docs/project/`. [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-023](../src/FireDetectionSingleFinal.ino)
- **UNKNOWN:** Không có log build/upload, log test có lưu file, dataset, ảnh mạch thật, video demo, báo cáo cuối hoặc slide dự án.
- **CONFLICT:** README nói không dùng Servo và trỏ tới `FireDetectionFinal.ino`; code hiện có dùng `ESP32Servo`, GPIO32/33 và mang tên `FireDetectionSingleFinal.ino`. [SRC-023](../src/FireDetectionSingleFinal.ino), [SRC-024](../IOT102-G2-Fire-Detection-System/README.md), [SRC-025](../IOT102-G2-Fire-Detection-System/Final/README.md)
- File `example/IOT102_Final_Project_Report_Template/Untitled Sketch_bb.png` có kích thước bất thường `132063×3708`; công cụ xác định được định dạng nhưng không giải mã để kiểm tra toàn ảnh. [SRC-021](<../references/IOT102_Final_Project_Report_Template/Untitled Sketch_bb.png>)
- File `~$T102_Fire_Detection_Project_Plan.docx` là file 162 byte, không phải gói DOCX hợp lệ; có dấu hiệu là lock file Word. Không suy đoán nội dung. [SRC-022](<../~$T102_Fire_Detection_Project_Plan.docx>)
- Nội dung nhúng của DOCX đã được kiểm tra ở mức văn bản, bảng và hình quan trọng; không sao chép toàn văn vào knowledge base.

## Nguồn tham khảo

Danh mục đầy đủ: [08_SOURCE_INDEX.md](08_SOURCE_INDEX.md).

## Thông tin chưa xác minh

Xem danh sách tập trung tại [05_PROGRESS.md](05_PROGRESS.md#chưa-thực-hiện-hoặc-chưa-xác-minh) và [06_ISSUES.md](06_ISSUES.md).
