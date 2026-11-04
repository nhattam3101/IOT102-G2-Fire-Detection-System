# Kế hoạch triển khai

## Mục đích và phạm vi

Tài liệu này hợp nhất lộ trình 11 tuần của môn học với chuỗi công việc dự án. Đây là kế hoạch và dependency, không phải bảng xác nhận hoàn thành. Trạng thái bằng chứng nằm tại [05_PROGRESS.md](05_PROGRESS.md); yêu cầu tại [01_REQUIREMENTS.md](01_REQUIREMENTS.md).

## Lộ trình 11 tuần

| Tuần | Giai đoạn | Kết quả cần có | Trạng thái theo repository |
|---:|---|---|---|
| 1 | Course introduction | Hiểu PBL/RBL, hướng đề tài | **Không theo dõi được** |
| 2 | Topic proposal | Topic + Problem Statement được duyệt | Có project plan, nhưng **UNKNOWN** đã được duyệt [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx) |
| 3 | Literature Review/RQ | Mini-LR 2–3 trang, Research Question, novelty | **Chưa tìm thấy** |
| 4 | System Design | Block Diagram, interfacing plan, architecture | Có diagram, nhưng mâu thuẫn scope/GPIO [SRC-005]–[SRC-008] |
| 5 | Hardware integration | Prototype cơ bản, calibration, raw log | Tài liệu/code mô tả hardware; **không có bằng chứng mạch/test/log** [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), [SRC-023](../src/FireDetectionSingleFinal.ino) |
| 6 | Firmware | Flowchart, firmware cơ bản, telemetry theo đề tài | Có firmware local và flowchart cũ; build/telemetry **chưa xác minh** [SRC-023](../src/FireDetectionSingleFinal.ino), [SRC-007](../docs/design/exports/BlockDiagram_IOT102_G2-FlowChart.drawio.png) |
| 7 | OPA1 | Diagram + schematic + flowchart + prototype cơ bản | Diagram và firmware có; demo **UNKNOWN** |
| 8 | Prototype/data | Prototype, dữ liệu thô, biểu đồ, Methodology/Result sơ bộ | **Chưa tìm thấy** |
| 9 | OPA2 | Demo end-to-end, Draft Paper v1, progress report | **Chưa tìm thấy** |
| 10 | Refinement | Hệ thống ổn định, Paper v2 | **Chưa tìm thấy** |
| 11 | Final | Demo, report, repo, evidence, slides/Q&A | **Chưa tìm thấy** |

Lộ trình course: [SRC-001](../CF_IOT102_FA26.docx), mục 5. Trạng thái được suy ra chỉ từ file hiện có, không thay xác nhận của nhóm.

## Chuỗi công việc dự án và phụ thuộc

```text
Chốt scope hiện tại
  -> Chốt BOM + nguồn/mức điện áp
    -> Test từng linh kiện
      -> Đồng bộ Block Diagram + Schematic + Flowchart + GPIO
        -> Hoàn thiện firmware local
          -> Integration và TC01–TC08
            -> Thu metrics/evidence
              -> Viết report + README + slides + AI audit
                -> Rehearsal demo/Q&A và đóng gói Final
```

Nguồn chuỗi 10 bước ban đầu: [SRC-002](../docs/project/IOT102_Fire_Detection_Project_Plan.docx), mục 6. Scope local gần nhất: [SRC-004](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx), mục 1.3.

## Kế hoạch hành động ưu tiên

| ID | Công việc | Phụ thuộc | Đầu ra kiểm chứng |
|---|---|---|---|
| P-01 | Chốt local-only hay khôi phục MQTT/dashboard | Quyết định nhóm/giảng viên | Scope statement phiên bản/ngày |
| P-02 | Đối chiếu mạch thật, code và GPIO | Có mạch + [SRC-023](../src/FireDetectionSingleFinal.ino) | Pin map signed-off, ảnh dây |
| P-03 | Sửa schematic an toàn 3,3 V/nguồn | P-02, datasheet/module measurement | Schematic mới, BOM điện trở/nguồn |
| P-04 | Sửa block diagram/flowchart theo scope | P-01, P-02 | Diagram không còn thành phần chưa triển khai |
| P-05 | Xác nhận source candidate, sửa hướng dẫn tên file/Servo và ghi dependency versions | P-02 | Release/tag hoặc xác nhận nhóm; README đúng; compile log |
| P-06 | Thực hiện TC01–TC08 an toàn | P-03, P-05 | Bảng result, ảnh/log/video |
| P-07 | Định nghĩa và thu metrics | P-06 | CSV/log, biểu đồ, phương pháp đo |
| P-08 | Literature Review/RQ | Topic/scope chốt | 6–10 bài phù hợp, gap/RQ [SRC-001](../CF_IOT102_FA26.docx), mục 2.2 |
| P-09 | Hoàn thiện report/repo/slides/AI audit | P-04–P-08 | Bộ deliverables theo [01_REQUIREMENTS.md](01_REQUIREMENTS.md) |
| P-10 | Rehearsal Final | P-09 | Demo script, rollback plan, Q&A ownership |

## Phân công và deadline

- **UNKNOWN:** Không có tên thành viên, owner công việc, ma trận trách nhiệm hay deadline theo ngày trong nguồn.
- **FACT:** Mẫu report có bảng `Author's contribution` và tổng đóng góp 100%, nhưng dữ liệu trong mẫu là placeholder. [SRC-009](<../references/IOT102_Final_Project_Report_Template/IOT102 - Final Project Report.tex>).
- **Khuyến nghị quản trị (INFERENCE):** Nhóm cần điền owner/reviewer/due date cho P-01–P-10; không thể tự gán từ repository.

## Checklist quản lý

- [ ] Chốt owner và due date cho từng P-ID.
- [ ] Mỗi mục “Done” có link tới artefact/test evidence.
- [ ] Diagram, firmware và wiring cùng version.
- [ ] Quyết định xử lý lời gọi `updateDoor()` hai lần và test debounce trước khi freeze firmware. [SRC-023](../src/FireDetectionSingleFinal.ino), dòng 283/345.
- [ ] Không đưa tính năng future work vào phần Results.
- [ ] Đối chiếu milestone với LMS vì source không có ngày lịch.
- [ ] Ghi 3–5 AI-assisted engineering decisions trong suốt dự án, không dồn cuối kỳ. [SRC-001](../CF_IOT102_FA26.docx), mục 13.

## Nguồn tham khảo

- [SRC-001 — Lộ trình 11 tuần](../CF_IOT102_FA26.docx)
- [SRC-002 — Quy trình dự án 10 bước](../docs/project/IOT102_Fire_Detection_Project_Plan.docx)
- [SRC-004 — Scope và checklist bàn giao](../docs/project/IOT102_Tai_Lieu_Ban_Giao_Du_An_Canh_Bao_Chay.docx)
- [SRC-023 — Firmware candidate](../src/FireDetectionSingleFinal.ino)

## Thông tin chưa xác minh

Phê duyệt đề tài, lịch lớp cụ thể, phân công, ngày OPA/Final và tiến độ thực tế của P-01–P-10.
