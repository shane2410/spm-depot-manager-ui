#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

#include <QDialog>
#include "../backend_headers/HangHoa.h"
#include "../backend_headers/QuanLyNhaCungCap.h"

namespace Ui {
class ProductDialog;
}

class ProductDialog : public QDialog
{
    Q_OBJECT

public:

    explicit ProductDialog(QuanLyNhaCungCap& qlncc, QWidget *parent = nullptr);


    ProductDialog(const HangHoa& hhToEdit, QuanLyNhaCungCap& qlncc, QWidget *parent = nullptr);

    ~ProductDialog();


    HangHoa getHangHoaData() const;

private:
    void populateNccComboBox();
    void setHangHoaData(const HangHoa& hh);

    Ui::ProductDialog *ui;
    QuanLyNhaCungCap& m_qlncc_ref;
    std::string m_originalMaHH;
};

#endif // PRODUCTDIALOG_H
