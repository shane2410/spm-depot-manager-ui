#ifndef SUPPLIERMANAGEMENTWIDGET_H
#define SUPPLIERMANAGEMENTWIDGET_H

#include <QWidget>
#include "../backend_headers/QuanLyNhaCungCap.h"

namespace Ui {
class SupplierManagementWidget;
}

class SupplierManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SupplierManagementWidget(QuanLyNhaCungCap& qlncc, QWidget *parent = nullptr);
    ~SupplierManagementWidget();

public slots:
    void refreshTable();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_searchButton_clicked();
    void updateActionButtonsState();

private:
    void setupTable();
    void loadTableData();

    Ui::SupplierManagementWidget *ui;
    QuanLyNhaCungCap& m_qlncc_ref;
};

#endif // SUPPLIERMANAGEMENTWIDGET_H
