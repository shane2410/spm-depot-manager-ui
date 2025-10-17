// main.cpp
#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QMessageBox>

// Include các lớp backend cần thiết
#include "../backend_headers/QuanLyNguoiDung.h"
#include "../backend_headers/FileManager.h"
#include "../backend_headers/NguoiDung.h" // Cần để sử dụng đối tượng NguoiDung

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. Khởi tạo các đối tượng quản lý
    QuanLyNguoiDung qlnd;
    FileManager fileManager;

    // 2. Đọc dữ liệu người dùng từ file
    if (!fileManager.docNguoiDung(qlnd, "data/nguoidung.csv")) {
        QMessageBox::critical(nullptr, "Lỗi nghiêm trọng", "Không thể tải dữ liệu người dùng. Vui lòng kiểm tra file data/nguoidung.csv.");
        return -1;
    }

    LoginDialog loginDialog;
    const NguoiDung* nguoiDungHienTai = nullptr;

    while (true) {
        if (loginDialog.exec() == QDialog::Accepted) {
            std::string username = loginDialog.getUsername().toStdString();
            std::string password = loginDialog.getPassword().toStdString();

            // 3. Sử dụng QuanLyNguoiDung để kiểm tra
            nguoiDungHienTai = qlnd.kiemTraDangNhap(username, password);

            if (nguoiDungHienTai != nullptr) {
                // Đăng nhập thành công!
                break; // Thoát vòng lặp
            } else {
                QMessageBox::warning(&loginDialog, "Đăng nhập thất bại", "Sai tên đăng nhập hoặc mật khẩu!");
            }
        } else {
            // Người dùng nhấn Cancel hoặc đóng dialog
            return 0;
        }
    }

    // 4. Khởi tạo MainWindow và truyền thông tin người dùng vào
    MainWindow w(nguoiDungHienTai); // Truyền con trỏ người dùng vào MainWindow
    w.show();
    return a.exec();
}
