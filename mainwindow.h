#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../backend_headers/NguoiDung.h"
#include "../backend_headers/QuanLyNguoiDung.h"
#include "../backend_headers/QuanLyHangHoa.h"
#include "../backend_headers/QuanLyNhaCungCap.h"
#include "../backend_headers/QuanLyPhieu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void logoutRequested();
public:
    explicit MainWindow(const NguoiDung* user, QWidget *parent = nullptr);
    ~MainWindow();
    enum CloseAction { Shutdown, Logout };
    CloseAction getCloseAction() const;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_navWidget_currentRowChanged(int currentRow);
    void on_logoutButton_clicked();

private:
    CloseAction m_closeAction;
    void setupNavigation();
    void loadAllData();
    void saveAllData();
    void setupContentWidgets();

    Ui::MainWindow *ui;
    const NguoiDung* m_currentUser;

    QuanLyNguoiDung m_qlnd;
    QuanLyHangHoa m_qlhh;
    QuanLyNhaCungCap m_qlncc;
    QuanLyPhieu m_qlp;
};

#endif // MAINWINDOW_H
