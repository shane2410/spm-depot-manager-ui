#ifndef SUPPLIERDIALOG_H
#define SUPPLIERDIALOG_H

#include <QDialog>
#include "../backend_headers/NhaCungCap.h"

namespace Ui {
class SupplierDialog;}

class SupplierDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SupplierDialog(QWidget *parent = nullptr); // For Add mode
    SupplierDialog(const NhaCungCap& nccToEdit, QWidget *parent = nullptr); // For Edit mode
    ~SupplierDialog();

    NhaCungCap getSupplierData() const;

private:
    void setSupplierData(const NhaCungCap& ncc);

    Ui::SupplierDialog *ui;
    std::string m_originalMaNCC;
};

#endif // SUPPLIERDIALOG_H
