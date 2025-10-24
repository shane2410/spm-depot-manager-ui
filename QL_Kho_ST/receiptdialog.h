#ifndef RECEIPTDIALOG_H
#define RECEIPTDIALOG_H

#include <QDialog>
#include "../backend_headers/QuanLyHangHoa.h"
#include "../backend_headers/QuanLyNhaCungCap.h"
#include "../backend_headers/Phieu.h"

namespace Ui {
class ReceiptDialog;
}

class ReceiptDialog : public QDialog
{
    Q_OBJECT

public:
    enum DialogMode { Import, Export };

    explicit ReceiptDialog(DialogMode mode, QuanLyHangHoa& qlhh, QuanLyNhaCungCap& qlncc, QWidget *parent = nullptr);
    ~ReceiptDialog();

    PhieuNhap getPhieuNhapData() const;
    PhieuXuat getPhieuXuatData() const;

private slots:
    void on_findProductButton_clicked();
    void on_addItemButton_clicked();
    void on_removeItemButton_clicked();
    void on_maHHEdit_returnPressed();

private:
    void setupUiForMode();
    void populateNccComboBox();
    void updateDetailsTable();
    void updateTotalAmount();
    void clearAddItemSection();
    void generateNewReceiptId();

    Ui::ReceiptDialog *ui;
    DialogMode m_mode;
    QuanLyHangHoa& m_qlhh_ref;
    QuanLyNhaCungCap& m_qlncc_ref;

    HangHoa* m_foundProduct; // To store the product found by search
    LinkedList<ChitietPhieuNhap> m_tempChiTietNhap;
    LinkedList<ChitietPhieuXuat> m_tempChiTietXuat;
};

#endif // RECEIPTDIALOG_H
