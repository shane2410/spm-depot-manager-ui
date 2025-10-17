#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>


namespace Ui {class LoginUI;}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    QString getUsername() const;
    QString getPassword() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoginUI *ui;
};


#endif
