# Tetris Game

Tetris là một trò chơi xếp hình cổ điển được phát minh bởi Alexey Pajitnov vào năm 1984. Trong trò chơi này, bạn sẽ điều khiển các khối hình (tetrominoes) rơi từ trên xuống và cố gắng xếp chúng sao cho tạo thành các hàng đầy đủ. Khi một hàng đầy được tạo ra, nó sẽ bị xóa và bạn sẽ nhận điểm. Mục tiêu của trò chơi là đạt điểm số cao nhất có thể trước khi các khối hình không còn đủ chỗ để rơi xuống.
## VIDEO TRÌNH BÀY VÀ TRẢI NGHIỆM GAME : https://l.facebook.com/l.php?u=https%3A%2F%2Fdrive.google.com%2Ffile%2Fd%2F1hgwkyopnLB1y1vGHMvWsgI95xzvpepQa%2Fview%3Fusp%3Ddrive_link%26fbclid%3DIwZXh0bgNhZW0CMTAAAR0h7cM3ZiO_tKsgU7EtGdshCApznPRr_vp58GmmwXnCZv-YVFmpbieJGkU_aem_U58JIo7sudwSB0PVTWI8UA&h=AT1yGAebn15X_0jz1dtl1hCotelCMn444Rwl3VrpjvpIT8iAh8tdzJ-r4E0n7Ao0SbpSVG1qA1-2bSq8r8go0toCj6ZBCf6H-he5HABIZrr2aTxIRHmEogS-saFbBiMqM1nzcdlmHy1_PQ9zfgcAOwtFb0c

## Tính năng

- **Khối hình đa dạng:** Bao gồm bảy loại tetrominoes với các hình dạng khác nhau (I, O, T, S, Z, J, L).
- **Điều khiển dễ dàng:** Sử dụng các phím mũi tên để di chuyển và xoay các khối hình.
- **Cập nhật điểm số:** Tính điểm dựa trên số lượng hàng đầy được xóa.
- **Thiết kế tối ưu:** Đồ họa đơn giản và dễ sử dụng với hiệu ứng âm thanh đặc trưng.
- **Tính năng tự phát triển thêm:** thay đổi BACKGROUD và tự thiết kế lại các khối , đã phát triển thêm tính năng ( LINE : tính số dòng đã ăn được ) và tính năng LƯU LẠI BEST SCORE ( BEST ) 

## Cài đặt

# Tetris Game

 Trò chơi này được xây dựng bằng SDL2.

## Cài đặt

### Prerequisites

Trước khi cài đặt, hãy đảm bảo rằng bạn đã cài đặt các công cụ và thư viện cần thiết:

- **CMake**: Công cụ để quản lý cấu hình dự án.
- **SDL2**: Thư viện đa phương tiện để phát triển trò chơi.

#### Cài đặt SDL2

- **Trên Ubuntu/Debian:**
  ```bash
  sudo apt-get update
  sudo apt-get install libsdl2-dev


1. **Clone Repository:**
   ```bash
   sau đó bạn có thể tải mã nguồn từ link sau :git clone https://github.com/letuan1904/game.git
   ## Lưu ý

Hãy kiểm tra bạn đã cài đặt môi trường và thư viện (SDL/SDL2) chưa trước khi tiến hành cài đặt và biên dịch trò chơi.
# Hướng Dẫn Chơi Tetris

Tetris là một trò chơi xếp hình cổ điển với lối chơi đơn giản nhưng cuốn hút. Mục tiêu của trò chơi là xếp các khối hình (gọi là tetrominoes) sao cho tạo thành các hàng đầy đủ và không có khoảng trống. Khi một hàng đầy được tạo ra, nó sẽ bị xóa và bạn sẽ nhận được điểm. Trò chơi sẽ kết thúc khi các khối hình xếp chồng lên quá cao và không còn chỗ cho các khối mới.

## Mục Tiêu

- **Xếp Hình:** Tạo ra các hàng ngang đầy đủ bằng cách sắp xếp các khối tetrominoes rơi từ trên xuống.
- **Tích Lũy Điểm:** Mỗi lần xóa một hàng, bạn sẽ nhận được điểm. Cố gắng xóa càng nhiều hàng cùng một lúc càng tốt để nhận thêm điểm thưởng.
- **Sinh Tồn:** Trò chơi sẽ kết thúc nếu các khối hình chạm đến đỉnh của màn hình. Mục tiêu là sống sót càng lâu càng tốt và đạt điểm số cao nhất có thể.

## Các Khối Hình (Tetrominoes)

Có bảy loại tetrominoes trong Tetris, mỗi loại có hình dạng và màu sắc khác nhau:

- **I-Tetromino:** Hình thanh dài với 4 ô vuông liên tiếp.
- **O-Tetromino:** Hình vuông 2x2.
- **T-Tetromino:** Hình chữ T.
- **S-Tetromino:** Hình zigzag hướng về bên trái.
- **Z-Tetromino:** Hình zigzag hướng về bên phải.
- **J-Tetromino:** Hình chữ L ngược.
- **L-Tetromino:** Hình chữ L.

## Điều Khiển

- **Mũi tên trái (←):** Di chuyển khối tetromino sang trái.
- **Mũi tên phải (→):** Di chuyển khối tetromino sang phải.
- **Mũi tên lên (↑):** Xoay khối tetromino theo chiều kim đồng hồ.
- **Mũi tên xuống (↓):** Tăng tốc độ rơi của khối tetromino.
- **Phím Space:** Thả nhanh khối tetromino xuống dưới cùng.
- **Phím P:** Tạm dừng hoặc tiếp tục trò chơi.
  
## Chiến Thuật

- **Tạo Tetris:** Tetris là khi bạn xóa bốn hàng cùng một lúc bằng cách xếp các I-Tetromino dọc. Đây là cách để ghi được điểm cao nhất.
- **Giữ Trung Tâm:** Giữ trung tâm của màn hình chơi càng trống càng tốt để dễ dàng xếp các khối tetromino lớn.
- **Dự Trữ Khối Hình:** Sử dụng chức năng "giữ" (nếu có) để lưu trữ các khối tetromino mà bạn chưa muốn sử dụng ngay. Điều này giúp bạn chuẩn bị cho các tình huống sau này.
- **Xoay Khối Hình:** Xoay các khối tetromino để tìm cách xếp chúng vào các khoảng trống chật hẹp.

## Cấp Độ và Tăng Độ Khó

- **Tăng Cấp:** Trò chơi sẽ tăng cấp sau khi bạn xóa một số hàng nhất định. Khi cấp độ tăng, tốc độ rơi của các khối tetromino sẽ nhanh hơn, khiến trò chơi trở nên khó khăn hơn.
- **Độ Khó Tăng Dần:** Ban đầu, trò chơi sẽ khá dễ nhưng sẽ trở nên khó hơn khi bạn chơi lâu hơn và tốc độ rơi của các khối tăng lên.

## Kết Thúc Trò Chơi

- **Trò Chơi Kết Thúc:** Khi các khối tetromino xếp chồng lên đến đỉnh của màn hình, trò chơi sẽ kết thúc. Điểm số cuối cùng của bạn sẽ được tính dựa trên số hàng đã xóa và số điểm tích lũy được.

## Mẹo và Thủ Thuật

- **Luyện Tập Xoay:** Tập trung luyện tập xoay các khối tetromino, đặc biệt là trong không gian hẹp, để tối ưu hóa cách xếp.
- **Nhìn Trước Khối Tiếp Theo:** Luôn chú ý đến khối tetromino tiếp theo để chuẩn bị trước cho bước di chuyển của bạn.
- **Đừng Sợ Hãy Xóa Ít Hàng:** Nếu cần, hãy xóa ít hàng hơn để tránh tạo ra khoảng trống khó lấp đầy.

---

Hãy thử thách bản thân và xem bạn có thể đạt được điểm số bao nhiêu trong Tetris! Chúc bạn chơi vui vẻ!
## Hướng dẫn chi tiết 
<img width="564" alt="Screenshot 2024-08-18 at 14 45 02" src="https://github.com/user-attachments/assets/d0874645-b7f0-46b7-8663-49af9a9a25dd">.<br>
## - **Giao diện trò chơi:** Khi thấy giao diện này, kéo thả chuột để di chuyển giao diện. Nếu muốn chơi, hãy nhấn vào **START** và ấn **ENTER**. Ngược lại, nếu không muốn chơi, hãy nhấn **EXIT** và ấn **ENTER**.<br>
## Tiếp theo sẽ xuất hiện giao diện như sau:.<br>
<img width="554" alt="Screenshot 2024-08-18 at 14 45 25" src="https://github.com/user-attachments/assets/a015dd70-a5b2-4dc0-b7c8-23f3e3d88a52">.<br>
## Như các bạn thấy, màn hình được chia làm 2 phần: bên trái và bên phải. Bên trái là màn hình chơi, bên phải là nơi thể hiện những thông số.<br>
## Bên trái từ trên xuống dưới gồm next( hiển thị các hình tiếp theo xuất hiện ) , line ( thể hiện số dòng bạn đã ăn được ) , score ( thể hiện điểm bạn đã giành được ) , best ( thể hiện điểm tốt nhất từ trước đến nay ).<br>
## tiếp theo.<br>
<img width="552" alt="Screenshot 2024-08-18 at 14 46 13" src="https://github.com/user-attachments/assets/e3c86daa-1f96-4290-8a0c-eb657391875f">.<br>
## đây là giao diện thua cuộc , khi bạn đã lấp đầy màn hình chơi ( các khối chạm và biên giới trên cùng của màn hình chơi ).<br>  
## tới đây , nếu bạn muốn quay trở lại bảng chọn ban đầu , hãy ấn ( SPACE )







