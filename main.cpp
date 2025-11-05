// main.cpp
#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QTimer>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool r = true;
    while (r){
        QuanLyNguoiDung qlnd;
        QuanLyHangHoa qlhh;
        QuanLyNhaCungCap qlncc;
        QuanLyPhieu qlp;
        const NguoiDung* currentUser = nullptr;
        LoginDialog l;
        bool loginSuccess = l.handleLogin(qlnd, qlhh, qlncc, qlp, &currentUser);

        if (!loginSuccess) {
            break;
        }
        MainWindow w(currentUser);
        w.show();
        a.exec();
        if (w.getCloseAction() == MainWindow::Logout) {
            r = true;
        }
        else r = false;
    }
    return 0;

}
