# Tetris

- Ngôn ngữ: C++, SDL
- Cách download và chạy code
    + Cài git
    + Clone repo về máy
    + Chạy file Tetris.exe
- About Tetris Game
    + Tham khảo https://tetris.com/
    + Cách chơi: 
        Mục tiêu của trò chơi là di chuyển các khối gạch đang rơi từ từ xuống trong kích thước hình chữ nhật 20 hàng x 10 cột (trên màn hình). Chỗ nào có gạch rồi thì không di chuyển được tới vị trí đó. Người chơi xếp những khối hình sao cho khối hình lấp đầy 1 hàng ngang để ghi điểm và hàng ngang ấy sẽ biến mất.

        Ta có ba bảng:

            Một bảng chính gồm 22 * 12 dòng. Ta chỉ thể hiện ra 20 * 10 dòng. Còn lại hai dòng và hai cột trên cùng và dưới cùng được dùng là biên giới của bảng để check việc di chuyển của các block.

            Một bảng Next: thể hiện khối block tiếp theo sẽ xuất hiện.

            Một bảng Score trong đó:
                 Ô Score: là ghi số điểm hiện có.
                 Ô Line: là ghi số dòng đã tạo được.

        Nếu để cho những block cao quá màn hình, trò chơi sẽ kết thúc.

        Trò chơi kết thúc khi block không rơi xuống được nữa.

    + Phím tắt:
        
        + Phím mũi tên lên: xoay khối.
        + Phím mũi tên trái: di chuyển sang trái.
        + Phím mũi tên phải: di chuyển sang phải.
        + Phím mũi tên xuống: tăng tốc độ rơi.

- Cấu trúc Tetris game:
    
    + Các file header là để khai báo
    + Các file .cpp là để viết các hàm
    + Folder SDL chứa những thứ liên quan đến SDL: như font, include, lib
    + Folder image chứa những ảnh cần cho game
    + Folder music chứa những âm thanh cần cho game

    // gọi tắt các file x.cpp và x.hpp là x 
    + file common.hpp là để khai báo những biến dùng cho toàn cục.
    + file main.cpp là để khởi tạo và chạy vòng lặp game
    + file game là để xử lý những thứ liên quan đến game: 
        
        ví dụ như: trước khi chơi game thì có những phương thức, thuộc tính gì, trong khi chơi thì có những sự kiện, hàm xử lý gì.

    + file object là thiết lập các thuộc tính, phương thức của một đối tượng như: setRenderer, loadTexture...
    + file board là thiết lập các thuộc tính, phương thức của bảng chơi như: updateBoard, showBoard, resetBoard...
    + file block là thiết lập các thuộc tính, phương thức của các khối block như: khởi tạo, rotate
    
