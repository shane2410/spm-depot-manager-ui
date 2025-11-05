#ifndef ADMINPANELWIDGET_H
#define ADMINPANELWIDGET_H

#include <QWidget>
#include "../backend_headers/QuanLyNguoiDung.h"

namespace Ui {
class AdminPanelWidget;
}

class AdminPanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPanelWidget(QuanLyNguoiDung& qlnd, const NguoiDung* currentUser, QWidget *parent = nullptr);
    ~AdminPanelWidget();

private slots:
    void on_addUserButton_clicked();
    void on_editUserButton_clicked();
    void on_deleteUserButton_clicked();
    void updateUserActionsState();

private:
    void loadUserTable();

    Ui::AdminPanelWidget *ui;
    QuanLyNguoiDung& m_qlnd_ref;
    const NguoiDung* m_currentUser;
};

#endif // ADMINPANELWIDGET_H
