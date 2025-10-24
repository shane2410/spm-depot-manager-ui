#include "mainwindow.h"
#include "../backend_headers/FileManager.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QIcon>
#include <QListWidgetItem>
#include <QMessageBox>

#include "adminpanelwidget.h"
#include "dashboardwidget.h"
#include "productmanagementwidget.h"
#include "receiptmanagementwidget.h"
#include "reportwidget.h"
#include "suppliermanagementwidget.h"

MainWindow::MainWindow(const NguoiDung *user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_currentUser(user) {
    ui->setupUi(this);

    loadAllData();
    setupNavigation();
    setupContentWidgets();

    connect(ui->navWidget, &QListWidget::currentRowChanged, this,
            &MainWindow::on_navWidget_currentRowChanged);

    if (m_currentUser) {
        ui->welcomeLabel->setText(
            QString("Xin chào, %1")
                .arg(QString::fromStdString(m_currentUser->getHoTen())));
    }

    ui->navWidget->setCurrentRow(0);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question(
        this, "Xác nhận thoát",
        "Bạn có muốn lưu lại tất cả thay đổi trước khi thoát?",
        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
        QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        saveAllData();
        event->accept();
    } else if (resBtn == QMessageBox::No) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::loadAllData() {
    FileManager fm;
    fm.docTatCaDuLieu(m_qlhh, m_qlncc, m_qlp, m_qlnd);
    ui->statusbar->showMessage("Tải dữ liệu thành công.", 3000);
}

void MainWindow::saveAllData() {
    FileManager fm;
    fm.ghiTatCaDuLieu(m_qlhh, m_qlncc, m_qlnd);
    ui->statusbar->showMessage("Đang lưu dữ liệu...", 2000);
    ui->statusbar->showMessage("Lưu dữ liệu thành công.", 3000);
}

void MainWindow::setupNavigation() {
    ui->navWidget->addItem(
        new QListWidgetItem(QIcon(":/icons/dashboard.png"), "📈 Tổng Quan"));
    ui->navWidget->addItem(new QListWidgetItem(QIcon(":/icons/product.png"),
                                               "📦 Quản lý Hàng Hóa"));
    ui->navWidget->addItem(
        new QListWidgetItem(QIcon(":/icons/supplier.png"), "🚚 Quản lý NCC"));
    ui->navWidget->addItem(new QListWidgetItem(QIcon(":/icons/import.png"),
                                               "📥 Quản lý Nhập Kho"));
    ui->navWidget->addItem(new QListWidgetItem(QIcon(":/icons/export.png"),
                                               "📤 Quản lý Xuất Kho"));
    ui->navWidget->addItem(
        new QListWidgetItem(QIcon(":/icons/report.png"), "📊 Báo cáo & TK"));

    if (m_currentUser && m_currentUser->getVaiTro() == "quanly") {
        ui->navWidget->addItem(new QListWidgetItem(QIcon(":/icons/admin.png"),
                                                   "⚙️ Quản trị Hệ thống"));
    }
}

void MainWindow::setupContentWidgets() {
    ui->contentStackedWidget->addWidget(
        new DashboardWidget(m_qlhh, m_qlp, this));
    ui->contentStackedWidget->addWidget(
        new ProductManagementWidget(m_qlhh, m_qlncc, this));
    ui->contentStackedWidget->addWidget(
        new SupplierManagementWidget(m_qlncc, this));
    ui->contentStackedWidget->addWidget(
        new ReceiptManagementWidget(m_qlp, m_qlhh, m_qlncc, this));
    ui->contentStackedWidget->addWidget(new ReportWidget(m_qlp, m_qlhh, this));

    if (m_currentUser && m_currentUser->getVaiTro() == "quanly") {
        ui->contentStackedWidget->addWidget(new AdminPanelWidget(m_qlnd, m_currentUser, this));
    }
}

void MainWindow::on_navWidget_currentRowChanged(int currentRow) {
    if (currentRow >= 0 && currentRow < ui->contentStackedWidget->count()) {
        ui->contentStackedWidget->setCurrentIndex(currentRow);
    }
}

void MainWindow::on_logoutButton_clicked() {
    QMessageBox::information(this, "Đăng xuất", "Bạn đã đăng xuất thành công.");
    close();
}
