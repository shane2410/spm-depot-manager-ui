#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "../backend_headers/NguoiDung.h"
#include "../backend_headers/QuanLyHangHoa.h"
#include "../backend_headers/QuanLyNhaCungCap.h"
#include "../backend_headers/QuanLyPhieu.h"
#include "../backend_headers/FileManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(NguoiDung& user, QWidget *parent = nullptr);
    explicit MainWindow(const NguoiDung* user, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_navWidget_currentRowChanged(int currentRow);
    void on_logoutButton_clicked();

private:
    void setupNavigation();
    void loadData();
    Ui::MainWindow *ui;
    const NguoiDung* nguoiDungHienTai;
    QuanLyHangHoa m_qlhh;
    QuanLyNhaCungCap m_qlncc;
    QuanLyPhieu m_qlp;
    FileManager m_fileManager;
};
#endif // MAINWINDOW_H
