#include <QPushButton>
#include <QMessageBox>
#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginUI)
{
    ui->setupUi(this);
    ui->errorLabel->setText("");

    QPushButton *loginButton = ui->buttonBox->button(QDialogButtonBox::Ok);

    if (loginButton) {
        loginButton->setText("Đăng nhập");
        loginButton->setIcon(QIcon());
    }
}

LoginDialog::~LoginDialog() { delete ui; }

QString LoginDialog::getUsername() const {
    return ui->usernameLineEdit->text();
}

QString LoginDialog::getPassword() const {
    return ui->passwordLineEdit->text();
}

void LoginDialog::on_buttonBox_accepted()
{
    accept();
}


bool LoginDialog::handleLogin(QuanLyNguoiDung &qlnd,
                 QuanLyHangHoa &qlhh,
                 QuanLyNhaCungCap &qlncc,
                 QuanLyPhieu &qlp,
                              const NguoiDung** outUser){
    if (FileManager::isFirstRun()) {
        QMessageBox::information(nullptr, // parent là nullptr vì chưa có cửa sổ nào
                                 "Chào mừng đến với Hệ thống",
                                 "Đây là lần đầu tiên bạn chạy ứng dụng.\n\n"
                                 "Một tài khoản Quản trị viên mặc định đã được tạo:\n"
                                 "   - Tên đăng nhập: admin\n"
                                 "   - Mật khẩu: admin\n\n"
                                 "Vui lòng sử dụng tài khoản này để đăng nhập lần đầu tiên.");
    }


    FileManager fm;
    fm.docTatCaDuLieu(qlhh, qlncc, qlp, qlnd);

    LoginDialog loginDialog;
    const NguoiDung* currentUser = nullptr;

    while (true) {
        if (loginDialog.exec() == QDialog::Accepted) {
            std::string username = loginDialog.getUsername().toStdString();
            std::string password = loginDialog.getPassword().toStdString();

            currentUser = qlnd.kiemtradangnhap(username, password);
            if (currentUser != nullptr) {
                *outUser = currentUser;
                return true;
            } else {
                QMessageBox::warning(&loginDialog, "Lỗi", "Sai tên đăng nhập hoặc mật khẩu!");
            }
        } else {
            return false;
        }
    }

}
