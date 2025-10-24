#include "supplierdialog.h"
#include "ui_supplierdialog.h"

SupplierDialog::SupplierDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupplierDialog)
{
    ui->setupUi(this);
    setWindowTitle("Thêm Nhà Cung Cấp Mới");
}

SupplierDialog::SupplierDialog(const NhaCungCap& nccToEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupplierDialog)
{
    ui->setupUi(this);
    setWindowTitle("Cập Nhật Thông Tin Nhà Cung Cấp");
    setSupplierData(nccToEdit);
    ui->maNccEdit->setReadOnly(true);
}

SupplierDialog::~SupplierDialog()
{
    delete ui;
}

void SupplierDialog::setSupplierData(const NhaCungCap& ncc)
{
    m_originalMaNCC = ncc.getMaNCC();
    ui->maNccEdit->setText(QString::fromStdString(ncc.getMaNCC()));
    ui->tenNccEdit->setText(QString::fromStdString(ncc.getTenNCC()));
    ui->diaChiEdit->setText(QString::fromStdString(ncc.getDiaChi()));
    ui->sdtEdit->setText(QString::fromStdString(ncc.getSoDienThoai()));
}

NhaCungCap SupplierDialog::getSupplierData() const
{
    std::string maNCC = ui->maNccEdit->isReadOnly() ? m_originalMaNCC : ui->maNccEdit->text().toStdString();
    std::string tenNCC = ui->tenNccEdit->text().toStdString();
    std::string diaChi = ui->diaChiEdit->text().toStdString();
    std::string sdt = ui->sdtEdit->text().toStdString();

    return NhaCungCap(maNCC, tenNCC, diaChi, sdt);
}
