#include "reportwidget.h"
#include "ui_reportwidget.h"
#include <QDate>
#include <QLocale>

ReportWidget::ReportWidget(QuanLyPhieu& qlp, QuanLyHangHoa& qlhh, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportWidget),
    m_qlp_ref(qlp),
    m_qlhh_ref(qlhh)
{
    ui->setupUi(this);
    setupInitialState();
}

ReportWidget::~ReportWidget()
{
    delete ui;
}

void ReportWidget::setupInitialState()
{
    ui->fromDateEdit->setDate(QDate::currentDate().addMonths(-1));
    ui->toDateEdit->setDate(QDate::currentDate());

    ui->revenueTable->horizontalHeader()->setStretchLastSection(true);
    ui->inventoryTable->horizontalHeader()->setStretchLastSection(true);

    loadInventoryReport();
}

void ReportWidget::on_viewReportButton_clicked()
{
    loadRevenueReport();
}

void ReportWidget::on_tabWidget_currentChanged(int index)
{
    if (index == 0) { // Revenue Tab
        loadRevenueReport();
    } else if (index == 1) { // Inventory Tab
        loadInventoryReport();
    }
}

void ReportWidget::loadRevenueReport()
{
    QDate fromQDate = ui->fromDateEdit->date();
    QDate toQDate = ui->toDateEdit->date();
    Date fromDate = {fromQDate.day(), fromQDate.month(), fromQDate.year()};
    Date toDate = {toQDate.day(), toQDate.month(), toQDate.year()};

    ui->revenueTable->setRowCount(0);
    double totalRevenue = 0;

    const LinkedList<PhieuXuat>& dsPX = m_qlp_ref.getDanhSachPhieuXuat();
    Node<PhieuXuat>* current = dsPX.getHead();

    while(current != nullptr)
    {
        Date ngayXuat = current->data.getNgayXuat();
        QDate ngayXuatQDate(ngayXuat.getYear(), ngayXuat.getMonth(), ngayXuat.getDay());

        if (ngayXuatQDate >= fromQDate && ngayXuatQDate <= toQDate) {
            int row = ui->revenueTable->rowCount();
            ui->revenueTable->insertRow(row);

            ui->revenueTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(current->data.getMaPhieuXuat())));
            ui->revenueTable->setItem(row, 1, new QTableWidgetItem(ngayXuatQDate.toString("dd/MM/yyyy")));
            ui->revenueTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(current->data.getTenKH())));

            double tongTien = current->data.getThanhTien();
            ui->revenueTable->setItem(row, 3, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(tongTien, 'f', 0)));
            totalRevenue += tongTien;
        }
        current = current->pNext;
    }
    ui->totalRevenueLabel->setText("Tổng Doanh thu: " + QLocale(QLocale::Vietnamese).toString(totalRevenue, 'f', 0) + " VND");
}

void ReportWidget::loadInventoryReport()
{
    ui->inventoryTable->setRowCount(0);
    const LinkedList<HangHoa>& dsHH = m_qlhh_ref.getDanhSach();
    Node<HangHoa>* current = dsHH.getHead();

    while(current != nullptr) {
        int row = ui->inventoryTable->rowCount();
        ui->inventoryTable->insertRow(row);
        ui->inventoryTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(current->data.getMaHH())));
        ui->inventoryTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(current->data.getTenHH())));
        ui->inventoryTable->setItem(row, 2, new QTableWidgetItem(QString::number(current->data.getSoLuongTon())));
        current = current->pNext;
    }
}
