# PAPER 01 – Multi-Detector Real-Time Fire Alarm Technology

## 1. Thông tin bài báo

- **Title:** Research on multi-detector real-time fire alarm technology based on signal similarity
    
- **Authors:** Miaomiao Yu, Hongyong Yuan, Kaiyuan Li, Jingwu Wang
    
- **Journal:** Fire Safety Journal
    
- **Volume:** 136
    
- **Publication:** April 2023
    
- **Article Number:** 103724
    
- **DOI:** [https://doi.org/10.1016/j.firesaf.2022.103724](https://doi.org/10.1016/j.firesaf.2022.103724)
    
- **Source:** Elsevier – ScienceDirect
    
- **Available material:** Abstract, Introduction, Section Snippets và Conclusion trích đoạn; chưa có toàn văn.
    

## 2. Research Problem – Vấn đề nghiên cứu

Các hệ thống cảnh báo cháy cần phát hiện nguy hiểm sớm và chính xác. Tuy nhiên, đầu báo cháy truyền thống có thể tạo ra nhiều cảnh báo nhầm (_false alarms_) do những yếu tố không phải cháy, chẳng hạn khói nấu ăn.

Việc chỉ dựa trên một tín hiệu hoặc một ngưỡng cố định có thể gây khó khăn khi phân biệt đám cháy thực sự với nguồn nhiễu trong môi trường.

Nghiên cứu tập trung giải quyết hai vấn đề:

1. Phát hiện cháy kịp thời dựa trên tín hiệu của nhiều đầu dò.
    
2. Giảm cảnh báo nhầm bằng cách phân tích mối quan hệ giữa các tín hiệu cảm biến.
    

## 3. Research Objectives – Mục tiêu

Đề xuất một mô hình cảnh báo cháy thời gian thực dựa trên **sự tương đồng tín hiệu giữa nhiều đầu dò**.

Mô hình xem xét sự khác biệt về thời điểm phản hồi, diễn biến tín hiệu và mối tương quan giữa các đầu dò để hỗ trợ phân biệt cháy với nguồn gây nhiễu.

## 4. Proposed Methodology – Phương pháp

Nghiên cứu kết hợp ba kỹ thuật chính:

### 4.1. Derivative Dynamic Time Warping (DDTW)

DDTW được sử dụng để căn chỉnh các chuỗi tín hiệu có sự khác biệt về thời gian phản hồi.

Ví dụ, các đầu dò ở những vị trí khác nhau có thể phát hiện dấu hiệu cháy ở các thời điểm khác nhau.

Phương pháp giúp so sánh đặc điểm biến thiên của các tín hiệu ngay cả khi chúng không đồng bộ hoàn toàn.

### 4.2. Pearson Correlation Coefficient

Hệ số tương quan Pearson được sử dụng để đo mức độ tương đồng giữa các tín hiệu sau khi căn chỉnh.

Mục tiêu là xác định các đầu dò có đang phản hồi theo một xu hướng liên quan đến cùng một hiện tượng hay không.

### 4.3. Support Vector Classification (SVC)

SVC được sử dụng để xác định ngưỡng cảnh báo dựa trên dữ liệu huấn luyện.

Ngưỡng được xem xét theo số lượng đầu dò phản hồi, thay vì áp dụng một điều kiện duy nhất cho mọi tình huống.

### 4.4. Quy trình tổng quát

1. Thu thập tín hiệu từ nhiều đầu dò.
    
2. Căn chỉnh tín hiệu theo thời gian bằng DDTW.
    
3. Tính hệ số tương quan Pearson.
    
4. Sử dụng ngưỡng phân loại xác định bằng SVC.
    
5. Đưa ra quyết định cảnh báo cháy.
    

## 5. Experimental Setup – Thiết lập thí nghiệm

Theo nội dung bài báo được cung cấp:

- Sử dụng dữ liệu thử nghiệm cháy từ National Institute of Standards and Technology (NIST).
    
- Sử dụng dữ liệu thử nghiệm nguồn gây nhiễu trong môi trường bếp (_kitchen cooking nuisance tests_).
    
- Thực hiện thí nghiệm hiệu chuẩn trong hệ thống Fire Emulation/Detector Evaluation (FE/DE).
    
- Có thử nghiệm sử dụng năm đầu dò khói quang điện.
    
- Tập dữ liệu huấn luyện được mô tả gồm 149 nhóm dữ liệu hệ số tương quan:
    
    - 85 nhóm từ thử nghiệm cháy.
        
    - 64 nhóm từ mô phỏng nguồn gây nhiễu.
        

Các số liệu trên thuộc **nghiên cứu gốc**, không phải dữ liệu thực nghiệm của dự án G2.

## 6. Results and Findings – Kết quả nghiên cứu

Các kết quả được trình bày trong nội dung trích xuất cho thấy:

- Nghiên cứu xây dựng mô hình phát hiện cháy dựa trên tương quan tín hiệu giữa nhiều đầu dò.
    
- Mô hình xem xét độ trễ thời gian và sự tương đồng của tín hiệu.
    
- Ngưỡng cảnh báo được xác định thông qua phương pháp phân loại dựa trên dữ liệu.
    
- Nhóm tác giả đánh giá mô hình bằng dữ liệu thử nghiệm cháy và nguồn gây nhiễu.
    

**Giới hạn thông tin:** Phần tài liệu hiện có chưa cung cấp đầy đủ chỉ số Accuracy, Precision, Recall, False Alarm Rate hoặc Response Time cuối cùng. Không được tự suy luận hay ghi các tỷ lệ phần trăm cụ thể.

## 7. Limitations – Những giới hạn cần lưu ý

Từ nội dung bài báo và phần Introduction:

- Tín hiệu đầu dò phụ thuộc loại cảm biến, vị trí đặt, nguồn cháy và môi trường.
    
- Dữ liệu huấn luyện khó bao quát mọi tình huống cháy.
    
- Những mô hình AI hoặc thống kê phức tạp có thể yêu cầu tài nguyên xử lý cao hơn.
    
- Bài báo đề xuất phương pháp dựa trên chuỗi tín hiệu, không phải hệ thống chỉ đọc tín hiệu digital HIGH/LOW.
    

Các giới hạn cụ thể của chính mô hình Pearson-DDTW/SVC cần được kiểm tra thêm từ toàn văn trước khi trích dẫn như kết luận của tác giả.

## 8. Relevance to IOT102 G2 – Liên hệ dự án

Dự án G2 sử dụng:

- ESP32 DevKit.
    
- LM35 Temperature Sensor.
    
- MQ-2 Smoke/Gas Sensor.
    
- Flame Sensor.
    
- Logic SAFE / WARNING / DANGER.
    
- LED, buzzer, LCD1602 và Servo SG90.
    

### 8.1. Điểm tương đồng

Cả hai đều hướng đến phát hiện nguy hiểm từ nhiều nguồn tín hiệu và cảnh báo sớm.

Nghiên cứu cung cấp cơ sở để thảo luận tại sao hệ thống phát hiện cháy cần quan tâm đến cảnh báo nhầm.

### 8.2. Điểm khác biệt

|Tiêu chí|Nghiên cứu Yu et al.|Dự án G2|
|---|---|---|
|Phương pháp|Pearson-DDTW + SVC|Rule-based threshold|
|Tín hiệu|Phân tích chuỗi tín hiệu|LM35 analog, MQ-2/Flame digital|
|Phát hiện nguy hiểm|Phân loại theo tương quan|Logic OR|
|Ngưỡng|Xác định từ dữ liệu huấn luyện|WARNING 40°C, DANGER 43°C|
|Mục tiêu|Phân biệt cháy và nguồn nhiễu bằng phân tích tín hiệu|Prototype cảnh báo đơn giản, xử lý tại ESP32|

### 8.3. Hạn chế liên quan của firmware G2

Điều kiện DANGER:

```
bool danger = flameDetected ||
              smokeDetected ||
              temperature >= TEMP_DANGER;
```

Chỉ cần một trong ba điều kiện đúng là hệ thống chuyển sang DANGER.

Vì vậy, hệ thống có khả năng phản ứng với tín hiệu nguy hiểm từ một cảm biến riêng lẻ, nhưng cũng có nguy cơ cảnh báo nhầm nếu tín hiệu đó xuất phát từ nguồn nhiễu.

Đây là nhận xét suy luận từ thuật toán G2, **không phải kết quả kiểm thử false alarm đã được đo**.

## 9. Application in Final Report – Cách sử dụng

**Introduction:** Giải thích nhu cầu phát hiện cháy sớm và vấn đề false alarms.

**Related Work:** Giới thiệu hướng tiếp cận dựa trên sự tương đồng tín hiệu nhiều đầu dò, sau đó so sánh với phương pháp ngưỡng cố định của G2.

**Discussion:** Phân tích trade-off giữa thuật toán đơn giản, dễ triển khai và khả năng phân biệt nguồn nhiễu.

**Future Work:** Đề xuất nghiên cứu sensor fusion, adaptive thresholds và phân tích tín hiệu theo thời gian.

Không tuyên bố G2 đã áp dụng Pearson-DDTW hoặc SVC.

## 10. Suggested Research Direction

Một hướng nghiên cứu có thể xem xét trong tương lai:

**Context-Aware Fire Warning with Reduced False Alarms**

Nghiên cứu điều chỉnh cấu hình cảnh báo theo bối cảnh hoạt động, chẳng hạn sinh hoạt có khói, đồng thời giữ các điều kiện cảnh báo nguy hiểm quan trọng.

Việc tích hợp Blynk và chỉnh ngưỡng từ ứng dụng là **ý tưởng mở rộng của G2**, không phải chức năng đã được bài báo này chứng minh hoặc firmware hiện tại triển khai.

Cần có thí nghiệm kiểm chứng trước khi kết luận việc chỉnh ngưỡng giúp giảm cảnh báo nhầm mà không tăng nguy cơ bỏ sót cháy.

## 11. Reference – IEEE / BibTeX

```
@article{yu2023multidetector,
  author  = {M. Yu and H. Yuan and K. Li and J. Wang},
  title   = {Research on multi-detector real-time fire
             alarm technology based on signal similarity},
  journal = {Fire Safety Journal},
  volume  = {136},
  pages   = {103724},
  year    = {2023},
  doi     = {10.1016/j.firesaf.2022.103724}
}
```

**Citation key:** `yu2023multidetector`

**Source status:** Đã đọc nội dung preview/abstract và các đoạn trích được cung cấp; chưa kiểm chứng toàn văn.

**Recommendation:** Phù hợp để sử dụng trong Introduction, Related Work và Discussion của Final Report IOT102 G2.

# PAPER 02 – Multisensor Integration in Early Fire and Gas Detection Based on Artificial Neural Network

## 1. Thông tin bài báo

- **Title:** Multisensor Integration in Early Fire and Gas Detection Based on Artificial Neural Network
    
- **Authors:** Khoirudin Fathoni, Alfa Faridh Suni, Nur Iksan, Mohammad Sofyan Aziz
    
- **Journal:** Edu Komputika Journal
    
- **Volume / Issue:** 12(2)
    
- **Pages:** 157–167
    
- **Publication Date:** December 31, 2025
    
- **DOI:** [https://doi.org/10.15294/edukom.v12i2.27436](https://doi.org/10.15294/edukom.v12i2.27436)
    
- **Source:** Universitas Negeri Semarang (UNNES)
    
- **Keywords:** Artificial Neural Network, False Alarm, Fire Detection, Hazardous Gases
    
- **Available Material:** Abstract, metadata và danh sách References do người dùng cung cấp; chưa phân tích toàn văn PDF.
    

## 2. Research Problem – Vấn đề nghiên cứu

Các hệ thống phát hiện cháy truyền thống thường dựa trên một biến đơn lẻ như khói hoặc ngọn lửa.

Phương pháp phát hiện dựa trên một cảm biến hoặc ngưỡng cố định có nguy cơ tạo ra cảnh báo nhầm (_false alarms_), đặc biệt khi môi trường tồn tại những tác nhân gây nhiễu.

Nghiên cứu tập trung vào hai vấn đề:

1. Giảm cảnh báo nhầm trong quá trình phát hiện cháy sớm.
    
2. Kết hợp nhiều thông tin môi trường để xác định tình trạng cháy và khí nguy hiểm thay vì chỉ dựa trên một cảm biến.
    

## 3. Research Objectives – Mục tiêu nghiên cứu

Nghiên cứu đề xuất một hệ thống phát hiện cháy và khí nguy hiểm sử dụng nhiều cảm biến kết hợp với **Artificial Neural Network (ANN)**.

Mục tiêu là cải thiện khả năng phân loại tình trạng cháy, giảm cảnh báo nhầm và cung cấp cảnh báo sớm dựa trên nhiều đặc trưng môi trường.

## 4. Proposed Methodology – Phương pháp

### 4.1. Multisensor Integration

Hệ thống tích hợp các cảm biến:

|Thành phần|Vai trò|
|---|---|
|IR Flame Sensor|Phát hiện tín hiệu ngọn lửa|
|MQ-9|Cảm biến khí|
|MQ-2|Cảm biến khí/khói|
|MQ-4|Cảm biến khí|
|DHT-11|Đo nhiệt độ và độ ẩm|
|Raspberry Pi 3|Xử lý dữ liệu và chạy mô hình ANN|

Việc kết hợp dữ liệu từ nhiều cảm biến cho phép hệ thống xem xét đồng thời các dấu hiệu liên quan đến cháy.

### 4.2. Artificial Neural Network – RBFN

Nghiên cứu sử dụng **Radial Basis Function Network (RBFN)**, một kiến trúc mạng nơ-ron nhân tạo.

Thay vì kiểm tra một điều kiện đơn lẻ, mô hình ANN xử lý dữ liệu từ nhiều cảm biến để xác định tình trạng cháy.

Đặc điểm chính theo Abstract:

- Dữ liệu cảm biến được sử dụng để huấn luyện mô hình.
    
- Mô hình RBFN được triển khai trên Raspberry Pi 3.
    
- Kết quả xử lý được sử dụng để đưa ra quyết định cảnh báo.
    

Chi tiết về kiến trúc mạng, số neuron, hàm kích hoạt, dữ liệu đầu vào và quá trình huấn luyện chưa được cung cấp trong Abstract.

### 4.3. Quy trình tổng quát

1. Thu thập tín hiệu từ Flame Sensor, các cảm biến khí và DHT-11.
    
2. Kết hợp dữ liệu cảm biến thành đầu vào cho mô hình.
    
3. Sử dụng RBFN đã huấn luyện để phân loại tình trạng cháy.
    
4. Đưa ra cảnh báo khi mô hình xác định điều kiện nguy hiểm.
    

## 5. Experimental Setup – Thiết lập thí nghiệm

Theo Abstract, nhóm tác giả đã xây dựng và thử nghiệm hệ thống phát hiện cháy sử dụng RBFN.

Thông tin xác nhận được:

- Phần cứng xử lý: Raspberry Pi 3.
    
- Các cảm biến: IR Flame, MQ-9, MQ-2, MQ-4 và DHT-11.
    
- Thuật toán: ANN với kiến trúc RBFN.
    
- Mục tiêu đánh giá: cảnh báo nhầm và thời gian phản hồi.
    

**Thông tin chưa có trong tài liệu được cung cấp:**

- Số lượng mẫu huấn luyện và kiểm thử.
    
- Số lần thử nghiệm.
    
- Cách tạo các tình huống cháy và nguồn gây nhiễu.
    
- Phương pháp chia tập dữ liệu.
    
- Confusion matrix và điều kiện đo thời gian phản hồi.
    

Cần đọc toàn văn PDF trước khi phân tích các chi tiết trên.

## 6. Results and Findings – Kết quả nghiên cứu

Theo Abstract, nghiên cứu báo cáo:

|Chỉ số|Kết quả được công bố|
|---|---|
|False alarms|Không ghi nhận cảnh báo nhầm trong các thử nghiệm được báo cáo|
|Response time|2,1 giây|
|Detection method|RBFN-based ANN|
|Processing hardware|Raspberry Pi 3|

**Diễn giải quan trọng:**

- Kết quả không ghi nhận false alarm chỉ áp dụng cho các thử nghiệm được nhóm tác giả báo cáo.
    
- Không có nghĩa hệ thống bảo đảm 0% false alarm trong mọi môi trường.
    
- Response time 2,1 giây được mô tả là khoảng thời gian từ khi nguồn cháy bắt đầu đến khi phát cảnh báo.
    
- Không được xem 2,1 giây là tốc độ phản hồi của ESP32 G2.
    

Abstract không cung cấp đủ dữ liệu để kết luận accuracy, precision, recall hoặc F1-score cụ thể.

## 7. Limitations – Những giới hạn cần lưu ý

Từ phạm vi thông tin đang có, có thể xác định:

- Mô hình RBFN yêu cầu dữ liệu để huấn luyện.
    
- Hệ thống sử dụng Raspberry Pi 3, khác với nền tảng ESP32 của G2.
    
- Chưa có thông tin đầy đủ về mức độ đa dạng của dữ liệu kiểm thử.
    
- Chưa biết kết quả có duy trì khi áp dụng trong các môi trường khác hay không.
    
- Chưa đủ thông tin để đánh giá độ phức tạp tính toán và tài nguyên phần cứng của mô hình.
    

Đây là các giới hạn khi **đánh giá nghiên cứu từ Abstract**, không phải tất cả đều là hạn chế mà tác giả đã tự xác nhận.

## 8. Relevance to IOT102 G2 – Liên hệ dự án

Dự án G2 sử dụng ESP32 với ba cảm biến:

- LM35 Temperature Sensor.
    
- MQ-2 Smoke/Gas Sensor.
    
- Flame Sensor.
    

Firmware nhóm sử dụng thuật toán điều kiện để xác định `SAFE`, `WARNING` và `DANGER`.

### 8.1. Điểm tương đồng

- Cùng hướng đến phát hiện nguy hiểm liên quan đến cháy.
    
- Cùng sử dụng Flame Sensor và MQ-2.
    
- Cùng kết hợp nhiều thông tin cảm biến.
    
- Cùng quan tâm đến khả năng cảnh báo sớm.
    

### 8.2. Điểm khác biệt

|Tiêu chí|Fathoni et al. (2025)|IOT102 G2|
|---|---|---|
|Controller|Raspberry Pi 3|ESP32 DevKit|
|Temperature Sensor|DHT-11|LM35|
|Gas Sensors|MQ-9, MQ-2, MQ-4|MQ-2|
|Flame Sensor|IR Flame Sensor|Flame Sensor|
|Thuật toán|ANN – RBFN|Rule-based threshold|
|Dữ liệu xử lý|Nhiều đặc trưng cảm biến|Nhiệt độ + trạng thái DO|
|Mục tiêu giảm false alarm|Trọng tâm nghiên cứu|Chưa đánh giá định lượng|
|Điều khiển đầu ra G2|Không đủ thông tin từ Abstract để so sánh|LED, LCD, buzzer, Servo|

### 8.3. Hạn chế của thuật toán G2

Theo firmware đã chốt:

```
bool danger = flameDetected ||
              smokeDetected ||
              temperature >= TEMP_DANGER;
```

Với ngưỡng:

- WARNING: 40°C.
    
- DANGER: 43°C.
    

Logic OR giúp hệ thống phản hồi khi có ít nhất một dấu hiệu nguy hiểm.

Tuy nhiên, nếu một cảm biến kích hoạt do nguồn gây nhiễu, hệ thống cũng có thể chuyển sang DANGER.

Đây là một nguy cơ xuất phát từ thiết kế thuật toán, chưa phải tỷ lệ false alarm đã được đo trong thí nghiệm G2.

### 8.4. Trade-off

**RBFN-based ANN:**

- Có khả năng học mối quan hệ giữa nhiều đầu vào.
    
- Cần dữ liệu huấn luyện và quy trình đánh giá.
    
- Phức tạp hơn về phát triển và vận hành.
    

**Rule-based threshold của G2:**

- Đơn giản, dễ giải thích.
    
- Phù hợp để triển khai prototype nhỏ trên ESP32.
    
- Không cần huấn luyện mô hình.
    
- Hạn chế khả năng phân biệt giữa sự kiện cháy và nguồn nhiễu nếu cùng kích hoạt cảm biến.
    

Không thể kết luận một phương pháp luôn chính xác hơn phương pháp kia nếu chưa có thử nghiệm so sánh trong cùng điều kiện.

## 9. Application in Final Report – Cách sử dụng

### Introduction

Trích dẫn nghiên cứu để làm rõ vấn đề cảnh báo nhầm ở những hệ thống phát hiện cháy dựa trên một cảm biến hoặc một ngưỡng đơn giản.

### Related Work

Giới thiệu hướng tiếp cận multisensor + ANN/RBFN nhằm phân loại nguy hiểm dựa trên nhiều đặc trưng môi trường.

### Discussion

So sánh giữa tính đơn giản của thuật toán G2 và phương pháp học máy yêu cầu dữ liệu huấn luyện.

### Future Work

Đề xuất nghiên cứu sensor fusion hoặc mô hình phân loại thích ứng để cải thiện khả năng phân biệt sự kiện cháy với nguồn gây nhiễu.

Không tuyên bố dự án G2 đã triển khai ANN/RBFN.

## 10. Suggested Research Direction

**Reducing False Alarms in Low-Cost Multisensor Fire Detection Systems**

Hướng nghiên cứu đề xuất là đánh giá khả năng giảm cảnh báo nhầm khi chuyển từ một điều kiện OR đơn giản sang các phương pháp kết hợp tín hiệu hoặc phân loại theo bối cảnh.

Một số hướng có thể thử nghiệm trong tương lai:

- Kết hợp nhiều điều kiện trước khi đưa ra mức cảnh báo không khẩn cấp.
    
- Sử dụng tín hiệu analog MQ-2 đã được hiệu chuẩn nếu phần cứng cho phép.
    
- Thu thập dữ liệu để phân biệt nguồn khói sinh hoạt với tín hiệu nguy hiểm.
    
- Thiết kế cấu hình ngưỡng qua Blynk trong giới hạn an toàn.
    

**Lưu ý:** Blynk chưa được triển khai trong source G2 hiện tại. Việc thay đổi ngưỡng không được phép khiến hệ thống bỏ qua những dấu hiệu nguy hiểm nghiêm trọng.

## 11. Reference – IEEE / BibTeX

```
@article{fathoni2025multisensor,
  author  = {Khoirudin Fathoni and Alfa Faridh Suni
             and Nur Iksan and Mohammad Sofyan Aziz},
  title   = {Multisensor Integration in Early Fire
             and Gas Detection Based on Artificial
             Neural Network},
  journal = {Edu Komputika Journal},
  volume  = {12},
  number  = {2},
  pages   = {157--167},
  year    = {2025},
  doi     = {10.15294/edukom.v12i2.27436}
}
```

**Citation key:** `fathoni2025multisensor`

**Source status:** Đã tổng hợp từ Abstract, metadata và References do người dùng cung cấp; chưa phân tích toàn văn PDF.

**Recommendation:** Phù hợp cho Introduction, Related Work, Discussion và Future Work của báo cáo IOT102 G2.

**Lưu ý trích dẫn:** Các bài nằm trong phần References của Fathoni et al. không tự động trở thành những bài G2 đã đọc. Nếu muốn dùng chúng làm nguồn trực tiếp, cần kiểm tra nội dung từng bài trước.


# PAPER 03 – Smart Safety Room: ESP32 Decision Tree-Based Multi-Hazard Detection System

## 1. Thông tin bài báo

- **Title:** Smart Safety Room: ESP32 Decision Tree-Based Multi-Hazard Detection System
    
- **Authors:** Jogi Purba, Dedy Kiswanto, John Bush Henrydunan, Revidamurti Dly
    
- **Journal:** Journal of Artificial Intelligence and Engineering Applications (JAIEA)
    
- **Volume / Issue:** 5(2)
    
- **Pages:** 2627–2637
    
- **Publication Date:** February 15, 2026
    
- **DOI:** [https://doi.org/10.59934/jaiea.v5i2.1947](https://doi.org/10.59934/jaiea.v5i2.1947)
    
- **Keywords:** IoT, Smart Safety, ESP32, Multi-Sensor, Decision Tree, Fire Detection, Gas Detection, Intrusion Detection, Real-Time Monitoring
    
- **Available Material:** Abstract, metadata và References do người dùng cung cấp; chưa phân tích toàn văn PDF.
    

## 2. Research Problem – Vấn đề nghiên cứu

An toàn trong các khu vực như nhà ở, phòng làm việc và phòng máy chủ là một vấn đề quan trọng.

Các hệ thống an ninh và cảnh báo truyền thống thường dựa trên một cảm biến riêng lẻ hoặc chỉ đưa ra cảnh báo thụ động. Điều này hạn chế khả năng xử lý khi nhiều mối nguy hiểm xuất hiện đồng thời.

Nghiên cứu tập trung giải quyết ba vấn đề:

1. Phát hiện nhiều loại nguy hiểm trong cùng một hệ thống.
    
2. Phân loại mức độ nguy hiểm để đưa ra cảnh báo phù hợp.
    
3. Cung cấp khả năng giám sát trạng thái cảm biến thông qua dashboard thời gian thực.
    

## 3. Research Objectives – Mục tiêu nghiên cứu

Nghiên cứu đề xuất một hệ thống **Smart Safety Room** sử dụng ESP32 kết hợp nhiều cảm biến.

Hệ thống hướng đến việc phát hiện các tình huống liên quan đến cháy, khí và xâm nhập, sau đó phân loại trạng thái phòng thành:

- **SAFE:** Không phát hiện mối nguy hiểm theo điều kiện hệ thống.
    
- **ALERT:** Trạng thái cần chú ý.
    
- **DANGER:** Phát hiện tình huống nguy hiểm.
    

Mục tiêu là xây dựng giải pháp giám sát an toàn tích hợp, có khả năng phản hồi nhanh và hỗ trợ quan sát từ xa.

## 4. Proposed Methodology – Phương pháp

### 4.1. ESP32-Based Multisensor System

Hệ thống tích hợp các thành phần:

|Thành phần|Vai trò|
|---|---|
|ESP32|Bộ điều khiển trung tâm|
|MQ-2 Gas Sensor|Phát hiện tín hiệu khí/khói|
|Flame Sensor|Phát hiện ngọn lửa|
|PIR Sensor|Phát hiện chuyển động phục vụ giám sát xâm nhập|
|OLED Display|Hiển thị thông tin tại thiết bị|
|RGB LED|Biểu thị trạng thái|
|Buzzer|Cảnh báo bằng âm thanh|
|Web Dashboard|Giám sát trạng thái cảm biến qua giao diện web|

ESP32 tiếp nhận tín hiệu từ các cảm biến, thực hiện phân loại và điều khiển thiết bị đầu ra.

### 4.2. Decision Tree Classification

Nghiên cứu sử dụng thuật toán **Decision Tree** với cơ chế phân loại theo thứ tự ưu tiên.

Thay vì xử lý các cảm biến như những cảnh báo hoàn toàn độc lập, hệ thống kết hợp trạng thái đầu vào để quyết định mức cảnh báo.

Ba nhóm trạng thái đầu ra là SAFE, ALERT và DANGER.

Theo Abstract, thuật toán sử dụng các mức ưu tiên phân cấp (_hierarchical priorities_). Tuy nhiên, chưa có đủ thông tin để xác định chính xác các nhánh điều kiện, quy tắc ưu tiên và cấu trúc cây quyết định mà tác giả triển khai.

Do đó, không tự dựng lại decision tree của nghiên cứu khi chưa đọc toàn văn.

### 4.3. Real-Time Monitoring

Nghiên cứu tích hợp một web dashboard để hiển thị trạng thái hệ thống.

Theo Abstract:

- Dashboard cập nhật tự động mỗi 1 giây.
    
- Trạng thái cảm biến được hiển thị qua giao diện web.
    
- Nhóm tác giả đánh giá tỷ lệ mất dữ liệu trong quá trình vận hành liên tục.
    

### 4.4. Quy trình tổng quát

1. Các cảm biến thu thập tín hiệu môi trường.
    
2. ESP32 tiếp nhận dữ liệu từ các cảm biến.
    
3. Thuật toán Decision Tree phân loại mức độ nguy hiểm.
    
4. Hệ thống điều khiển LED, buzzer và màn hình.
    
5. Trạng thái cảm biến được hiển thị trên web dashboard.
    
6. Quá trình đọc và cập nhật được thực hiện liên tục.
    

## 5. Experimental Setup – Thiết lập thí nghiệm

Theo Abstract, nghiên cứu được thử nghiệm với bốn tình huống chính.

|Scenario|Nội dung|
|---|---|
|Normal Condition|Điều kiện bình thường|
|Fire Detection|Phát hiện cháy|
|Intrusion Detection|Phát hiện xâm nhập|
|Dual Threat|Hai mối nguy hiểm xuất hiện đồng thời|

Nghiên cứu đánh giá hiệu quả phân loại, hiệu suất cảm biến, thời gian phản hồi và khả năng truyền dữ liệu đến dashboard.

**Những thông tin chưa có trong Abstract:**

- Tổng số mẫu kiểm thử.
    
- Số lần lặp cho từng scenario.
    
- Ma trận nhầm lẫn (_confusion matrix_).
    
- Cách xác định nhãn đúng của dữ liệu.
    
- Điều kiện môi trường và khoảng cách cảm biến.
    
- Phương pháp đo thời gian phản hồi.
    
- Thời lượng thử nghiệm liên tục của dashboard.
    

Cần đọc toàn văn trước khi đánh giá chi tiết phương pháp thực nghiệm.

## 6. Results and Findings – Kết quả nghiên cứu

Các kết quả được tác giả công bố trong Abstract:

|Metric|Kết quả|
|---|---|
|Overall Accuracy|96,5%|
|Fire Sensor Performance|96%|
|Gas Sensor Performance|94%|
|PIR Sensor Performance|98%|
|Average Response Time|Dưới 300 ms|
|F1-Score|95–97% tùy nhóm phân loại|
|Dashboard Auto-refresh|Mỗi 1 giây|
|Data Loss Rate|0,8% trong thử nghiệm vận hành liên tục|

### 6.1. Detection Performance

Nghiên cứu báo cáo overall accuracy đạt 96,5%.

Các chỉ số thành phần được công bố gồm 96% cho cảm biến lửa, 94% cho cảm biến khí và 98% cho PIR.

Các con số này phản ánh kết quả thử nghiệm do tác giả báo cáo. Abstract chưa giải thích cụ thể cách tính từng chỉ số thành phần.

### 6.2. Response Time

Thời gian phản hồi trung bình được báo cáo là dưới 300 ms đối với các loại phát hiện được thử nghiệm.

Đây là một kết quả quan trọng vì hệ thống cảnh báo cần xử lý và đưa ra tín hiệu kịp thời.

Tuy nhiên, chưa rõ mốc bắt đầu và kết thúc phép đo được xác định như thế nào.

### 6.3. Classification Performance

F1-score được báo cáo trong khoảng 95–97% cho các nhóm phân loại.

Kết quả cho thấy nghiên cứu có đánh giá khả năng phân loại theo nhiều tiêu chí thay vì chỉ báo cáo overall accuracy.

### 6.4. Dashboard Performance

Dashboard tự động cập nhật mỗi giây, với data loss rate được báo cáo là 0,8%.

Kết quả này cho thấy nhóm tác giả không chỉ kiểm tra phần phát hiện nguy hiểm mà còn đánh giá khả năng giám sát và truyền dữ liệu.

**Lưu ý:** Tất cả các số liệu trên thuộc bài nghiên cứu Purba et al. (2026), không phải kết quả thực nghiệm của IOT102 G2. Chưa đủ thông tin để so sánh trực tiếp hiệu năng giữa hai hệ thống.

## 7. Limitations – Những giới hạn cần lưu ý

Từ Abstract và phạm vi nghiên cứu, có thể xác định một số điểm cần làm rõ:

- Hệ thống tập trung vào nhiều loại nguy hiểm, không chỉ riêng phát hiện cháy.
    
- Chưa rõ cách Decision Tree xử lý khi tín hiệu các cảm biến mâu thuẫn.
    
- Chưa đủ thông tin về quy mô và mức độ đa dạng của dữ liệu thử nghiệm.
    
- Chưa rõ việc kiểm thử có bao gồm khói nấu ăn, hơi nước hoặc những nguồn gây nhiễu sinh hoạt hay không.
    
- Chưa có đủ thông tin để đánh giá sự ổn định của cảm biến khi vận hành trong thời gian dài.
    
- Chưa rõ có cơ chế cấu hình ngưỡng từ xa hay không.
    

Đây là những giới hạn của việc **đánh giá từ Abstract**, không phải tất cả đều là hạn chế được nhóm tác giả thừa nhận.

## 8. Relevance to IOT102 G2 – Liên hệ dự án

### 8.1. Điểm tương đồng

Nghiên cứu này gần với dự án G2 hơn về kiến trúc phần cứng so với Paper 01 và Paper 02.

Cả hai hệ thống đều:

- Sử dụng ESP32 làm bộ điều khiển.
    
- Sử dụng MQ-2 và Flame Sensor.
    
- Phân loại trạng thái thành ba mức.
    
- Điều khiển LED và buzzer để cảnh báo.
    
- Sử dụng thuật toán dựa trên các điều kiện cảm biến.
    

Cả hai cũng hướng đến một mô hình chi phí thấp, phù hợp nghiên cứu và triển khai prototype.

### 8.2. Điểm khác biệt

|Tiêu chí|Purba et al. (2026)|IOT102 G2|
|---|---|---|
|Controller|ESP32|ESP32|
|Flame Sensor|Có|Có|
|MQ-2|Có|Có|
|Temperature Sensor|Không được nêu trong Abstract|LM35|
|PIR Sensor|Có|Không|
|Display|OLED|LCD1602 I²C|
|LED|RGB LED|Ba LED riêng biệt|
|Buzzer|Có|Một buzzer GPIO15|
|Thuật toán|Decision Tree phân cấp|Rule-based OR và threshold|
|Trạng thái|SAFE / ALERT / DANGER|SAFE / WARNING / DANGER|
|Servo Door|Không được nêu trong Abstract|SG90, 0°/90°|
|Web Dashboard|Đã được tác giả báo cáo triển khai|Chưa có trong firmware G2|
|Kết quả định lượng|Có metrics được công bố|Chưa có số liệu định lượng được lưu|

### 8.3. So sánh thuật toán

Firmware G2 sử dụng:

```
bool danger = flameDetected ||
              smokeDetected ||
              temperature >= TEMP_DANGER;
```

Với:

- `TEMP_WARNING = 40.0`
    
- `TEMP_DANGER = 43.0`
    

Quy tắc phân loại:

1. Nếu phát hiện lửa, khói/khí hoặc nhiệt độ từ 43°C trở lên → DANGER.
    
2. Nếu không DANGER nhưng nhiệt độ từ 40°C trở lên → WARNING.
    
3. Nếu không thuộc hai điều kiện trên → SAFE.
    

Cách tiếp cận này có thể xem là một **rule-based decision logic** có thứ tự ưu tiên.

Tuy nhiên, không nên gọi thuật toán G2 là Decision Tree đã được huấn luyện hoặc tối ưu bằng dữ liệu. Các điều kiện của G2 được lập trình thủ công.

### 8.4. Trade-off

**Phương pháp Decision Tree của nghiên cứu:**

- Tổ chức nhiều điều kiện và mức ưu tiên.
    
- Có thể xử lý nhiều loại nguy hiểm trong một hệ thống.
    
- Được tác giả đánh giá bằng các chỉ số định lượng.
    
- Chưa có đủ chi tiết để xác định độ phức tạp thuật toán thực tế.
    

**Phương pháp Rule-based của G2:**

- Dễ triển khai và giải thích.
    
- Không yêu cầu tập dữ liệu huấn luyện.
    
- Phù hợp với ESP32 và phạm vi đồ án IOT102.
    
- Có thể phản hồi với một dấu hiệu nguy hiểm riêng lẻ.
    
- Có nguy cơ báo nhầm nếu một cảm biến bị kích hoạt bởi nguồn gây nhiễu.
    

Không được kết luận Decision Tree luôn chính xác hoặc nhanh hơn logic G2 vì hai hệ thống chưa được kiểm thử trong cùng điều kiện.

## 9. Application in Final Report – Cách sử dụng

### Introduction

Sử dụng nghiên cứu để giới thiệu nhu cầu xây dựng hệ thống cảnh báo an toàn tích hợp dựa trên ESP32 và nhiều cảm biến.

### Related Work

Đây là một nguồn tham khảo trực tiếp để trình bày phương pháp phân loại trạng thái theo mức độ nguy hiểm.

Có thể mô tả:

Purba et al. (2026) proposed an ESP32-based multi-hazard monitoring system integrating gas, flame, and motion sensors. A hierarchical decision-tree approach was employed to classify environmental conditions into SAFE, ALERT, and DANGER states.

### System Design

Sử dụng làm cơ sở tham khảo cho việc tổ chức hệ thống thành ba nhóm:

- Sensor Inputs.
    
- ESP32 Decision Processing.
    
- Warning Outputs.
    

Không sử dụng sơ đồ hoặc thuật toán chi tiết của tác giả như thể đó là thiết kế của G2.

### Results and Discussion

Có thể đối chiếu các loại metrics được nghiên cứu sử dụng:

- Detection accuracy.
    
- Response time.
    
- F1-score.
    
- Data loss rate.
    

Tuy nhiên, G2 chỉ nên so sánh bằng những chỉ số đã tự đo và có phương pháp tương ứng.

### Future Work

Nghiên cứu là cơ sở tham khảo cho việc phát triển:

- Phân loại tình huống nguy hiểm phức tạp hơn.
    
- Kết hợp thêm cảm biến.
    
- Hệ thống giám sát từ xa.
    
- Đánh giá response time và false alarms bằng dữ liệu.
    
- Cấu hình cảnh báo theo điều kiện sử dụng, nếu được thử nghiệm và bảo đảm an toàn.
    

## 10. Suggested Research Direction

**Rule-Based and Hierarchical Multi-Sensor Fire Detection on ESP32**

Một hướng nghiên cứu phù hợp là đánh giá hiệu quả của logic phân cấp theo mức độ nguy hiểm trên ESP32.

Các câu hỏi có thể xem xét:

1. Hệ thống có phân loại đúng SAFE, WARNING và DANGER trong các tình huống kiểm thử đã xác định không?
    
2. Thời gian phản hồi khi một hoặc nhiều cảm biến kích hoạt là bao nhiêu?
    
3. Khi đồng thời xuất hiện tín hiệu lửa và khói, hệ thống có duy trì trạng thái DANGER nhất quán không?
    
4. Việc bổ sung các điều kiện xác nhận có giúp giảm cảnh báo nhầm mà không tăng nguy cơ bỏ sót cháy không?
    

Với G2, nhóm đã xác nhận 8 functional test cases đạt hành vi mong đợi, nhưng chưa có raw data hoặc phép đo định lượng được lưu.

Vì vậy, không được biến 8/8 functional tests thành accuracy 100% hay sử dụng các chỉ số của Purba et al. làm kết quả của nhóm.

## 11. Reference – IEEE / BibTeX

```
@article{purba2026smartsafety,
  author  = {Jogi Purba and Dedy Kiswanto
             and John Bush Henrydunan and Revidamurti Dly},
  title   = {Smart Safety Room: ESP32 Decision
             Tree-Based Multi-Hazard Detection System},
  journal = {Journal of Artificial Intelligence
             and Engineering Applications},
  volume  = {5},
  number  = {2},
  pages   = {2627--2637},
  year    = {2026},
  doi     = {10.59934/jaiea.v5i2.1947}
}
```

**Citation key:** `purba2026smartsafety`

**Source status:** Đã tổng hợp từ Abstract, metadata và References do người dùng cung cấp; chưa phân tích toàn văn PDF.

**Recommendation:** Rất phù hợp cho Introduction, Related Work, System Design và Discussion của IOT102 G2.

Các metrics công bố nên được kiểm tra thêm trong toàn văn trước khi phân tích sâu hoặc đối chiếu định lượng với các nghiên cứu khác.

# PAPER 04 – IoT-Based Early Fire Detection System Using Flame and Gas Sensors with Telegram Bot and Blynk Dashboard Integration

## 1. Thông tin bài báo

- **Title:** IoT-Based Early Fire Detection System using Flame and Gas Sensors with Telegram Bot and Blynk Dashboard Integration
    
- **Author:** Novi Ramadani
    
- **Journal:** Journal of Artificial Intelligence and Engineering Applications (JAIEA)
    
- **Volume / Issue:** 6(1)
    
- **Pages:** 603–612
    
- **Publication Date:** October 15, 2026
    
- **DOI:** [https://doi.org/10.59934/jaiea.v6i1.2805](https://doi.org/10.59934/jaiea.v6i1.2805)
    
- **Keywords:** Blynk, ESP32, Fire Detection, Internet of Things, MQ-2 Sensor, Telegram Bot
    
- **Available Material:** Abstract, metadata và References do người dùng cung cấp; chưa phân tích toàn văn PDF.
    

## 2. Research Problem – Vấn đề nghiên cứu

Các vụ cháy có thể gây thiệt hại nghiêm trọng về người và tài sản, đặc biệt khi việc phát hiện và phản ứng bị chậm trễ.

Những hệ thống báo cháy thông thường chủ yếu cung cấp cảnh báo tại chỗ, khiến người dùng khó theo dõi tình trạng nguy hiểm khi không có mặt tại khu vực lắp đặt.

Nghiên cứu tập trung vào ba vấn đề:

1. Phát hiện sớm dấu hiệu cháy và khí dễ cháy.
    
2. Hỗ trợ giám sát, nhận thông báo nguy hiểm từ xa thông qua Internet.
    
3. Tự động kích hoạt phản ứng chữa cháy ban đầu khi điều kiện được xác định là nguy hiểm.
    

## 3. Research Objectives – Mục tiêu nghiên cứu

Nghiên cứu đề xuất một hệ thống phát hiện cháy sớm dựa trên **Internet of Things (IoT)** sử dụng ESP32.

Hệ thống hướng đến:

- Phát hiện ngọn lửa và khí dễ cháy bằng cảm biến.
    
- Gửi trạng thái hệ thống đến Blynk để giám sát từ xa.
    
- Sử dụng Telegram Bot để tự động thông báo tình huống khẩn cấp.
    
- Kích hoạt còi báo động tại chỗ.
    
- Điều khiển máy bơm nước qua relay nhằm hỗ trợ dập cháy ban đầu.
    

Mục tiêu ứng dụng là các khu vực nhà ở và không gian trong nhà có quy mô nhỏ.

## 4. Proposed Methodology – Phương pháp

### 4.1. Hardware Architecture

Các thành phần chính được nêu trong Abstract:

|Thành phần|Chức năng|
|---|---|
|ESP32|Xử lý dữ liệu và kết nối Internet|
|KY-026 Flame Sensor|Phát hiện tín hiệu ngọn lửa|
|MQ-2 Gas Sensor|Phát hiện tín hiệu khí dễ cháy|
|Buzzer|Cảnh báo âm thanh tại chỗ|
|Relay Module|Điều khiển máy bơm|
|Water Pump / Sprinkler|Phản ứng dập cháy ban đầu|
|Blynk Dashboard|Giám sát từ xa|
|Telegram Bot|Gửi thông báo khẩn cấp|

### 4.2. Sensor Calibration and Thresholds

Nghiên cứu thực hiện hiệu chuẩn cảm biến để xác định các ngưỡng phát hiện phù hợp.

Theo Abstract:

|Sensor|Ngưỡng được báo cáo|
|---|---|
|Flame Sensor|Giá trị ADC dưới 2000|
|MQ-2 Gas Sensor|Giá trị ADC trên 500|

Hai ngưỡng này là cấu hình được báo cáo trong nghiên cứu, không phải ngưỡng chuẩn có thể áp dụng cho mọi module.

Đặc biệt, chúng không thể áp dụng trực tiếp vào firmware G2 hiện tại vì nhóm đang đọc MQ-2 và Flame Sensor bằng tín hiệu digital `HIGH/LOW`, không phải giá trị ADC analog.

### 4.3. Blynk Dashboard Integration

Hệ thống tích hợp Blynk nhằm cung cấp khả năng theo dõi trạng thái từ xa.

Người dùng có thể giám sát thông tin của hệ thống thông qua dashboard kết nối Internet.

Abstract không mô tả việc người dùng có thể chỉnh độ nhạy cảm biến hoặc ngưỡng cảnh báo từ Blynk.

Vì vậy, không được sử dụng bài nghiên cứu này để khẳng định tính năng tùy chỉnh ngưỡng đã được tác giả triển khai.

### 4.4. Telegram Bot Notification

Telegram Bot được tích hợp để gửi thông báo khẩn cấp tự động.

Cách tiếp cận này bổ sung cảnh báo từ xa, giúp người dùng nhận thông tin khi không có mặt tại vị trí lắp đặt thiết bị.

### 4.5. Automatic Fire Suppression

Hệ thống điều khiển một máy bơm nước thông qua relay kết nối với sprinkler.

Quy tắc được mô tả:

- Khi phát hiện lửa, buzzer cảnh báo ngay lập tức.
    
- Nếu tín hiệu phát hiện ngọn lửa duy trì liên tục trong 6 giây, hệ thống kích hoạt relay để bật máy bơm nước.
    

Việc xác nhận tín hiệu trong một khoảng thời gian trước khi kích hoạt máy bơm là một phần quan trọng của thiết kế.

Tuy nhiên, cần phân biệt quy tắc kích hoạt máy bơm với quy tắc cảnh báo cháy. Abstract không cung cấp đủ chi tiết để kết luận cách xử lý mọi tình huống tín hiệu nhiễu hoặc gián đoạn.

### 4.6. Quy trình hoạt động tổng quát

1. ESP32 tiếp nhận dữ liệu từ Flame Sensor và MQ-2.
    
2. So sánh dữ liệu với các ngưỡng đã hiệu chuẩn.
    
3. Phát hiện tình trạng liên quan đến ngọn lửa hoặc khí dễ cháy.
    
4. Kích hoạt buzzer để cảnh báo tại chỗ.
    
5. Cập nhật trạng thái lên Blynk.
    
6. Gửi thông báo khẩn cấp qua Telegram Bot.
    
7. Nếu phát hiện ngọn lửa liên tục trong 6 giây, kích hoạt relay và máy bơm nước.
    

Đây là mô hình tổng hợp từ Abstract, chưa phải bản sao flowchart chi tiết của tác giả.

## 5. Experimental Setup – Thiết lập thí nghiệm

Theo tài liệu được cung cấp, nghiên cứu tiến hành kiểm thử các thành phần phần cứng và phần mềm của hệ thống.

Những nội dung được đề cập bao gồm:

- Hoạt động của cảm biến ngọn lửa và khí.
    
- Hiệu chuẩn ngưỡng cảm biến.
    
- Truyền dữ liệu thông qua Internet.
    
- Giám sát thông tin qua Blynk.
    
- Gửi thông báo bằng Telegram.
    
- Cảnh báo bằng buzzer.
    
- Kích hoạt máy bơm và sprinkler khi phát hiện ngọn lửa liên tục.
    

**Thông tin chưa có trong Abstract:**

- Tổng số lần thử nghiệm.
    
- Khoảng cách phát hiện của Flame Sensor.
    
- Điều kiện khí sử dụng khi thử MQ-2.
    
- Response time cụ thể của từng cảm biến.
    
- Độ trễ Blynk và Telegram.
    
- Tỷ lệ cảnh báo nhầm.
    
- Accuracy, Precision, Recall hoặc F1-score.
    
- Lưu lượng nước và hiệu quả dập cháy.
    

Các nội dung này cần được kiểm tra trong toàn văn PDF trước khi phân tích định lượng.

## 6. Results and Findings – Kết quả nghiên cứu

Theo Abstract, tác giả báo cáo các thành phần phần cứng và phần mềm hoạt động đúng thiết kế và giao tiếp thành công qua Internet.

|Nội dung đánh giá|Kết quả được báo cáo|
|---|---|
|Fire Detection|Hệ thống phát hiện tín hiệu cháy|
|Gas Detection|Hệ thống phát hiện tín hiệu khí|
|Local Alarm|Buzzer được kích hoạt|
|Blynk Monitoring|Kết nối và giám sát thành công|
|Telegram Notification|Gửi thông báo khẩn cấp|
|Automatic Suppression|Kích hoạt máy bơm theo điều kiện|
|Network Communication|Các thành phần giao tiếp qua Internet thành công|
|Quantitative Accuracy|Không có số liệu cụ thể trong Abstract|
|Quantitative Response Time|Không có số liệu cụ thể trong Abstract|

Tác giả mô tả hệ thống có khả năng phát hiện sớm và cảnh báo nhanh, nhưng Abstract không cung cấp các chỉ số định lượng để so sánh hiệu năng.

Vì vậy, không được tự suy ra tỷ lệ chính xác hoặc tốc độ truyền thông của hệ thống.

## 7. Limitations – Những giới hạn cần lưu ý

Dựa trên phạm vi thông tin hiện có:

- Hệ thống được mô tả tập trung vào Flame Sensor và MQ-2.
    
- Abstract không đề cập việc tích hợp cảm biến nhiệt độ riêng.
    
- Chưa rõ hiệu quả giảm cảnh báo nhầm từ những nguồn khói sinh hoạt.
    
- Chưa có mô tả tính năng điều chỉnh ngưỡng cảnh báo qua Blynk.
    
- Chưa có số liệu cụ thể về độ trễ thông báo từ xa.
    
- Chưa rõ hoạt động của các tính năng kết nối khi Internet bị gián đoạn.
    
- Chưa có kết quả định lượng về hiệu quả dập cháy của sprinkler.
    

Đây là các thông tin chưa được làm rõ trong Abstract, không mặc nhiên là hạn chế đã được tác giả thừa nhận.

## 8. Relevance to IOT102 G2 – Liên hệ dự án

### 8.1. Điểm tương đồng

Cả nghiên cứu và hệ thống G2 đều sử dụng:

- ESP32 làm bộ điều khiển trung tâm.
    
- MQ-2 để phát hiện tín hiệu khí/khói.
    
- Flame Sensor để phát hiện ngọn lửa.
    
- Buzzer để cảnh báo tại chỗ.
    
- Các quy tắc phát hiện nguy hiểm từ cảm biến.
    

Ngoài ra, cả hai đều phù hợp với định hướng phát triển prototype phát hiện cháy trong nhà.

### 8.2. Điểm khác biệt

|Tiêu chí|Ramadani (2026)|IOT102 G2|
|---|---|---|
|Controller|ESP32|ESP32|
|Flame Sensor|KY-026|Flame Sensor|
|MQ-2|Có|Có|
|Temperature Sensor|Không nêu trong Abstract|LM35|
|Sensor Input|ADC với ngưỡng hiệu chuẩn|Flame/MQ-2 digital|
|Buzzer|Có|Một buzzer GPIO15|
|Display|Không được nêu trong Abstract|LCD1602 I²C|
|Local Status|Không đủ thông tin về LED|Ba LED|
|Remote Monitoring|Blynk|Chưa triển khai|
|Emergency Notifications|Telegram Bot|Chưa triển khai|
|Actuator|Relay + water pump|Servo SG90|
|Automatic Response|Kích hoạt sprinkler|Mở cửa mô hình khi DANGER|
|Alert Levels|Không đủ thông tin từ Abstract|SAFE / WARNING / DANGER|

### 8.3. So sánh detection logic

**Nghiên cứu Ramadani (2026):**

- Đọc dữ liệu ADC từ cảm biến.
    
- So sánh với ngưỡng đã hiệu chuẩn.
    
- Thực hiện cảnh báo.
    
- Kích hoạt máy bơm sau khi tín hiệu ngọn lửa duy trì 6 giây.
    

**Firmware G2:**

```
bool danger = flameDetected ||
              smokeDetected ||
              temperature >= TEMP_DANGER;
```

Cấu hình:

- WARNING: 40°C.
    
- DANGER: 43°C.
    
- Flame Sensor: active LOW.
    
- MQ-2 Sensor: active LOW.
    

Khi DANGER, ESP32 bật LED đỏ, bật buzzer liên tục và mở cửa bằng Servo.

Điểm khác biệt quan trọng là G2 xử lý cảnh báo tại chỗ, còn nghiên cứu Ramadani bổ sung kết nối Internet và phản ứng bằng máy bơm nước.

### 8.4. Trade-off

**Kiến trúc tích hợp Blynk và Telegram:**

- Hỗ trợ giám sát, thông báo từ xa.
    
- Có thể mở rộng chức năng và giao diện người dùng.
    
- Yêu cầu kết nối mạng và các thành phần truyền thông.
    
- Cần kiểm thử thêm độ trễ, tính ổn định và trường hợp mất mạng.
    

**Kiến trúc local của G2:**

- Không phụ thuộc Internet để thực hiện cảnh báo tại chỗ.
    
- Đơn giản hơn trong triển khai và kiểm thử.
    
- Có thể tiếp tục hoạt động khi không có WiFi.
    
- Chưa hỗ trợ giám sát và nhận thông báo trên điện thoại.
    

Hai phương án có thể được kết hợp, trong đó ESP32 duy trì khả năng cảnh báo tại chỗ ngay cả khi kết nối từ xa không khả dụng.

## 9. Application in Final Report – Cách sử dụng

### Introduction

Sử dụng bài báo làm cơ sở giải thích hạn chế của những hệ thống chỉ cảnh báo tại chỗ và nhu cầu giám sát nguy hiểm từ xa.

### Related Work

Giới thiệu hệ thống ESP32 tích hợp Flame Sensor, MQ-2, Blynk và Telegram.

Có thể diễn đạt:

Ramadani (2026) developed an ESP32-based early fire detection system integrating flame and gas sensors with Blynk monitoring and Telegram emergency notifications. A relay-controlled water pump was activated after six seconds of continuous flame detection.

### System Design

Sử dụng nghiên cứu để tham khảo việc phân chia hệ thống thành:

- Sensor Layer.
    
- Processing Layer.
    
- Local Warning Layer.
    
- Communication and Monitoring Layer.
    
- Actuation Layer.
    

Không trình bày tầng Blynk và Telegram như những thành phần đã được triển khai trong firmware G2.

### Discussion

So sánh khả năng hoạt động độc lập của cảnh báo tại chỗ với nhu cầu kết nối Internet để giám sát từ xa.

### Future Work

Đây là nguồn phù hợp nhất trong bốn paper hiện tại để hỗ trợ đề xuất:

- Tích hợp Blynk Dashboard.
    
- Gửi trạng thái cảm biến qua WiFi.
    
- Nhận thông báo cảnh báo từ xa.
    
- Cấu hình chế độ giám sát trên ứng dụng.
    
- Duy trì chức năng cảnh báo tại chỗ khi mất Internet.
    

Lưu ý: Bài báo hỗ trợ ý tưởng tích hợp Blynk để giám sát; không trực tiếp chứng minh tính năng chỉnh ngưỡng từ ứng dụng hoặc hiệu quả giảm false alarms của tính năng đó.

## 10. Suggested Research Direction

**ESP32-Based Fire Detection with Configurable IoT Monitoring and Local Safety Control**

Một hướng phát triển tiếp theo cho G2 là tích hợp ứng dụng quản lý cấu hình và giám sát.

Kiến trúc đề xuất:

1. ESP32 tiếp tục đọc LM35, MQ-2 và Flame Sensor.
    
2. Các quy tắc SAFE/WARNING/DANGER vẫn được xử lý tại ESP32.
    
3. Blynk nhận trạng thái cảm biến và trạng thái cảnh báo.
    
4. Người dùng lựa chọn cấu hình cảnh báo phù hợp trong giới hạn an toàn.
    
5. Các điều kiện nguy hiểm nghiêm trọng vẫn kích hoạt cảnh báo tại chỗ.
    
6. Khi mất kết nối Internet, ESP32 tiếp tục hoạt động độc lập.
    

### Context-Aware Alert Configuration

Ý tưởng của G2 là cho phép người dùng điều chỉnh chế độ cảnh báo khi có những hoạt động sinh hoạt tạo khói, chẳng hạn nấu ăn hoặc đốt nhang.

Tuy nhiên:

- Firmware hiện tại chưa tích hợp Blynk.
    
- Ngưỡng Flame/MQ-2 trong G2 phụ thuộc đầu ra digital của module.
    
- Chỉnh ngưỡng bằng app không đồng nghĩa thay đổi trực tiếp độ nhạy của cảm biến.
    
- Không nên cho phép chế độ tùy chỉnh vô hiệu hóa hoàn toàn cảnh báo cháy.
    
- Cần thực nghiệm để xác định khả năng giảm cảnh báo nhầm và rủi ro bỏ sót nguy hiểm.
    

Đây là định hướng phát triển của G2, không phải kết quả đã được chứng minh trong bài báo Ramadani.

## 11. Reference – IEEE / BibTeX

```
@article{ramadani2026blynk,
  author  = {Novi Ramadani},
  title   = {IoT-Based Early Fire Detection System
             using Flame and Gas Sensors with
             Telegram Bot and Blynk Dashboard
             Integration},
  journal = {Journal of Artificial Intelligence
             and Engineering Applications},
  volume  = {6},
  number  = {1},
  pages   = {603--612},
  year    = {2026},
  doi     = {10.59934/jaiea.v6i1.2805}
}
```

**Citation key:** `ramadani2026blynk`

**Source status:** Tổng hợp từ Abstract, metadata và References do người dùng cung cấp; chưa phân tích toàn văn PDF.

**Recommendation:** Phù hợp cho Introduction, Related Work, Discussion và Future Work. Đặc biệt hữu ích để trình bày định hướng tích hợp Blynk của nhóm G2.

Các kết quả và tính năng chỉ được trích dẫn trong phạm vi Abstract đã xác nhận.

# REFERENCE 05 – ESP32 Analog-to-Digital Converter (ADC) Calibration

## 1. Thông tin tài liệu

- **Title:** Analog to Digital Converter (ADC) Calibration Driver
    
- **Author / Organization:** Espressif Systems
    
- **Documentation:** ESP-IDF Programming Guide
    
- **Platform:** ESP32
    
- **Category:** Official Technical Documentation
    
- **Source:** [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/adc/adc_calibration.html](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/adc/adc_calibration.html)
    
- **Version:** ESP-IDF master/latest tại thời điểm tài liệu được cung cấp.
    
- **Publication Year:** Không xác định cụ thể từ nội dung trang.
    
- **Available Material:** Nội dung tài liệu hướng dẫn ADC Calibration, API Reference và các khuyến nghị giảm nhiễu.
    

**Phân loại:** Technical Reference, không phải Research Paper.

## 2. Technical Problem – Vấn đề kỹ thuật

ESP32 có bộ chuyển đổi tín hiệu analog sang digital, gọi là **Analog-to-Digital Converter (ADC)**.

ADC tiếp nhận điện áp analog từ cảm biến và chuyển thành giá trị digital để chương trình xử lý.

Tuy nhiên, kết quả đo có thể bị sai lệch do điện áp tham chiếu của ADC khác nhau giữa các chip ESP32.

Theo Espressif:

- Điện áp tham chiếu thiết kế của ESP32 là 1100 mV.
    
- Điện áp tham chiếu thực tế có thể nằm trong khoảng 1000–1200 mV giữa các chip khác nhau.
    

Do đó, nếu sử dụng giá trị ADC mà không quan tâm đến hiệu chuẩn, điện áp tính toán có thể không phản ánh chính xác điện áp thực tế.

Ngoài sai lệch điện áp tham chiếu, ADC của ESP32 còn nhạy với nhiễu, làm các kết quả đo dao động.

## 3. Technical Objectives – Mục tiêu tài liệu

Tài liệu hướng dẫn cách sử dụng ADC Calibration Driver nhằm:

1. Giảm ảnh hưởng của sự khác biệt điện áp tham chiếu giữa các chip ESP32.
    
2. Chuyển đổi kết quả ADC thô thành điện áp đã hiệu chuẩn.
    
3. Hướng dẫn khởi tạo và sử dụng các calibration scheme.
    
4. Đưa ra biện pháp hạn chế nhiễu trong phép đo analog.
    

## 4. Technical Methodology – Cơ chế hoạt động

### 4.1. Analog-to-Digital Conversion

ADC chuyển đổi tín hiệu điện áp liên tục thành dữ liệu số.

Trong các hệ thống cảm biến, dữ liệu này được sử dụng để tính toán đại lượng vật lý như nhiệt độ.

Quy trình cơ bản:

1. Cảm biến tạo tín hiệu điện áp analog.
    
2. ADC của ESP32 đọc điện áp.
    
3. Kết quả được chuyển thành giá trị digital.
    
4. Phần mềm sử dụng kết quả ADC để tính toán giá trị cảm biến.
    

Độ chính xác phụ thuộc đặc tính ADC, cấu hình phép đo, điện áp tham chiếu và chất lượng tín hiệu.

### 4.2. ADC Calibration

Hiệu chuẩn ADC nhằm giảm sai lệch khi chuyển đổi từ kết quả số sang điện áp.

Espressif cung cấp ADC Calibration Driver trong ESP-IDF.

Đối với ESP32, tài liệu mô tả **Line Fitting Calibration Scheme**.

Quá trình sử dụng gồm:

1. Xác định calibration scheme được chip hỗ trợ.
    
2. Tạo calibration handle với cấu hình phù hợp.
    
3. Đọc dữ liệu ADC.
    
4. Chuyển kết quả ADC thô sang điện áp đã hiệu chuẩn.
    
5. Giải phóng calibration handle khi không còn sử dụng.
    

### 4.3. Line Fitting Calibration

ESP32 hỗ trợ calibration scheme:

`ADC_CALI_SCHEME_VER_LINE_FITTING`

Cấu hình liên quan đến:

- ADC unit.
    
- ADC attenuation.
    
- ADC bit width.
    
- Calibration reference parameters khi cần.
    

Việc hiệu chuẩn có thể sử dụng các giá trị được ghi trong eFuse của chip.

Nếu thông tin hiệu chuẩn cần thiết không có trong eFuse, driver có thể cần giá trị điện áp tham chiếu mặc định.

### 4.4. Raw ADC to Calibrated Voltage

ESP-IDF cung cấp các API như:

```
adc_cali_raw_to_voltage(
    adc_cali_handle,
    adc_raw,
    &voltage
);
```

API chuyển kết quả ADC thô thành điện áp tính bằng millivolt.

Đối với trường hợp cần hiệu chỉnh theo kênh ADC, tài liệu còn đề cập:

```
adc_cali_chan_raw_to_voltage(
    adc_cali_handle,
    channel,
    adc_raw,
    &voltage
);
```

Các API trên thuộc **ESP-IDF**, không phải hàm Arduino đang được nhóm G2 gọi trực tiếp.

## 5. Noise Reduction – Giảm nhiễu ADC

Espressif cho biết ADC của ESP32 nhạy với nhiễu điện, có thể dẫn đến sự khác biệt đáng kể giữa các lần đo.

Tài liệu đề xuất hai hướng giảm nhiễu:

### 5.1. Bypass Capacitor

Có thể sử dụng tụ ceramic, ví dụ 100 nF, tại đầu vào ADC trong những trường hợp phù hợp để giảm nhiễu.

Giá trị này là ví dụ kỹ thuật từ tài liệu Espressif; cần kiểm tra tính phù hợp với mạch cảm biến thực tế.

### 5.2. Multisampling

Đọc nhiều mẫu ADC và xử lý kết quả giúp hạn chế ảnh hưởng của nhiễu ngẫu nhiên.

Tài liệu minh họa giải pháp multisampling với 64 mẫu.

Tuy nhiên, số lượng mẫu trong hình minh họa không có nghĩa mọi hệ thống bắt buộc phải sử dụng 64 mẫu.

### 5.3. Trade-off

**Lấy nhiều mẫu:**

- Có thể giảm dao động do nhiễu ngẫu nhiên.
    
- Tăng thời gian xử lý một lần đo.
    
- Không tự động loại bỏ được sai số hệ thống hoặc cảm biến chưa hiệu chuẩn.
    

**Tụ lọc:**

- Có thể giảm một số thành phần nhiễu.
    
- Cần lựa chọn phù hợp với tín hiệu và thời gian đáp ứng mong muốn.
    

## 6. Technical Findings – Những thông tin kỹ thuật chính

|Thông số / Vấn đề|Nội dung|
|---|---|
|ESP32 nominal ADC reference|1100 mV|
|Actual reference variation|1000–1200 mV|
|Calibration method|Line Fitting|
|Calibration data|Có thể sử dụng eFuse|
|Calibrated voltage|Millivolt|
|Noise mitigation|Bypass capacitor, multisampling|
|Example bypass capacitor|100 nF|
|Example multisampling|64 samples|
|ESP-IDF calibration API|`adc_cali_raw_to_voltage()`|

Đây là những thông số và hướng dẫn kỹ thuật, không phải kết quả thí nghiệm của nhóm G2.

## 7. Limitations – Giới hạn

Hiệu chuẩn ADC không bảo đảm toàn bộ hệ thống đo nhiệt độ chính xác tuyệt đối.

Các nguồn sai số khác vẫn có thể tồn tại:

- Sai số của cảm biến LM35.
    
- Nhiễu nguồn điện.
    
- Nhiễu đường tín hiệu.
    
- Độ ổn định của ADC.
    
- Vị trí cảm biến.
    
- Điều kiện nhiệt độ môi trường.
    
- Cấu hình attenuation không phù hợp.
    
- Sai số do nguồn cấp hoặc cách đấu dây.
    

Ngoài ra, tài liệu ESP-IDF không tự động chứng minh rằng Arduino Core sử dụng hoàn toàn cùng một cơ chế triển khai calibration trong mọi phiên bản.

Cần kiểm tra phiên bản Arduino-ESP32 thực tế của nhóm trước khi mô tả chi tiết nội bộ thư viện.

## 8. Relevance to IOT102 G2 – Liên hệ dự án

### 8.1. LM35 Temperature Sensor

Firmware G2 sử dụng LM35 để đo nhiệt độ.

Cảm biến tạo điện áp analog theo nhiệt độ, với hệ số chuyển đổi danh định:

**10 mV tương ứng 1°C.**

Công thức được chương trình sử dụng:

`Temperature (°C) = Voltage (mV) / 10`

Đây là công thức dựa trên đặc tính danh định của LM35, không phải công thức tính trực tiếp từ ADC raw value.

### 8.2. ESP32 ADC Configuration

Theo source code G2:

```
#define LM35_PIN 34

analogReadResolution(12);
analogSetPinAttenuation(LM35_PIN, ADC_0db);
```

Trong đó:

- GPIO34 nhận tín hiệu analog từ LM35.
    
- `analogReadResolution(12)` thiết lập độ phân giải đọc 12-bit.
    
- `ADC_0db` cấu hình mức attenuation cho kênh ADC.
    

Mức attenuation ảnh hưởng phạm vi điện áp đầu vào có thể đo phù hợp. Không nên mặc định rằng mọi điện áp trong khoảng 0–3,3 V đều được đo chính xác với `ADC_0db`.

### 8.3. Temperature Reading Algorithm

Firmware G2:

```
float readTemperature() {
    uint32_t total = 0;

    for (int i = 0; i < 10; i++) {
        total += analogReadMilliVolts(LM35_PIN);
        delay(5);
    }

    float voltageMv = total / 10.0;

    return voltageMv / 10.0;
}
```

Quy trình:

1. Đọc điện áp LM35 tại GPIO34.
    
2. Thực hiện 10 lần đọc.
    
3. Có khoảng delay 5 ms sau mỗi lần đọc.
    
4. Tính điện áp trung bình.
    
5. Chia điện áp trung bình cho 10 để tính nhiệt độ Celsius.
    

Nhóm đã sử dụng **multisampling với 10 lần đọc**, phù hợp về nguyên lý với khuyến nghị giảm nhiễu của Espressif.

Tuy nhiên, cần phân biệt:

- `analogReadMilliVolts()` là API của Arduino-ESP32.
    
- `adc_cali_raw_to_voltage()` là API được mô tả trong ESP-IDF.
    
- Source G2 không trực tiếp sử dụng ESP-IDF ADC Calibration Driver.
    
- Không được khẳng định G2 đã thực hiện hiệu chuẩn độc lập bằng thiết bị đo chuẩn.
    

### 8.4. Temperature Thresholds

Hệ thống G2 sử dụng:

- `TEMP_WARNING = 40.0°C`
    
- `TEMP_DANGER = 43.0°C`
    

Nếu điện áp đo từ LM35 không chính xác, nhiệt độ tính toán có thể sai lệch và ảnh hưởng đến quyết định phân loại.

Ví dụ minh họa:

Nếu điện áp đo được là 420 mV, chương trình tính:

`Temperature = 420 / 10 = 42°C`

Khi không có tín hiệu lửa hoặc khói, trạng thái sẽ là WARNING.

Nếu điện áp đo được là 440 mV:

`Temperature = 440 / 10 = 44°C`

Khi đó hệ thống sẽ chuyển sang DANGER.

Đây là ví dụ suy ra từ công thức và code, không phải dữ liệu đo thực tế.

### 8.5. Hardware Considerations

Khi hoàn thiện Circuit Schematic, nhóm cần xác minh:

- Phiên bản và điện áp cấp nguồn được nhà sản xuất cho phép đối với LM35 đang sử dụng.
    
- Nguồn cấp cảm biến ổn định.
    
- Tín hiệu đầu ra LM35 nằm trong phạm vi ADC cho phép.
    
- Mass/GND của các module được nối đúng.
    
- Điện áp thực tế đo được phù hợp với cấu hình ADC.
    

Đặc biệt, nếu nhóm đang cấp LM35 trực tiếp bằng 3,3 V, cần kiểm tra đúng mã linh kiện và datasheet. Nhiều phiên bản LM35 thông dụng có điện áp cấp nguồn tối thiểu danh định khoảng 4 V; không nên mặc định 3,3 V là hợp lệ chỉ vì phần mềm đọc được dữ liệu.

## 9. Application in Final Report – Cách sử dụng

### Hardware Implementation

Giải thích nguyên lý LM35 xuất tín hiệu analog và ESP32 sử dụng ADC để đọc điện áp.

### Software Implementation

Trình bày hàm `readTemperature()`, 10 lần lấy mẫu và cách chuyển đổi mV sang °C.

### Methodology

Giải thích cấu hình ADC, thuật toán averaging và các ngưỡng nhiệt độ.

### Experimental Results

Tài liệu có thể làm cơ sở để thiết kế thí nghiệm so sánh nhiệt độ G2 với nhiệt kế tham chiếu.

Chỉ báo cáo sai số nếu nhóm thật sự có phép đo đối chiếu.

### Limitations

Thảo luận về nhiễu ADC, calibration, độ ổn định nguồn và sai số cảm biến.

### Future Work

Đề xuất:

- Đánh giá sai số LM35 với nhiệt kế tham chiếu.
    
- Kiểm tra và cải thiện mạch lọc nhiễu.
    
- Thử các cấu hình multisampling khác nhau.
    
- Kiểm chứng calibration theo phiên bản Arduino-ESP32 sử dụng.
    
- Bổ sung khả năng phát hiện giá trị cảm biến bất thường.
    

## 10. Suggested Technical Evaluation

**Temperature Measurement Reliability Using ESP32 ADC and LM35**

Có thể thiết kế thí nghiệm:

1. Đặt LM35 và nhiệt kế tham chiếu trong cùng điều kiện.
    
2. Đọc nhiệt độ từ Serial Monitor.
    
3. Ghi nhiệt độ tham chiếu.
    
4. Lặp lại tại nhiều mức nhiệt.
    
5. Tính sai số tuyệt đối.
    

Công thức:

`Absolute Error = |T_ESP32 - T_reference|`

`Mean Absolute Error = Tổng sai số tuyệt đối / Số lần đo`

Nhóm chưa cung cấp dữ liệu để thực hiện phép tính này.

Do đó, thí nghiệm chỉ là hướng đánh giá đề xuất, không phải kết quả đã hoàn thành.

## 11. Reference – BibTeX

```
@manual{espressif_adc_calibration,
  author       = {{Espressif Systems}},
  title        = {Analog to Digital Converter
                  (ADC) Calibration Driver},
  organization = {Espressif Systems},
  url          = {https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/adc/adc_calibration.html},
  note         = {ESP-IDF Programming Guide,
                  ESP32 documentation,
                  accessed 2026-11-03}
}
```

**Citation key:** `espressif_adc_calibration`

**Source status:** Đã tổng hợp nội dung tài liệu kỹ thuật chính thức được cung cấp.

**Recommendation:** Phù hợp cho Hardware Implementation, Software Implementation, Methodology và Limitations.

Không sử dụng tài liệu này như một bài nghiên cứu về độ chính xác phát hiện cháy hoặc tỷ lệ cảnh báo nhầm.

# PAPER 06 – Early Fire Detection Based on Gas Sensor Arrays: Multivariate Calibration and Validation

## 1. Thông tin bài báo

- **Title:** Early fire detection based on gas sensor arrays: Multivariate calibration and validation
    
- **Authors:** Ana Solórzano, Jens Eichmann, Luis Fernández, Bernd Ziems, Juan Manuel Jiménez-Soto, Santiago Marco, Jordi Fonollosa
    
- **Journal:** Sensors and Actuators B: Chemical
    
- **Publication:** February 1, 2022
    
- **DOI:** [https://doi.org/10.1016/j.snb.2021.130961](https://doi.org/10.1016/j.snb.2021.130961)
    
- **Keywords:** Gas sensors, Early fire detection, Sensor arrays, EN-54, Smoke detector, Fire alarm, Public dataset
    
- **Source status:** Đã đọc nội dung nghiên cứu được cung cấp, bao gồm Methodology, Experiments, Results và Conclusions.
    

## 2. Research Problem – Vấn đề nghiên cứu

Những đám cháy âm ỉ (_smoldering fires_) có thể phát thải khí CO và các hợp chất hữu cơ dễ bay hơi (_VOCs_) trước khi xuất hiện lượng khói lớn hoặc ngọn lửa rõ ràng.

Các hệ thống dựa trên cảm biến khí có khả năng phát hiện những khí này sớm, nhưng cũng gặp hai vấn đề:

1. **False alarms:** Cảm biến phản ứng với các nguồn khí không phải cháy như chất tẩy rửa, cồn hoặc sản phẩm tạo mùi.
    
2. **Sensor drift:** Đặc tính của cảm biến thay đổi theo thời gian khiến mô hình đã hiệu chuẩn mất độ chính xác.
    

Ngoài ra, chi phí xây dựng dữ liệu hiệu chuẩn trong phòng thử nghiệm cháy tiêu chuẩn tương đối cao.

## 3. Research Objectives – Mục tiêu

Nghiên cứu hướng đến:

- Phát hiện sớm cháy âm ỉ và cháy liên quan đến vật liệu nhựa.
    
- Phân biệt sự kiện cháy với nguồn gây nhiễu.
    
- Đánh giá độ ổn định của mô hình sau nhiều tháng.
    
- Giảm chi phí thu thập dữ liệu bằng mô hình thí nghiệm quy mô nhỏ.
    

## 4. Proposed Methodology – Phương pháp

### 4.1. Gas Sensor Array

Hệ thống sử dụng một mảng gồm 12 cảm biến, bao gồm:

- Các cảm biến Metal Oxide (MOX) để phát hiện VOCs và một số khí.
    
- Cảm biến điện hóa đo CO.
    
- Cảm biến NDIR đo CO2.
    
- Photoionization Detector (PID) phát hiện VOCs.
    
- Cảm biến nhiệt độ và độ ẩm.
    

Nền tảng thu thập dữ liệu sử dụng Arduino DUE, với tín hiệu analog được lấy mẫu ở tần số 10 Hz.

### 4.2. Data Preprocessing

Các tín hiệu cảm biến được xử lý trước khi đưa vào mô hình:

1. Median filtering để giảm nhiễu.
    
2. Giảm tần suất dữ liệu xuống các đoạn 1 giây.
    
3. Chuyển tín hiệu MOX từ điện áp sang độ dẫn điện.
    
4. Điều chỉnh baseline ở đầu mỗi thí nghiệm.
    

### 4.3. Classification Models

Nghiên cứu so sánh hai phương pháp:

**Partial Least Squares Discriminant Analysis (PLS-DA):** Phương pháp phân loại tuyến tính dựa trên các biến đặc trưng được trích xuất.

**Support Vector Machine (SVM):** Phương pháp phân loại phi tuyến sử dụng RBF kernel.

Mô hình được huấn luyện trên các chiến dịch đo trước đó, sau đó đánh giá bằng tập dữ liệu thu thập ở thời điểm khác.

### 4.4. Temporal Confirmation

Nghiên cứu yêu cầu dự đoán cháy duy trì trong một khoảng thời gian trước khi chấp nhận là cảnh báo thật.

Các cửa sổ thời gian được thử nghiệm:

- 15 giây.
    
- 30 giây.
    
- 60 giây.
    

Cơ chế này giúp loại bỏ một số tín hiệu kích hoạt ngắn, nhưng làm tăng thời gian phát cảnh báo.

Đây là trade-off giữa khả năng chống cảnh báo nhầm và tốc độ phản hồi.

## 5. Experimental Setup – Thiết lập thí nghiệm

Nghiên cứu sử dụng hai môi trường:

### 5.1. Standard Fire Room

- Kích thước: 10 × 6 × 4 m.
    
- Thể tích: 240 m³.
    
- Dựa trên phòng thử nghiệm theo tiêu chuẩn EN-54.
    
- Có các thiết bị đo tham chiếu và đầu báo khói thương mại.
    

Các tình huống cháy bao gồm gỗ, bông, PVC, PET, dây cáp và linh kiện điện tử.

Các tình huống gây nhiễu bao gồm cồn, xăng, giấm, chất tẩy rửa và sản phẩm tạo mùi.

### 5.2. Small-Scale Chamber

- Kích thước: 55 × 55 × 90 cm.
    
- Thể tích khoảng 272 lít.
    
- Được thiết kế để thử nghiệm nhanh hơn với chi phí thấp hơn.
    

Buồng thử nghiệm được đặt trong hệ thống hút khí để xử lý an toàn khí sinh ra.

### 5.3. Datasets

|Dataset|Số thí nghiệm|Nguồn|
|---|---|---|
|LD1|27|Standard room|
|LD2|18|Standard room|
|LD3|25|Standard room|
|SD1|34|Small-scale chamber|
|**Total**|**104**|**4 measurement campaigns**|

Các chiến dịch được tiến hành ở những thời điểm cách nhau nhiều tháng, cho phép đánh giá độ ổn định của mô hình theo thời gian.

## 6. Results and Findings – Kết quả

### 6.1. Đánh giá PLS-DA và SVM

Sử dụng LD1 và LD2 để xây dựng mô hình, LD3 để kiểm thử:

|Metric|PLS-DA|SVM|
|---|---|---|
|Fire detected (TP)|11|10|
|Fire missed (FN)|2|3|
|False alarms (FP)|0|1|
|Correct non-fire (TN)|12|11|
|Sensitivity|Khoảng 85%|Khoảng 77%|
|Specificity|100%|Khoảng 92%|

PLS-DA không gây cảnh báo nhầm trong tập LD3 được báo cáo nhưng bỏ sót hai sự kiện cháy.

SVM phát hiện ít sự kiện cháy hơn trong tập kiểm thử này và có một cảnh báo nhầm, nhưng nghiên cứu cho thấy phương pháp SVM có thể phản hồi nhanh hơn ở những tình huống được khảo sát.

### 6.2. Kết quả kết hợp dữ liệu hai môi trường

Nghiên cứu đánh giá việc bổ sung dữ liệu từ buồng thử nghiệm nhỏ vào dữ liệu phòng tiêu chuẩn.

|Training Data|Classification Rate|Sensitivity|Specificity|AUC|
|---|---|---|---|---|
|LD1|52%|82%|32%|0.60|
|SD1|70%|60%|88%|0.70|
|LD1 + SD1|**88%**|**90%**|**81%**|**0.89**|

Mô hình kết hợp có hiệu năng tổng thể tốt hơn trong phép so sánh này.

### 6.3. Kết luận quan trọng

- Dữ liệu cảm biến khí có thể giúp phát hiện một số dạng cháy sớm hơn đầu báo khói thông thường.
    
- Kết hợp dữ liệu huấn luyện đa dạng giúp cải thiện khả năng phân biệt cháy với nguồn nhiễu.
    
- Sensor drift vẫn là vấn đề cần được nghiên cứu.
    
- Độ nhạy và khả năng loại bỏ false alarms không phải lúc nào cũng cải thiện đồng thời.
    

## 7. Limitations – Giới hạn

- Hệ thống sử dụng nhiều loại cảm biến và mạch xử lý phức tạp.
    
- Cần dữ liệu thực nghiệm đa dạng để xây dựng mô hình.
    
- Sensor drift ảnh hưởng đến độ ổn định dài hạn.
    
- Một số loại cháy nhựa có tín hiệu khí gần giống nguồn gây nhiễu.
    
- Chưa đạt khả năng phát hiện và loại bỏ cảnh báo nhầm hoàn hảo.
    

Kết quả phụ thuộc vào tập dữ liệu và điều kiện thử nghiệm.

## 8. Relevance to IOT102 G2 – Liên hệ dự án

### Điểm tương đồng

- Cùng sử dụng tín hiệu cảm biến liên quan đến khí/khói để phát hiện nguy hiểm.
    
- Cùng phải xem xét cảnh báo nhầm.
    
- Cùng hướng đến phát hiện cháy sớm.
    

### Điểm khác biệt

|Tiêu chí|Solórzano et al.|G2|
|---|---|---|
|Bộ xử lý|Arduino DUE|ESP32|
|Gas sensors|Sensor array đa loại|MQ-2|
|Dữ liệu khí|Analog đa kênh|MQ-2 digital DO|
|Phân loại|PLS-DA / SVM|Rule-based OR|
|Calibration|Dựa trên datasets|Ngưỡng module, chưa có dataset calibration|
|False alarm evaluation|Có thử nghiệm nuisance|Chưa có đánh giá định lượng|
|Monitoring|Máy tính thu thập dữ liệu|LCD và Serial Monitor|

### Trade-off

G2 sử dụng một MQ-2 với tín hiệu digital, phù hợp với prototype đơn giản nhưng không cung cấp lượng thông tin tương đương mảng cảm biến khí của nghiên cứu.

Điều này hạn chế khả năng phân tích đặc trưng và phân biệt các nguồn khí khác nhau.

## 9. Application in Final Report

**Introduction:** Giải thích vấn đề phát hiện sớm khí sinh ra từ cháy âm ỉ.

**Related Work:** Trình bày phương pháp sử dụng gas sensor arrays và machine learning để phân biệt cháy với nguồn gây nhiễu.

**Discussion:** Phân tích hạn chế của MQ-2 digital và nguy cơ cảnh báo nhầm.

**Future Work:** Đề xuất hiệu chuẩn MQ-2, đánh giá các tình huống khói sinh hoạt và thu thập dữ liệu analog nếu phần cứng cho phép.

## 10. Suggested Research Direction

**Calibration and False-Alarm Evaluation of Low-Cost Gas Sensors**

Một hướng nghiên cứu cho G2 là kiểm tra khả năng phân biệt các tình huống có khói nhưng không có cháy so với tình huống nguy hiểm.

Các tiêu chí cần đánh giá:

- False Positive Rate.
    
- False Negative Rate.
    
- Response Time.
    
- Độ ổn định theo thời gian.
    
- Ảnh hưởng của cấu hình ngưỡng.
    

Không được sử dụng các metrics của nghiên cứu Solórzano làm kết quả G2.

## 11. Reference – BibTeX

```
@article{solorzano2022gas,
  author = {Ana Solorzano and Jens Eichmann
            and Luis Fernandez and Bernd Ziems
            and Juan Manuel Jimenez-Soto
            and Santiago Marco and Jordi Fonollosa},
  title = {Early fire detection based on gas sensor
           arrays: Multivariate calibration and validation},
  journal = {Sensors and Actuators B: Chemical},
  year = {2022},
  doi = {10.1016/j.snb.2021.130961}
}
```

**Citation key:** `solorzano2022gas`

**Recommendation:** Nguồn quan trọng cho Related Work, Discussion và hướng cải thiện false alarms của G2.

**Source note:** Nội dung có một chỗ ghi nhầm "100% false positive rate" khi mô tả PLS-DA, nhưng confusion matrix cho thấy 0 false positives và 12 true negatives, tương ứng specificity 100%. Bản tổng hợp sử dụng số liệu trực tiếp từ confusion matrix.

# PAPER 07 – Recurrent Trend Predictive Neural Network for Multi-Sensor Fire Detection

## 1. Thông tin bài báo

- **Title:** Recurrent Trend Predictive Neural Network for Multi-Sensor Fire Detection
    
- **Authors:** Mert Nakip, Cüneyt Güzelíş, Osman Yildiz
    
- **Journal:** IEEE Access
    
- **Volume:** 9
    
- **Pages:** 84204–84216
    
- **Publication Date:** June 10, 2021
    
- **DOI:** [https://doi.org/10.1109/ACCESS.2021.3087736](https://doi.org/10.1109/ACCESS.2021.3087736)
    
- **Keywords / Topics:** Fire Detection, Multi-Sensor Fusion, Recurrent Neural Network, Trend Prediction, Time Series
    
- **Source status:** Đã đọc nội dung Introduction, Methodology, Results và Conclusion do người dùng cung cấp.
    

## 2. Research Problem – Vấn đề nghiên cứu

Hệ thống phát hiện cháy dựa trên tín hiệu cảm biến có thể gặp hai dạng lỗi:

- **False Positive:** Báo cháy khi thực tế không có cháy.
    
- **False Negative:** Không báo cháy khi thực tế có cháy.
    

Các phương pháp chỉ xem xét giá trị cảm biến tại một thời điểm có thể bị ảnh hưởng bởi nhiễu tức thời.

Ví dụ, nhiệt độ có thể tăng bất thường trong một thời gian ngắn nhưng không phải do cháy.

Nghiên cứu đặt ra vấn đề: liệu việc phân tích đồng thời **giá trị hiện tại và xu hướng biến đổi của tín hiệu theo thời gian** có giúp cải thiện chất lượng phát hiện cháy hay không?

## 3. Research Objectives – Mục tiêu

Đề xuất mô hình Recurrent Trend Predictive Neural Network (rTPNN) nhằm:

1. Kết hợp dữ liệu từ nhiều cảm biến.
    
2. Dự đoán mức giá trị và xu hướng của từng tín hiệu.
    
3. Cải thiện khả năng phân biệt fire và non-fire.
    
4. Giảm đồng thời False Positive Rate và False Negative Rate.
    
5. Rút ngắn thời gian cảnh báo cháy.
    

## 4. Proposed Methodology – Phương pháp

### 4.1. Recurrent Trend Predictive Neural Network

rTPNN là một kiến trúc neural network xử lý dữ liệu cảm biến dạng chuỗi thời gian.

Khác với các phương pháp chỉ sử dụng giá trị tại thời điểm hiện tại, rTPNN xem xét cả diễn biến trước đó của tín hiệu.

Kiến trúc gồm hai nhóm thành phần:

**Sensor Data Processing (SDP):** Xử lý dữ liệu của từng cảm biến.

**Fire Predictor (FP):** Kết hợp các đặc trưng để dự đoán tình trạng cháy.

### 4.2. Sensor Data Processing

Mỗi cảm biến có một SDP module, gồm:

- Trend Predictor: Ước lượng xu hướng thay đổi.
    
- Level Predictor: Ước lượng mức tín hiệu.
    

Đầu vào gồm dữ liệu hiện tại, dữ liệu trước đó và trạng thái được lưu qua các bước thời gian.

Kết quả của mỗi module gồm giá trị cảm biến, predicted trend và predicted level.

### 4.3. Fire Predictor

Fire Predictor là một mạng fully connected.

Đầu vào là tập hợp các đặc trưng từ những SDP module.

Đầu ra là một giá trị trong khoảng 0–1 biểu thị dự đoán trạng thái cháy.

Giá trị đầu ra được so sánh với một ngưỡng phân loại để đưa ra quyết định fire/non-fire.

### 4.4. Model Training

Mô hình học các tham số từ dữ liệu thử nghiệm đã gán nhãn.

Quá trình training sử dụng Mean Squared Error (MSE) làm hàm mất mát để điều chỉnh tham số.

Nghiên cứu cũng so sánh rTPNN với:

- Linear Regression (LR).
    
- Nonlinear Perceptron (NP).
    
- Multi-Layer Perceptron (MLP).
    
- Kendall-MLP.
    
- Probabilistic Bayesian Neural Network (PBNN).
    
- Long Short-Term Memory (LSTM).
    
- Support Vector Machine (SVM).
    

## 5. Experimental Setup – Thiết lập thí nghiệm

Nghiên cứu sử dụng bộ dữ liệu cháy công khai.

Dữ liệu bao gồm:

- Temperature.
    
- Smoke Obscuration.
    
- Carbon Monoxide (CO).
    
- Carbon Dioxide (CO2).
    
- Oxygen (O2).
    

Trong nghiên cứu:

- Chọn 9 thí nghiệm cháy phù hợp từ tập dữ liệu.
    
- Tạo 25.796 mẫu cho bài toán dự đoán.
    
- Sử dụng phương pháp 10-fold cross-validation.
    
- Dữ liệu có khoảng 73,5% mẫu được gán nhãn non-fire.
    

Các mô hình được đánh giá trên cùng tập dữ liệu và so sánh theo nhiều chỉ số.

Lưu ý: Phương pháp chia mẫu và sự phụ thuộc giữa các thời điểm trong cùng thí nghiệm là yếu tố cần cân nhắc khi đánh giá khả năng tổng quát hóa.

## 6. Results and Findings – Kết quả

Theo nghiên cứu:

|Metric|rTPNN|
|---|---|
|Classification Accuracy|96%|
|True Positive Rate|Trên 92%|
|True Negative Rate|Trên 92%|
|F1-score|0,93|
|AUC|0,99|
|Average Time to Alarm|11 giây|
|Inference Time|Dưới 0,6 ms với tối đa 20 cảm biến trong thí nghiệm tính toán|

### 6.1. Accuracy

rTPNN đạt accuracy 96% trong phép đánh giá được công bố và vượt các mô hình so sánh trong thiết lập nghiên cứu.

### 6.2. False Positive và False Negative

Nghiên cứu cho biết rTPNN là mô hình duy nhất trong các phương pháp được so sánh đạt đồng thời True Positive Rate và True Negative Rate trên 92%.

Điều này quan trọng vì một hệ thống có tỷ lệ phát hiện cháy cao nhưng liên tục phát cảnh báo nhầm vẫn khó sử dụng trong thực tế.

### 6.3. Response Time

rTPNN báo cháy trung bình sau 11 giây tính từ thời điểm cháy bắt đầu theo phương pháp đánh giá của nghiên cứu.

Các phương pháp MLP, Kendall-MLP và LR được báo cáo ở mức 22 giây; một số mô hình khác cần nhiều thời gian hơn.

**Phân biệt:** 11 giây là thời gian phát hiện cháy trên chuỗi dữ liệu thí nghiệm, không phải thời gian chạy một phép dự đoán của neural network.

### 6.4. Computation Time

Nghiên cứu cho biết thời gian thực thi một phép dự đoán của rTPNN dưới 0,6 ms với tối đa 20 cảm biến trong thử nghiệm tính toán.

Tuy nhiên, phép đo được thực hiện trên môi trường Google Colab, không phải ESP32.

Không được suy ra mô hình sẽ có tốc độ tương tự nếu triển khai trên ESP32.

## 7. Limitations – Giới hạn

- Mô hình cần dữ liệu có nhãn để huấn luyện.
    
- Có độ phức tạp cao hơn các quy tắc threshold đơn giản.
    
- Các kết quả được đánh giá trên bộ dữ liệu lựa chọn từ các thí nghiệm có sẵn.
    
- Dữ liệu có sự mất cân bằng giữa fire và non-fire.
    
- Nghiên cứu chưa chứng minh hiệu năng thực tế của rTPNN trên phần cứng ESP32.
    
- Cần xem xét khả năng tổng quát hóa với môi trường và nguồn nhiễu mới.
    

Trong Conclusion, tác giả cũng đề xuất kiểm tra triển khai phần cứng thực tế trong tương lai.

## 8. Relevance to IOT102 G2 – Liên hệ dự án

### Điểm tương đồng

Cả nghiên cứu và G2 đều sử dụng nhiều tín hiệu môi trường để phát hiện nguy hiểm.

Cả hai đều hướng đến việc cảnh báo sớm và giảm nguy cơ bỏ sót cháy.

### Điểm khác biệt

|Tiêu chí|Nakip et al. (2021)|IOT102 G2|
|---|---|---|
|Thuật toán|rTPNN|Rule-based|
|Đầu vào|Multivariate time series|LM35 analog, MQ-2/Flame digital|
|Xu hướng theo thời gian|Có|Chưa có|
|Machine Learning|Có|Không|
|Training Dataset|Có|Không|
|Phân loại|Fire / Non-fire|SAFE / WARNING / DANGER|
|Nền tảng đánh giá|Dataset và môi trường tính toán|ESP32 prototype|

### 8.1. Hạn chế của G2

Firmware G2 sử dụng ngưỡng:

```
const float TEMP_WARNING = 40.0;
const float TEMP_DANGER = 43.0;
```

Điều kiện nguy hiểm:

```
bool danger = flameDetected ||
              smokeDetected ||
              temperature >= TEMP_DANGER;
```

Hệ thống quyết định dựa trên trạng thái cảm biến trong chu kỳ xử lý hiện tại.

LM35 có thực hiện trung bình 10 lần đọc nhằm giảm dao động phép đo, nhưng chương trình chưa có thuật toán theo dõi xu hướng nhiệt độ trong nhiều chu kỳ.

**Lấy trung bình nhiều mẫu không đồng nghĩa với dự đoán xu hướng theo thời gian.**

### 8.2. Trade-off

**rTPNN:**

- Khai thác diễn biến cảm biến theo thời gian.
    
- Có kết quả đánh giá bằng dữ liệu.
    
- Cần training và xử lý phức tạp.
    

**G2 Rule-Based:**

- Dễ triển khai và kiểm thử.
    
- Không yêu cầu dữ liệu huấn luyện.
    
- Phù hợp với phạm vi dự án nhỏ.
    
- Chưa phân tích được các xu hướng tín hiệu dài hạn.
    

## 9. Application in Final Report

**Introduction:** Nêu vấn đề false positives và false negatives.

**Related Work:** Giới thiệu phương pháp sử dụng neural network để kết hợp giá trị và xu hướng cảm biến.

**Methodology:** Làm rõ G2 sử dụng threshold-based processing, không sử dụng machine learning.

**Discussion:** Phân tích hạn chế khi chỉ đánh giá giá trị cảm biến tức thời.

**Future Work:** Đề xuất bổ sung temporal filtering hoặc trend monitoring để nghiên cứu cải thiện chất lượng cảnh báo.

## 10. Suggested Research Direction

**Temporal Analysis for Fire Detection Using ESP32**

Một hướng phát triển đơn giản hơn rTPNN nhưng phù hợp với G2 là nghiên cứu:

- Tốc độ tăng nhiệt độ theo thời gian.
    
- Số chu kỳ liên tục có tín hiệu nghi ngờ.
    
- Thời gian duy trì cảnh báo.
    
- Cơ chế lọc nhiễu ngắn hạn.
    

Các cơ chế này cần được kiểm chứng để bảo đảm không làm chậm cảnh báo nguy hiểm thực sự.

Không tuyên bố G2 đã triển khai rTPNN hay đạt các metrics của bài báo.

## 11. Reference – BibTeX

```
@article{nakip2021rtpnn,
  author = {Mert Nakip and Cuneyt Guzelis
            and Osman Yildiz},
  title = {Recurrent Trend Predictive Neural Network
           for Multi-Sensor Fire Detection},
  journal = {IEEE Access},
  volume = {9},
  pages = {84204--84216},
  year = {2021},
  doi = {10.1109/ACCESS.2021.3087736}
}
```

**Citation key:** `nakip2021rtpnn`

**Recommendation:** Phù hợp cho Related Work, Discussion và Future Work về phân tích tín hiệu theo thời gian.


# PAPER 08 – Smart Fire Detection and Deterrent System for Human Savior by Using Internet of Things (IoT)

## 1. Thông tin bài báo

- **Title:** Smart Fire Detection and Deterrent System for Human Savior by Using Internet of Things (IoT)
    
- **Authors:** Abdul Rehman, Muhammad Ahmed Qureshi, Tariq Ali, Muhammad Irfan, Saima Abdullah, Sana Yasin, Umar Draz, Adam Glowacz, Grzegorz Nowakowski và các đồng tác giả được liệt kê trong bài gốc
    
- **Journal:** Energies (MDPI)
    
- **Volume / Issue:** 14(17)
    
- **Article Number:** 5500
    
- **Publication Date:** September 3, 2021
    
- **DOI:** [https://doi.org/10.3390/en14175500](https://doi.org/10.3390/en14175500)
    
- **Keywords:** Smart Fire Detection, Multiple Sensors, Fuzzy Logic, IoT
    
- **Source status:** Đã đọc nội dung Introduction, Methods, Implementation, Results và Conclusions được cung cấp.
    

## 2. Research Problem – Vấn đề nghiên cứu

Các hệ thống phát hiện cháy sử dụng một cảm biến đơn lẻ có thể phát cảnh báo sai vì những điều kiện môi trường không nguy hiểm.

Ngoài phát hiện cháy, một hệ thống an toàn thông minh còn cần đánh giá mức độ nghiêm trọng để thực hiện hành động phù hợp.

Nghiên cứu đặt ra vấn đề:

1. Làm thế nào kết hợp dữ liệu nhiều cảm biến để đánh giá nguy cơ cháy?
    
2. Làm thế nào phân loại mức độ nguy hiểm thay vì chỉ đưa ra hai trạng thái fire/non-fire?
    
3. Làm thế nào tự động kích hoạt những thiết bị hỗ trợ khi tình huống trở nên nghiêm trọng?
    

## 3. Research Objectives – Mục tiêu

Nghiên cứu xây dựng một hệ thống **Smart Fire Detection and Deterrent (SMDD)**.

Mục tiêu:

- Phát hiện nguy cơ cháy bằng nhiều cảm biến.
    
- Sử dụng Fuzzy Logic để đánh giá mức nguy hiểm.
    
- Cung cấp cảnh báo phù hợp với tình huống.
    
- Hỗ trợ tự động điều khiển thiết bị như ventilation và water sprinkler.
    
- Thiết kế hệ thống phù hợp với nhà ở hoặc văn phòng quy mô nhỏ.
    

## 4. Proposed Methodology – Phương pháp

### 4.1. Hardware Architecture

Các thành phần chính được nghiên cứu sử dụng:

|Thành phần|Vai trò|
|---|---|
|Arduino UNO|Bộ điều khiển|
|Flame Sensor|Nhận diện dấu hiệu ngọn lửa|
|Temperature Sensor|Đo nhiệt độ|
|Humidity Sensor|Đo độ ẩm|
|MQ-Series Smoke Sensor|Đo tín hiệu liên quan đến khói|
|Warning System|Phát cảnh báo|
|Ventilation|Hỗ trợ thông gió|
|Water Sprinkler|Hỗ trợ dập cháy ban đầu|

Trong phần thiết kế, bài báo mô tả các cảm biến MQ và DHT, đồng thời sử dụng dữ liệu nhiệt độ, độ ẩm, khói và thời gian làm đầu vào Fuzzy Logic.

### 4.2. Fuzzy Logic

Fuzzy Logic cho phép xử lý các mức độ như LOW, MEDIUM và HIGH thay vì chỉ sử dụng điều kiện TRUE/FALSE.

Ví dụ, một nhiệt độ có thể thuộc về mức MEDIUM với một độ thành viên nhất định, thay vì chỉ bị xếp cứng vào một trong hai nhóm.

Nghiên cứu áp dụng bốn giai đoạn:

1. Fuzzification.
    
2. Rule Evaluation.
    
3. Inference.
    
4. Defuzzification.
    

### 4.3. Fuzzification

Dữ liệu cảm biến dạng số (_crisp input_) được chuyển thành các mức độ thành viên của tập mờ.

Nghiên cứu sử dụng triangular membership functions.

Các đầu vào chính của bộ Fuzzy Logic gồm:

- Temperature.
    
- Humidity.
    
- Smoke.
    
- Time.
    

Flame Sensor đóng vai trò phát hiện ban đầu để xác định khi nào bắt đầu đánh giá tình huống.

### 4.4. Rule Base

Nghiên cứu thiết lập các quy tắc IF–THEN để kết hợp những giá trị đầu vào.

Ví dụ về mặt nguyên lý:

IF temperature is HIGH AND smoke is HIGH THEN fire risk is HIGH.

Ví dụ trên chỉ minh họa cấu trúc Fuzzy Rule, không phải trích dẫn nguyên văn một rule cụ thể của nghiên cứu.

Bài báo mô tả 72 quy tắc để đánh giá mức nguy hiểm theo các điều kiện đầu vào và thời gian.

### 4.5. Mamdani Inference

Nghiên cứu sử dụng Mamdani Fuzzy Inference System để xử lý các quy tắc.

Kết quả từ những quy tắc được kết hợp thành một tập mờ đầu ra.

### 4.6. Defuzzification

Nghiên cứu sử dụng Centroid Defuzzification để chuyển kết quả tập mờ thành một giá trị số biểu thị _Fire Chances_.

Kết quả này được sử dụng để xác định hành động của hệ thống.

### 4.7. Actuator Control

Tùy mức nguy hiểm, hệ thống có thể:

- Gửi thông báo.
    
- Kích hoạt cảnh báo.
    
- Khởi động water sprinkler.
    
- Kích hoạt ventilation để hỗ trợ giảm nguy cơ ngạt khói.
    

Các hành động được tổ chức theo mức độ nghiêm trọng của tình huống.

## 5. Experimental Setup – Thiết lập thí nghiệm

Nghiên cứu sử dụng Arduino để đọc cảm biến và MATLAB Fuzzy Logic Toolbox để mô phỏng, đánh giá quy tắc.

Các tình huống thí nghiệm sử dụng những giá trị khác nhau của:

- Nhiệt độ.
    
- Độ ẩm.
    
- Khói.
    
- Thời gian.
    
- Trạng thái Flame Sensor.
    

Theo nội dung bài báo:

- Có hơn 70 lượt mô phỏng và hơn 1.000 giá trị được nhắc đến trong quá trình thiết lập miền giá trị.
    
- Phần kết quả chính trình bày 15 thí nghiệm để đánh giá các mức nguy hiểm.
    
- MATLAB Rules Viewer được sử dụng để quan sát kết quả Fuzzy Logic.
    

Các số liệu này cần được phân biệt với số lượng phép thử độc lập trên prototype hoàn chỉnh.

## 6. Results and Findings – Kết quả

Theo nghiên cứu, 15 thí nghiệm chính có kết quả đầu ra phù hợp với các mức trạng thái mong đợi mà tác giả xác định.

Bài báo tính tỷ lệ phù hợp giữa kết quả dự đoán và nhãn kỳ vọng là 100% trong bộ 15 thí nghiệm này.

### 6.1. Các trường hợp minh họa

**Low Fire Chances:**

Khi các tín hiệu đầu vào biểu thị nguy cơ thấp, hệ thống đưa ra kết quả nguy hiểm thấp và thực hiện cảnh báo tương ứng.

**Medium Fire Chances:**

Khi nhiệt độ và mức khói tăng, hệ thống có thể đưa ra mức nguy hiểm trung bình.

**High Fire Chances:**

Với các tín hiệu nguy hiểm cao, hệ thống có thể phát cảnh báo và kích hoạt thêm sprinkler, ventilation.

### 6.2. Đánh giá về con số 100%

Con số 100% trong nghiên cứu phản ánh kết quả được tác giả báo cáo trên 15 tình huống thử nghiệm.

Không thể diễn giải đây là bảo đảm phát hiện cháy chính xác 100% trong thực tế.

Cũng không thể xem đây là đánh giá đầy đủ của một hệ thống phòng cháy được chứng nhận.

### 6.3. Đánh giá hệ thống

Điểm quan trọng của nghiên cứu là việc kết hợp **phân loại mức nguy hiểm với hành động điều khiển tương ứng**.

Thay vì chỉ bật buzzer, hệ thống đưa ra những hành động khác nhau theo tình huống.

## 7. Limitations – Giới hạn

Các hạn chế được bài báo đề cập hoặc thể hiện qua phạm vi nghiên cứu:

- Thiết kế hướng đến nhà ở và văn phòng nhỏ.
    
- Hiệu năng có thể khác khi triển khai trong không gian lớn.
    
- Flame Sensor có thể bị ảnh hưởng bởi nguồn bức xạ ngoài môi trường.
    
- Phần kết quả dựa nhiều vào mô phỏng MATLAB và các tình huống xác định trước.
    
- Chưa có đủ bằng chứng để khẳng định tỷ lệ phát hiện cháy thực tế là 100%.
    
- Không có phép so sánh trực tiếp với hệ thống ESP32 G2.
    

## 8. Relevance to IOT102 G2 – Liên hệ dự án

### 8.1. Điểm tương đồng

Cả hai hệ thống đều:

- Kết hợp nhiều cảm biến.
    
- Phân loại tình trạng nguy hiểm.
    
- Phát cảnh báo tại chỗ.
    
- Điều khiển thiết bị đầu ra theo mức nguy hiểm.
    
- Hướng đến ứng dụng cảnh báo cháy cho không gian trong nhà.
    

### 8.2. Điểm khác biệt

|Tiêu chí|Rehman et al. (2021)|IOT102 G2|
|---|---|---|
|Controller|Arduino UNO|ESP32|
|Algorithm|Fuzzy Logic|Rule-based threshold|
|Temperature|Có|LM35|
|Humidity|Có|Không|
|Smoke/Gas|MQ-Series Sensor|MQ-2|
|Flame|Có|Có|
|Classification|Fire Chances / mức nguy hiểm|SAFE / WARNING / DANGER|
|Output|Alarm, sprinkler, ventilation|LED, LCD, buzzer, Servo|
|Simulation|MATLAB Fuzzy Logic|Chưa dùng Fuzzy Logic|
|Remote Monitoring|Đề cập trong kiến trúc IoT|Chưa có trong firmware|

### 8.3. So sánh thuật toán

**G2:**

```
if (danger) {
    status = "DANGER";
}
else if (temperature >= TEMP_WARNING) {
    status = "WARNING";
}
else {
    status = "SAFE";
}
```

Hệ thống G2 dùng ba trạng thái được xác định bởi điều kiện Boolean và nhiệt độ.

Trong DANGER:

- LED đỏ bật.
    
- Buzzer kêu liên tục.
    
- Servo mở cửa mô hình.
    

Trong WARNING:

- LED vàng bật.
    
- Buzzer kêu ngắt quãng.
    

Trong SAFE:

- LED xanh bật.
    
- Buzzer tắt.
    

**Nghiên cứu SMDD:**

Sử dụng tập mờ và hệ thống quy tắc để tính toán mức Fire Chances, sau đó lựa chọn hành động dựa trên mức nguy hiểm.

### 8.4. Trade-off

**Fuzzy Logic:**

- Biểu diễn các mức nguy hiểm mềm dẻo hơn.
    
- Có thể kết hợp nhiều đặc trưng và mức thành viên.
    
- Cần thiết kế membership functions và rules.
    
- Phức tạp hơn về phát triển và kiểm chứng.
    

**Rule-Based G2:**

- Đơn giản, dễ đọc.
    
- Dễ đối chiếu với flowchart.
    
- Không yêu cầu mô hình training.
    
- Không biểu diễn trực tiếp mức độ chắc chắn của nguy cơ cháy.
    

Không thể kết luận Fuzzy Logic chính xác hơn hệ thống G2 nếu chưa kiểm thử cả hai trên cùng một tập tình huống.

## 9. Application in Final Report

**Introduction:** Giải thích nhu cầu kết hợp nhiều loại tín hiệu và tự động phản ứng khi nguy hiểm.

**Related Work:** Trình bày một hướng phát hiện cháy đa cảm biến sử dụng Fuzzy Logic.

**System Design:** Tham khảo cách liên kết trạng thái nguy hiểm với điều khiển đầu ra.

**Discussion:** So sánh thuật toán Rule-Based với các mô hình phân loại mềm dẻo hơn.

**Future Work:** Đề xuất Fuzzy Logic hoặc phương pháp sensor fusion khác nhằm nghiên cứu giảm cảnh báo nhầm và nâng cao khả năng đánh giá mức nguy hiểm.

## 10. Suggested Research Direction

**Severity-Based Fire Warning and Automatic Actuator Control**

Đối với G2, có thể nghiên cứu mở rộng từ ba trạng thái cố định sang đánh giá nguy cơ dựa trên nhiều yếu tố.

Các hướng có thể đánh giá:

- Mức tăng nhiệt độ.
    
- Thời gian duy trì tín hiệu cảm biến.
    
- Số cảm biến cùng phát hiện dấu hiệu nguy hiểm.
    
- Khả năng phân biệt khói sinh hoạt và khói từ tình huống nguy hiểm.
    
- Điều khiển actuator phù hợp với từng cấp độ cảnh báo.
    

Tuy nhiên, việc giảm mức cảnh báo trong các bối cảnh sinh hoạt không được làm mất các bảo vệ quan trọng khi có nguy hiểm thực sự.

Đây là hướng Future Work, chưa được triển khai trong firmware G2.

## 11. Reference – BibTeX

```
@article{rehman2021smartfire,
  author = {Abdul Rehman and Muhammad Ahmed Qureshi
            and Tariq Ali and others},
  title = {Smart Fire Detection and Deterrent System
           for Human Savior by Using Internet of Things (IoT)},
  journal = {Energies},
  volume = {14},
  number = {17},
  pages = {5500},
  year = {2021},
  doi = {10.3390/en14175500}
}
```

**Citation key:** `rehman2021smartfire`

**Recommendation:** Phù hợp cho Related Work, System Design, Discussion và Future Work.

**Source note:** Bài nghiên cứu có một số đoạn diễn đạt và thông tin cảm biến chưa hoàn toàn nhất quán. Khi viết báo cáo G2, nên ưu tiên mô tả phương pháp và kết quả chính được xác nhận rõ ràng, không sao chép các chi tiết mâu thuẫn về loại cảm biến hoặc thô