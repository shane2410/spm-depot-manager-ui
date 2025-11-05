#include "userdialog.h"
#include "ui_userdialog.h"

UserDialog::UserDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
    setWindowTitle("Thêm Người Dùng Mới");
}

UserDialog::UserDialog(const NguoiDung &userToEdit, QWidget *parent)
    : QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
    setWindowTitle("Cập nhật Người Dùng");
    setUserData(userToEdit);
    ui->usernameEdit->setReadOnly(true);
    ui->passwordEdit->setPlaceholderText("[Không đổi]");
}

UserDialog::~UserDialog() { delete ui; }

void UserDialog::setUserData(const NguoiDung &user) {
    m_originalUsername = user.getTenDangNhap();
    ui->usernameEdit->setText(QString::fromStdString(user.getTenDangNhap()));
    ui->fullNameEdit->setText(QString::fromStdString(user.getHoTen()));
    ui->roleComboBox->setCurrentText(QString::fromStdString(user.getVaiTro()));
}

NguoiDung UserDialog::getUserData() const {
    std::string username = ui->usernameEdit->isReadOnly()
                               ? m_originalUsername
                               : ui->usernameEdit->text().toStdString();
    std::string password = ui->passwordEdit->text().toStdString();
    std::string fullName = ui->fullNameEdit->text().toStdString();
    std::string role = ui->roleComboBox->currentText().toStdString();

    NguoiDung user(username, "", fullName, role);
    if (!password.empty()) {
        user.setMatKhau(password);
    }

    return user;
}