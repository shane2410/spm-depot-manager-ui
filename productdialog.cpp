#include "productdialog.h"
#include "ui_productdialog.h"
#include <QDate>
#include <QVariant>

ProductDialog::ProductDialog(QuanLyNhaCungCap& qlncc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductDialog),
    m_qlncc_ref(qlncc)
{
    ui->setupUi(this);
    setWindowTitle("Thêm Hàng Hóa Mới");
    populateNccComboBox();

    ui->giaNhapSpinBox->setMaximum(1000000000);
    ui->giaBanSpinBox->setMaximum(1000000000);
    ui->soLuongSpinBox->setMaximum(1000000);
    ui->nsxDateEdit->setDate(QDate::currentDate());
    ui->hsdDateEdit->setDate(QDate::currentDate().addYears(1));
}

ProductDialog::ProductDialog(const HangHoa& hhToEdit, QuanLyNhaCungCap& qlncc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductDialog),
    m_qlncc_ref(qlncc)
{
    ui->setupUi(this);
    setWindowTitle("Cập Nhật Thông Tin Hàng Hóa");
    populateNccComboBox();

    ui->giaNhapSpinBox->setMaximum(1000000000);
    ui->giaBanSpinBox->setMaximum(1000000000);
    ui->soLuongSpinBox->setMaximum(1000000);

    setHangHoaData(hhToEdit);

    ui->maHHEdit->setReadOnly(true);
}

ProductDialog::~ProductDialog()
{
    delete ui;
}

void ProductDialog::populateNccComboBox()
{
    ui->nccComboBox->clear();
    const LinkedList<NhaCungCap>& dsNcc = m_qlncc_ref.getDanhSach();
    Node<NhaCungCap>* current = dsNcc.getHead();
    while (current != nullptr) {
        const NhaCungCap& ncc = current->data;
        ui->nccComboBox->addItem(QString::fromStdString(ncc.getTenNCC()),
                                 QVariant(QString::fromStdString(ncc.getMaNCC())));
        current = current->pNext;
    }
}

void ProductDialog::setHangHoaData(const HangHoa& hh)
{
    m_originalMaHH = hh.getMaHH();
    ui->maHHEdit->setText(QString::fromStdString(hh.getMaHH()));
    ui->tenHHEdit->setText(QString::fromStdString(hh.getTenHH()));
    ui->dvtEdit->setText(QString::fromStdString(hh.getDonViTinh()));
    ui->giaNhapSpinBox->setValue(hh.getGiaNhap());
    ui->giaBanSpinBox->setValue(hh.getGiaBan());
    ui->soLuongSpinBox->setValue(hh.getSoLuongTon());

    QString maNCC = QString::fromStdString(hh.getMaNCC());
    int index = ui->nccComboBox->findData(QVariant(maNCC));
    if (index != -1) {
        ui->nccComboBox->setCurrentIndex(index);
    }

    Date nsx = hh.getNgaySanXuat();
    ui->nsxDateEdit->setDate(QDate(nsx.getDay(), nsx.getMonth(), nsx.getYear()));
    Date hsd = hh.getHanSuDung();
    ui->hsdDateEdit->setDate(QDate(hsd.getDay(), hsd.getMonth(), hsd.getYear()));
}

HangHoa ProductDialog::getHangHoaData() const
{
    HangHoa hh;

    std::string maHH = ui->maHHEdit->isReadOnly() ? m_originalMaHH : ui->maHHEdit->text().toStdString();
    hh.setMaHH(maHH);

    hh.setTenHH(ui->tenHHEdit->text().toStdString());
    hh.setDonViTinh(ui->dvtEdit->text().toStdString());
    hh.setGiaNhap(ui->giaNhapSpinBox->value());
    hh.setGiaBan(ui->giaBanSpinBox->value());
    hh.setSoLuongTon(ui->soLuongSpinBox->value());

    hh.setMaNCC(ui->nccComboBox->currentData().toString().toStdString());

    QDate nsxQDate = ui->nsxDateEdit->date();
    hh.setNgaySanXuat({nsxQDate.day(), nsxQDate.month(), nsxQDate.year()});
    QDate hsdQDate = ui->hsdDateEdit->date();
    hh.setHanSuDung({hsdQDate.day(), hsdQDate.month(), hsdQDate.year()});

    return hh;
}
