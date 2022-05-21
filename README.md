# **ArkanoidGame** 
## **Video mô tả game**
[Link](https://youtu.be/eIV05z9agxQ)

## **Hướng dẫn xây dựng**
---
### *Yêu cầu:*
* Visual Studio Code ( hoặc bất kì trình biên dịch C++ nào khác, ở đây tôi sử dụng Visual Studio Code ) 
.* Mingw32 ( phiên bản 7.3.0 )
* Thư viện SFML
### *Cách chạy chương trình:*
* Mở Visual Studio Code => Terminal => New Terminal
* Gõ lệnh: 
###
``` 
    git clone https://github.com/KhoiSniper/ArknoidGame.git 
```
* Lệnh chạy xong, một folder mới được tạo 
* Tại giao diện Visual Studio Code, chọn File => Open Folfder => chọn      folder được tạo bên trên => Open;
* Sau khi mở được folder, di chuyển xuống Terminal, gõ 2 lệnh sau:
```
    mingw32-make
    ./sfml-app.exe
```
---
## **Mô tả chung:**
* Game sử dụng các phím điều hướng để điều khiển;
* Các thành phần game: ball, paddle, brick, các item phụ;
* Ý tưởng chính: Game gồm các thành phần như trên. Người chơi điều khiển paddle thông qua các phím, sao cho quả bóng không rơi xuống và phá hủy các viên gạch được xếp ở phía trên. Mỗi khi phá hủy được các viên gạch ngẫu nhiên, các item phụ sẽ rơi xuống, nếu paddle nhặt được các item này thì sẽ xảy ra các thay đổi về các thành phần game.
## **Các chức năng đã cài đặt**
### Cấu trúc game: Game có đủ các trạng thái cơ bản:
####
* MenuState;
* GamePlayState;
* GameOverState
### Mô tả :
* #### MenuState: Có ba nút:
    * Play  :    Chuyển sang trạng thái GamePlay;
    * Score:    Hiển thị điểm cao nhất;
    * Exit   :   Thoát game ; 
* #### GamePlayState                 :  Xử lý trò chơi
* #### GameOverState: Có 2 nút:
   * Replay:   Quay lại GamePlayState
   * Exit     :   Thoát
## **Kỹ thuật lập trình được sử dụng**
* Lập trình đồ họa
* Class
* Mảng
* Hàm
* Các biến đếm, biến cắm cờ (bool)
## **Kết luận**
* Game cơ bản đã có đủ các cấu trúc của 1 game. 
* Tuy nhiên, do không sử dụng con trỏ, cấu trúc game chưa được tốt và tối ưu hóa nhất.
* Kịch bản game còn khá đơn giản, đồ họa chưa đẹp, các item chưa đa dạng
* Vẫn tồn tại một số lỗi trong chương trình game như:
* Bóng chạm vào gạch không đổi hướng
* Khi paddle đỡ được item phụ thì không tiến hành update (xảy ra với item addLives khi countLive=3)
* Hướng phát triển:
	* Sửa các lỗi như đã nói bên trên
	* Nâng cấp đồ họa game cho bắt mắt hơn
    * Xây dựng chương trình game với nhiều level
    * Thêm các item phụ, các kịch bản mới thú vị hơn



		
