#include "receiptdialog.h"
#include "ui_receiptdialog.h"
#include <QMessageBox>
#include <QLocale>

ReceiptDialog::ReceiptDialog(DialogMode mode, QuanLyHangHoa& qlhh, QuanLyNhaCungCap& qlncc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiptDialog),
    m_mode(mode),
    m_qlhh_ref(qlhh),
    m_qlncc_ref(qlncc),
    m_foundProduct(nullptr)
{
    ui->setupUi(this);
    setupUiForMode();

    connect(ui->maHHEdit, &QLineEdit::returnPressed, this, &ReceiptDialog::on_findProductButton_clicked);
}

ReceiptDialog::~ReceiptDialog()
{
    delete ui;
}

void ReceiptDialog::setupUiForMode()
{
    ui->ngayLapDateEdit->setDate(QDate::currentDate());
    generateNewReceiptId();
    ui->detailsTable->setColumnCount(5);
    QStringList headers = {"Mã HH", "Tên Hàng Hóa", "Số Lượng", "Đơn Giá", "Thành Tiền"};
    ui->detailsTable->setHorizontalHeaderLabels(headers);
    ui->detailsTable->horizontalHeader()->setStretchLastSection(true);

    if (m_mode == Import) {
        setWindowTitle("Tạo Phiếu Nhập Mới");
        ui->providerCustomerLabel->setText("Nhà Cung Cấp:");
        ui->khachHangEdit->hide();
        populateNccComboBox();
    } else { // Export
        setWindowTitle("Tạo Phiếu Xuất Mới");
        ui->providerCustomerLabel->setText("Tên Khách Hàng:");
        ui->nccComboBox->hide();
    }
}

void ReceiptDialog::generateNewReceiptId()
{
    // Basic ID generation, should be improved for real apps
    qint64 id = QDateTime::currentMSecsSinceEpoch();
    if (m_mode == Import) {
        ui->maPhieuEdit->setText(QString("PN%1").arg(id));
    } else {
        ui->maPhieuEdit->setText(QString("PX%1").arg(id));
    }
}


void ReceiptDialog::populateNccComboBox()
{
    const LinkedList<NhaCungCap>& dsNcc = m_qlncc_ref.getDanhSach();
    Node<NhaCungCap>* current = dsNcc.getHead();
    while(current != nullptr) {
        ui->nccComboBox->addItem(QString::fromStdString(current->data.getTenNCC()),
                                 QString::fromStdString(current->data.getMaNCC()));
        current = current->pNext;
    }
}

void ReceiptDialog::on_findProductButton_clicked()
{
    std::string maHH = ui->maHHEdit->text().toStdString();
    if (maHH.empty()) return;

    m_foundProduct = m_qlhh_ref.layHangHoaTheoMa(maHH);
    if (m_foundProduct) {
        ui->tenHHLabel->setText(QString::fromStdString(m_foundProduct->getTenHH()));
        ui->soLuongSpinBox->setEnabled(true);
        ui->addItemButton->setEnabled(true);
        ui->soLuongSpinBox->setFocus();

        if (m_mode == Export) {
            ui->soLuongSpinBox->setMaximum(m_foundProduct->getSoLuongTon());
        }

    } else {
        ui->tenHHLabel->setText("<font color='red'>Không tìm thấy!</font>");
        m_foundProduct = nullptr;
        ui->soLuongSpinBox->setEnabled(false);
        ui->addItemButton->setEnabled(false);
    }
}

void ReceiptDialog::on_addItemButton_clicked()
{
    if (!m_foundProduct) {
        QMessageBox::warning(this, "Chưa chọn hàng", "Vui lòng tìm một mã hàng hóa hợp lệ trước.");
        return;
    }

    int soLuong = ui->soLuongSpinBox->value();
    if (soLuong <= 0) {
        QMessageBox::warning(this, "Số lượng không hợp lệ", "Số lượng phải lớn hơn 0.");
        return;
    }

    if (m_mode == Import) {
        ChitietPhieuNhap ct;
        ct.maHH = m_foundProduct->getMaHH();
        ct.soLuong = soLuong;
        ct.donGiaNhap = m_foundProduct->getGiaNhap();
        m_tempChiTietNhap.addLast(ct);
    } else {
        ChitietPhieuXuat ct;
        ct.maHH = m_foundProduct->getMaHH();
        ct.soLuong = soLuong;
        ct.donGiaBan = m_foundProduct->getGiaBan();
        m_tempChiTietXuat.addLast(ct);
    }

    updateDetailsTable();
    clearAddItemSection();
}

void ReceiptDialog::updateDetailsTable()
{
    ui->detailsTable->setRowCount(0);
    if (m_mode == Import) {
        Node<ChitietPhieuNhap>* current = m_tempChiTietNhap.getHead();
        while(current != nullptr) {
            int row = ui->detailsTable->rowCount();
            ui->detailsTable->insertRow(row);

            HangHoa* hh = m_qlhh_ref.layHangHoaTheoMa(current->data.maHH);
            QString tenHH = hh ? QString::fromStdString(hh->getTenHH()) : "N/A";

            ui->detailsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(current->data.maHH)));
            ui->detailsTable->setItem(row, 1, new QTableWidgetItem(tenHH));
            ui->detailsTable->setItem(row, 2, new QTableWidgetItem(QString::number(current->data.soLuong)));
            ui->detailsTable->setItem(row, 3, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(current->data.donGiaNhap, 'f', 0)));
            ui->detailsTable->setItem(row, 4, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(current->data.soLuong * current->data.donGiaNhap, 'f', 0)));

            current = current->pNext;
        }
    } else {
        Node<ChitietPhieuXuat>* current = m_tempChiTietXuat.getHead();
        while(current != nullptr) {
            int row = ui->detailsTable->rowCount();
            ui->detailsTable->insertRow(row);

            HangHoa* hh = m_qlhh_ref.layHangHoaTheoMa(current->data.maHH);
            QString tenHH = hh ? QString::fromStdString(hh->getTenHH()) : "N/A";

            ui->detailsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(current->data.maHH)));
            ui->detailsTable->setItem(row, 1, new QTableWidgetItem(tenHH));
            ui->detailsTable->setItem(row, 2, new QTableWidgetItem(QString::number(current->data.soLuong)));
            ui->detailsTable->setItem(row, 3, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(current->data.donGiaBan, 'f', 0)));
            ui->detailsTable->setItem(row, 4, new QTableWidgetItem(QLocale(QLocale::Vietnamese).toString(current->data.soLuong * current->data.donGiaBan, 'f', 0)));

            current = current->pNext;
        }
    }
    updateTotalAmount();
}

void ReceiptDialog::updateTotalAmount()
{
    double total = 0;
    if (m_mode == Import) {
        Node<ChitietPhieuNhap>* current = m_tempChiTietNhap.getHead();
        while(current != nullptr) {
            total += current->data.soLuong * current->data.donGiaNhap;
            current = current->pNext;
        }
    } else {
        Node<ChitietPhieuXuat>* current = m_tempChiTietXuat.getHead();
        while(current != nullptr) {
            total += current->data.soLuong * current->data.donGiaBan;
            current = current->pNext;
        }
    }
    ui->tongTienLabel->setText(QLocale(QLocale::Vietnamese).toString(total, 'f', 0) + " VND");
}

void ReceiptDialog::clearAddItemSection()
{
    m_foundProduct = nullptr;
    ui->maHHEdit->clear();
    ui->tenHHLabel->setText("(Vui lòng tìm mã hàng hóa)");
    ui->soLuongSpinBox->setValue(1);
    ui->soLuongSpinBox->setEnabled(false);
    ui->addItemButton->setEnabled(false);
    ui->maHHEdit->setFocus();
}

void ReceiptDialog::on_removeItemButton_clicked()
{
    int currentRow = ui->detailsTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Chưa chọn", "Vui lòng chọn một mục trong bảng để xóa.");
        return;
    }

    std::string maHH = ui->detailsTable->item(currentRow, 0)->text().toStdString();

    if (m_mode == Import) {
        ChitietPhieuNhap toRemove;
        toRemove.maHH = maHH;
        m_tempChiTietNhap.remove(toRemove);
    } else {
        ChitietPhieuXuat toRemove;
        toRemove.maHH = maHH;
        m_tempChiTietXuat.remove(toRemove);
    }
    updateDetailsTable();
}


PhieuNhap ReceiptDialog::getPhieuNhapData() const
{
    PhieuNhap pn;
    pn.setMaPhieuNhap(ui->maPhieuEdit->text().toStdString());

    QDate qd = ui->ngayLapDateEdit->date();
    pn.setNgayNhap({qd.day(), qd.month(), qd.year()});

    pn.setMaNCC(ui->nccComboBox->currentData().toString().toStdString());
    pn.setDSHangNhap(m_tempChiTietNhap);
    pn.tinhThanhtien();

    return pn;
}

void ReceiptDialog::on_maHHEdit_returnPressed()
{

    on_findProductButton_clicked();
}

PhieuXuat ReceiptDialog::getPhieuXuatData() const
{
    PhieuXuat px;
    px.setMaPhieuXuat(ui->maPhieuEdit->text().toStdString());

    QDate qd = ui->ngayLapDateEdit->date();
    px.setNgayXuat({qd.day(), qd.month(), qd.year()});

    px.setTenKH(ui->khachHangEdit->text().toStdString());
    px.setDSHangXuat(m_tempChiTietXuat);
    px.tinhThanhtien();

    return px;
}
