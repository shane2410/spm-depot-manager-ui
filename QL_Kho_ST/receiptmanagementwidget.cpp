#include "receiptmanagementwidget.h"
#include "qdatetime.h"
#include "ui_receiptmanagementwidget.h"
#include "receiptdialog.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QLocale>

ReceiptManagementWidget::ReceiptManagementWidget(QuanLyPhieu& qlp, QuanLyHangHoa& qlhh, QuanLyNhaCungCap& qlncc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiptManagementWidget),
    m_qlp_ref(qlp),
    m_qlhh_ref(qlhh),
    m_qlncc_ref(qlncc)
{
    ui->setupUi(this);
    setupTables();
    refreshTables();

    connect(ui->importReceiptsTable, &QTableWidget::itemSelectionChanged, this, &ReceiptManagementWidget::on_importReceiptsTable_itemSelectionChanged);
    connect(ui->exportReceiptsTable, &QTableWidget::itemSelectionChanged, this, &ReceiptManagementWidget::on_exportReceiptsTable_itemSelectionChanged);
}

ReceiptManagementWidget::~ReceiptManagementWidget()
{
    delete ui;
}

void ReceiptManagementWidget::setupTables()
{
    ui->importReceiptsTable->horizontalHeader()->setStretchLastSection(true);
    ui->importDetailsTable->horizontalHeader()->setStretchLastSection(true);
    ui->exportReceiptsTable->horizontalHeader()->setStretchLastSection(true);
    ui->exportDetailsTable->horizontalHeader()->setStretchLastSection(true);
}

void ReceiptManagementWidget::refreshTables()
{
    loadImportReceipts();
    loadExportReceipts();
    ui->importDetailsTable->setRowCount(0);
    ui->exportDetailsTable->setRowCount(0);
}

void ReceiptManagementWidget::loadImportReceipts()
{
    ui->importReceiptsTable->setRowCount(0);
    const LinkedList<PhieuNhap>& dsPN = m_qlp_ref.getDanhSachPhieuNhap();
    Node<PhieuNhap>* current = dsPN.getHead();

    while(current != nullptr) {
        int row = ui->importReceiptsTable->rowCount();
        ui->importReceiptsTable->insertRow(row);

        const PhieuNhap& pn = current->data;
        Date d = pn.getNgayNhap();
        QDate qd(d.getYear(), d.getMonth(), d.getDay());

        NhaCungCap* ncc = m_qlncc_ref.timKiemNhaCungCap(pn.getMaNCC());
        QString tenNCC = ncc ? QString::fromStdString(ncc->getTenNCC()) : "N/A";

        ui->importReceiptsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pn.getMaPhieuNhap())));
        ui->importReceiptsTable->setItem(row, 1, new QTableWidgetItem(qd.toString("dd/MM/yyyy")));
        ui->importReceiptsTable->setItem(row, 2, new QTableWidgetItem(tenNCC));
        ui->importReceiptsTable->setItem(row, 3, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(pn.getThanhTien(), 'f', 0)));

        current = current->pNext;
    }
}

void ReceiptManagementWidget::loadExportReceipts()
{
    ui->exportReceiptsTable->setRowCount(0);
    const LinkedList<PhieuXuat>& dsPX = m_qlp_ref.getDanhSachPhieuXuat();
    Node<PhieuXuat>* current = dsPX.getHead();

    while(current != nullptr) {
        int row = ui->exportReceiptsTable->rowCount();
        ui->exportReceiptsTable->insertRow(row);

        const PhieuXuat& px = current->data;
        Date d = px.getNgayXuat();
        QDate qd(d.getYear(), d.getMonth(), d.getDay());

        ui->exportReceiptsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(px.getMaPhieuXuat())));
        ui->exportReceiptsTable->setItem(row, 1, new QTableWidgetItem(qd.toString("dd/MM/yyyy")));
        ui->exportReceiptsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(px.getTenKH())));
        ui->exportReceiptsTable->setItem(row, 3, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(px.getThanhTien(), 'f', 0)));

        current = current->pNext;
    }
}


void ReceiptManagementWidget::on_createImportReceiptButton_clicked()
{
    ReceiptDialog dialog(ReceiptDialog::Import, m_qlhh_ref, m_qlncc_ref, this);
    if(dialog.exec() == QDialog::Accepted) {
        PhieuNhap pn = dialog.getPhieuNhapData();
        if(m_qlp_ref.taoPhieuNhap(pn, m_qlhh_ref)) {
            refreshTables();
            QMessageBox::information(this, "Thành công", "Tạo phiếu nhập thành công.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Không thể tạo phiếu nhập. Vui lòng kiểm tra lại thông tin.");
        }
    }
}

void ReceiptManagementWidget::on_createExportReceiptButton_clicked()
{
    ReceiptDialog dialog(ReceiptDialog::Export, m_qlhh_ref, m_qlncc_ref, this);
    if(dialog.exec() == QDialog::Accepted) {
        PhieuXuat px = dialog.getPhieuXuatData();
        if(m_qlp_ref.taoPhieuXuat(px, m_qlhh_ref)) {
            refreshTables();
            QMessageBox::information(this, "Thành công", "Tạo phiếu xuất thành công.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Không thể tạo phiếu xuất. Vui lòng kiểm tra lại thông tin, có thể do không đủ hàng tồn kho.");
        }
    }
}

void ReceiptManagementWidget::on_importReceiptsTable_itemSelectionChanged()
{
    int currentRow = ui->importReceiptsTable->currentRow();
    if(currentRow < 0) return;
    std::string maPhieu = ui->importReceiptsTable->item(currentRow, 0)->text().toStdString();
    showImportReceiptDetails(maPhieu);
}

void ReceiptManagementWidget::on_exportReceiptsTable_itemSelectionChanged()
{
    int currentRow = ui->exportReceiptsTable->currentRow();
    if(currentRow < 0) return;
    std::string maPhieu = ui->exportReceiptsTable->item(currentRow, 0)->text().toStdString();
    showExportReceiptDetails(maPhieu);
}


void ReceiptManagementWidget::showImportReceiptDetails(const std::string& maPhieu)
{
    ui->importDetailsTable->setRowCount(0);
    PhieuNhap* pn = m_qlp_ref.timPhieuNhap(maPhieu);
    if (!pn) return;

    const LinkedList<ChitietPhieuNhap>& dsCT = pn->getDsCTPN();
    Node<ChitietPhieuNhap>* current = dsCT.getHead();
    while (current != nullptr) {
        int row = ui->importDetailsTable->rowCount();
        ui->importDetailsTable->insertRow(row);

        const ChitietPhieuNhap& ct = current->data;
        HangHoa* hh = m_qlhh_ref.layHangHoaTheoMa(ct.maHH);
        QString tenHH = hh ? QString::fromStdString(hh->getTenHH()) : "Không tìm thấy";

        ui->importDetailsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(ct.maHH)));
        ui->importDetailsTable->setItem(row, 1, new QTableWidgetItem(tenHH));
        ui->importDetailsTable->setItem(row, 2, new QTableWidgetItem(QString::number(ct.soLuong)));
        ui->importDetailsTable->setItem(row, 3, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(ct.donGiaNhap, 'f', 0)));
        ui->importDetailsTable->setItem(row, 4, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(ct.soLuong * ct.donGiaNhap, 'f', 0)));

        current = current->pNext;
    }
}

void ReceiptManagementWidget::showExportReceiptDetails(const std::string& maPhieu)
{
    ui->exportDetailsTable->setRowCount(0);
    PhieuXuat* px = m_qlp_ref.timPhieuXuat(maPhieu);
    if (!px) return;

    const LinkedList<ChitietPhieuXuat>& dsCT = px->getDsCTPX();
    Node<ChitietPhieuXuat>* current = dsCT.getHead();
    while (current != nullptr) {
        int row = ui->exportDetailsTable->rowCount();
        ui->exportDetailsTable->insertRow(row);

        const ChitietPhieuXuat& ct = current->data;
        HangHoa* hh = m_qlhh_ref.layHangHoaTheoMa(ct.maHH);
        QString tenHH = hh ? QString::fromStdString(hh->getTenHH()) : "Không tìm thấy";

        ui->exportDetailsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(ct.maHH)));
        ui->exportDetailsTable->setItem(row, 1, new QTableWidgetItem(tenHH));
        ui->exportDetailsTable->setItem(row, 2, new QTableWidgetItem(QString::number(ct.soLuong)));
        ui->exportDetailsTable->setItem(row, 3, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(ct.donGiaBan, 'f', 0)));
        ui->exportDetailsTable->setItem(row, 4, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(ct.soLuong * ct.donGiaBan, 'f', 0)));

        current = current->pNext;
    }
}
