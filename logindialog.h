#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>
#include "../backend_headers/NguoiDung.h"
#include "../backend_headers/FileManager.h"


namespace Ui {class LoginUI;}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    QString getUsername() const;
    QString getPassword() const;

    bool handleLogin(QuanLyNguoiDung &qlnd,
                      QuanLyHangHoa &qlhh,
                      QuanLyNhaCungCap &qlncc,
                      QuanLyPhieu &qlp,
                     const NguoiDung** currentUser);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoginUI *ui;
};


#endif
