#include "productmanagementwidget.h"
#include "ui_productmanagementwidget.h"
#include "productdialog.h"
#include <QTableWidgetItem>
#include <QMessageBox>

ProductManagementWidget::ProductManagementWidget(QuanLyHangHoa &qlhh, QuanLyNhaCungCap &qlncc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductManagementWidget),
    m_qlhh_ref(qlhh),
    m_qlncc_ref(qlncc)
{
    ui->setupUi(this);

    setupTable();
    loadTableData();

    connect(ui->productTable, &QTableWidget::itemSelectionChanged, this, &ProductManagementWidget::updateActionButtonsState);

    updateActionButtonsState();
}

ProductManagementWidget::~ProductManagementWidget()
{
    delete ui;
}

void ProductManagementWidget::setupTable()
{
    ui->productTable->setColumnCount(7);
    QStringList headers = {"Mã HH", "Tên Hàng Hóa", "Đơn Vị Tính", "SL Tồn", "Giá Bán", "HSD", "Nhà Cung Cấp"};
    ui->productTable->setHorizontalHeaderLabels(headers);

    ui->productTable->horizontalHeader()->setStretchLastSection(true);
    ui->productTable->verticalHeader()->setVisible(false);
    ui->productTable->setSortingEnabled(true);
}

void ProductManagementWidget::loadTableData()
{
    ui->productTable->setSortingEnabled(false);
    ui->productTable->setRowCount(0);

    const LinkedList<HangHoa>& dsHangHoa = m_qlhh_ref.getDanhSach();
    Node<HangHoa>* current = dsHangHoa.getHead();

    while (current != nullptr)
    {
        const HangHoa& hh = current->data;
        int row = ui->productTable->rowCount();
        ui->productTable->insertRow(row);

        QTableWidgetItem* itemMaHH = new QTableWidgetItem(QString::fromStdString(hh.getMaHH()));
        QTableWidgetItem* itemTenHH = new QTableWidgetItem(QString::fromStdString(hh.getTenHH()));
        QTableWidgetItem* itemDVT = new QTableWidgetItem(QString::fromStdString(hh.getDonViTinh()));
        QTableWidgetItem* itemSLTon = new QTableWidgetItem(QString::number(hh.getSoLuongTon()));
        QTableWidgetItem* itemGiaBan = new QTableWidgetItem(QString::number(hh.getGiaBan(), 'f', 0));

        Date hsd = hh.getHanSuDung();
        QTableWidgetItem* itemHSD = new QTableWidgetItem(QString("%1/%2/%3").arg(hsd.getDay(), 2, 10, QChar('0')).arg(hsd.getMonth(), 2, 10, QChar('0')).arg(hsd.getYear()));

        // Lấy tên NCC từ mã NCC
        NhaCungCap* ncc = m_qlncc_ref.timKiemNhaCungCap(hh.getMaNCC());
        QString tenNCC = ncc ? QString::fromStdString(ncc->getTenNCC()) : "Không rõ";
        QTableWidgetItem* itemNCC = new QTableWidgetItem(tenNCC);

        // Đặt item vào bảng
        ui->productTable->setItem(row, 0, itemMaHH);
        ui->productTable->setItem(row, 1, itemTenHH);
        ui->productTable->setItem(row, 2, itemDVT);
        ui->productTable->setItem(row, 3, itemSLTon);
        ui->productTable->setItem(row, 4, itemGiaBan);
        ui->productTable->setItem(row, 5, itemHSD);
        ui->productTable->setItem(row, 6, itemNCC);

        current = current->pNext;
    }
    ui->productTable->setSortingEnabled(true);
}

void ProductManagementWidget::refreshTable()
{
    loadTableData();
}

void ProductManagementWidget::on_addButton_clicked()
{
    ProductDialog dialog(m_qlncc_ref, this);
    if (dialog.exec() == QDialog::Accepted) {
        HangHoa newHH = dialog.getHangHoaData();
        if (m_qlhh_ref.themHangHoa(newHH)) {
            loadTableData(); // Tải lại bảng
            QMessageBox::information(this, "Thành công", "Đã thêm hàng hóa mới.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Mã hàng hóa đã tồn tại.");
        }
    }
}

void ProductManagementWidget::on_editButton_clicked()
{
    int currentRow = ui->productTable->currentRow();
    if (currentRow < 0) return;

    std::string maHH = ui->productTable->item(currentRow, 0)->text().toStdString();
    HangHoa* hhToEdit = m_qlhh_ref.layHangHoaTheoMa(maHH);

    if (hhToEdit) {
        ProductDialog dialog(*hhToEdit, m_qlncc_ref, this);
        if (dialog.exec() == QDialog::Accepted) {
            HangHoa updatedHH = dialog.getHangHoaData();
            if (m_qlhh_ref.capNhatHangHoa(updatedHH)) {
                loadTableData();
                QMessageBox::information(this, "Thành công", "Đã cập nhật thông tin hàng hóa.");
            } else {
                QMessageBox::warning(this, "Thất bại", "Không thể cập nhật.");
            }
        }
    }
}

void ProductManagementWidget::on_deleteButton_clicked()
{
    int currentRow = ui->productTable->currentRow();
    if (currentRow < 0) return;

    std::string maHH = ui->productTable->item(currentRow, 0)->text().toStdString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Xác nhận xóa", QString("Bạn có chắc chắn muốn xóa hàng hóa có mã '%1'?").arg(QString::fromStdString(maHH)), QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (m_qlhh_ref.xoaHangHoa(maHH)) {
            loadTableData();
            QMessageBox::information(this, "Thành công", "Đã xóa hàng hóa.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Không thể xóa hàng hóa.");
        }
    }
}

void ProductManagementWidget::on_searchButton_clicked()
{
    QString keyword = ui->searchLineEdit->text().trimmed();
    int searchType = ui->searchCriteriaComboBox->currentIndex();

    for (int i = 0; i < ui->productTable->rowCount(); ++i)
    {
        bool match = false;
        if (keyword.isEmpty()) {
            match = true;
        } else {
            QTableWidgetItem* item = ui->productTable->item(i, searchType);
            if (item && item->text().contains(keyword, Qt::CaseInsensitive)) {
                match = true;
            }
        }
        ui->productTable->setRowHidden(i, !match);
    }
}

void ProductManagementWidget::updateActionButtonsState()
{
    bool hasSelection = ui->productTable->selectionModel()->hasSelection();
    ui->editButton->setEnabled(hasSelection);
    ui->deleteButton->setEnabled(hasSelection);
}
