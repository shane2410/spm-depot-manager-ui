#ifndef USERDIALOG_H
#define USERDIALOG_H

#include "../backend_headers/NguoiDung.h"
#include <QDialog>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog {
    Q_OBJECT

  public:
    explicit UserDialog(QWidget *parent = nullptr);
    UserDialog(const NguoiDung &userToEdit, QWidget *parent = nullptr);
    ~UserDialog();

    NguoiDung getUserData() const;

  private:
    void setUserData(const NguoiDung &user);

    Ui::UserDialog *ui;
    std::string m_originalUsername;
};

#endif // USERDIALOG_H
