#include "suppliermanagementwidget.h"
#include "ui_suppliermanagementwidget.h"
#include "supplierdialog.h"
#include <QTableWidgetItem>
#include <QMessageBox>

SupplierManagementWidget::SupplierManagementWidget(QuanLyNhaCungCap& qlncc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupplierManagementWidget),
    m_qlncc_ref(qlncc)
{
    ui->setupUi(this);
    setupTable();
    loadTableData();
    connect(ui->supplierTable, &QTableWidget::itemSelectionChanged, this, &SupplierManagementWidget::updateActionButtonsState);
    updateActionButtonsState();
}

SupplierManagementWidget::~SupplierManagementWidget()
{
    delete ui;
}

void SupplierManagementWidget::setupTable()
{
    ui->supplierTable->setColumnCount(4);
    QStringList headers = {"Mã NCC", "Tên Nhà Cung Cấp", "Địa chỉ", "Số điện thoại"};
    ui->supplierTable->setHorizontalHeaderLabels(headers);
    ui->supplierTable->horizontalHeader()->setStretchLastSection(true);
}

void SupplierManagementWidget::loadTableData()
{
    ui->supplierTable->setRowCount(0);
    const LinkedList<NhaCungCap>& dsNcc = m_qlncc_ref.getDanhSach();
    Node<NhaCungCap>* current = dsNcc.getHead();

    while (current != nullptr) {
        const NhaCungCap& ncc = current->data;
        int row = ui->supplierTable->rowCount();
        ui->supplierTable->insertRow(row);

        ui->supplierTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(ncc.getMaNCC())));
        ui->supplierTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(ncc.getTenNCC())));
        ui->supplierTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(ncc.getDiaChi())));
        ui->supplierTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(ncc.getSoDienThoai())));
        current = current->pNext;
    }
}

void SupplierManagementWidget::refreshTable()
{
    loadTableData();
}

void SupplierManagementWidget::on_addButton_clicked()
{
    SupplierDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        NhaCungCap newNcc = dialog.getSupplierData();
        if (m_qlncc_ref.themNhaCungCap(newNcc)) {
            loadTableData();
            QMessageBox::information(this, "Thành công", "Đã thêm nhà cung cấp mới.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Mã nhà cung cấp đã tồn tại.");
        }
    }
}

void SupplierManagementWidget::on_editButton_clicked()
{
    int currentRow = ui->supplierTable->currentRow();
    if (currentRow < 0) return;

    std::string maNCC = ui->supplierTable->item(currentRow, 0)->text().toStdString();
    NhaCungCap* nccToEdit = m_qlncc_ref.timKiemNhaCungCap(maNCC);

    if (nccToEdit) {
        SupplierDialog dialog(*nccToEdit, this);
        if (dialog.exec() == QDialog::Accepted) {
            NhaCungCap updatedNcc = dialog.getSupplierData();
            if (m_qlncc_ref.capNhatNhaCungCap(updatedNcc)) {
                loadTableData();
                QMessageBox::information(this, "Thành công", "Đã cập nhật thông tin.");
            } else {
                QMessageBox::warning(this, "Thất bại", "Không thể cập nhật.");
            }
        }
    }
}

void SupplierManagementWidget::on_deleteButton_clicked()
{
    int currentRow = ui->supplierTable->currentRow();
    if (currentRow < 0) return;

    std::string maNCC = ui->supplierTable->item(currentRow, 0)->text().toStdString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Xác nhận xóa", "Bạn có chắc chắn muốn xóa nhà cung cấp này?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (m_qlncc_ref.xoaNhaCungCap(maNCC)) {
            loadTableData();
            QMessageBox::information(this, "Thành công", "Đã xóa nhà cung cấp.");
        } else {
            QMessageBox::warning(this, "Thất bại", "Không thể xóa.");
        }
    }
}

void SupplierManagementWidget::on_searchButton_clicked()
{
    QString keyword = ui->searchLineEdit->text().trimmed();
    int searchType = ui->searchCriteriaComboBox->currentIndex();

    for (int i = 0; i < ui->supplierTable->rowCount(); ++i) {
        bool match = false;
        if (keyword.isEmpty()) {
            match = true;
        } else {
            QTableWidgetItem* item = ui->supplierTable->item(i, searchType + 1); // +1 because Mã is at col 0, Tên at col 1
            if (item && item->text().contains(keyword, Qt::CaseInsensitive)) {
                match = true;
            }
        }
        ui->supplierTable->setRowHidden(i, !match);
    }
}

void SupplierManagementWidget::updateActionButtonsState()
{
    bool hasSelection = ui->supplierTable->selectionModel()->hasSelection();
    ui->editButton->setEnabled(hasSelection);
    ui->deleteButton->setEnabled(hasSelection);
}
