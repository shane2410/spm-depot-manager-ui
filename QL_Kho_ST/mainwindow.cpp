#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>


MainWindow::MainWindow(const NguoiDung* user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), nguoiDungHienTai(user)
{
    ui->setupUi(this);
    setupNavigation();
    loadData();
    connect(ui->navWidget, &QListWidget::currentRowChanged, this, &MainWindow::on_navWidget_currentRowChanged);
    if (nguoiDungHienTai){
        QString welcomeMessage = QString("Xin chào, %1").arg(QString::fromStdString(->getHoTen()));
        ui->welcomeLabel->setText(welcomeMessage);
    }
    ui->navWidget->setCurrentRow(0);

    if ( user->getVaiTro() != "quanly") {
        ui->navWidget->item(4)->setHidden(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupNavigation()
{
    ui->navWidget->addItem(new QListWidgetItem(QIcon(":/icons/dashboard.png"), "Tổng Quan"));
    ui->navWidget->addItem(new QListWidgetItem(QIcon(":/icons/product.png"), "Quản lý Hàng Hóa"));
    ui->navWidget->addItem(new QListWidgetItem(QIcon(":/icons/supplier.png"), "Quản lý Nhà Cung Cấp"));

}

void MainWindow::loadData()
{
    m_fileManager.docHangHoa(m_qlhh, "data/hanghoa.csv");
    m_fileManager.docNhaCungCap(m_qlncc, "data/nhacungcap.csv");
}

void MainWindow::on_navWidget_currentRowChanged(int currentRow)
{
    ui->contentStackedWidget->setCurrentIndex(currentRow);
}
