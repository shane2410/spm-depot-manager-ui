// main.cpp
#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QMessageBox>

#include "../backend_headers/QuanLyNguoiDung.h"
#include "../backend_headers/FileManager.h"
#include "../backend_headers/NguoiDung.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QuanLyNguoiDung qlnd;
    FileManager fileManager;

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

            nguoiDungHienTai = qlnd.kiemtradangnhap(username, password);

            if (nguoiDungHienTai != nullptr) {
                break;
            } else {
                QMessageBox::warning(&loginDialog, "Đăng nhập thất bại", "Sai tên đăng nhập hoặc mật khẩu!");
            }
        } else {
            return 0;
        }
    }

    MainWindow w(nguoiDungHienTai);
    w.show();
    return a.exec();
}
