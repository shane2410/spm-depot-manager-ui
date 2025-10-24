#include <QPushButton>
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
