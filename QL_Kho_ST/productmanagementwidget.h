#ifndef PRODUCTMANAGEMENTWIDGET_H
#define PRODUCTMANAGEMENTWIDGET_H

#include <QWidget>
#include "../backend_headers/QuanLyHangHoa.h"
#include "../backend_headers/QuanLyNhaCungCap.h"

namespace Ui {
class ProductManagementWidget;
}

class ProductManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagementWidget(QuanLyHangHoa &qlhh, QuanLyNhaCungCap &qlncc, QWidget *parent = nullptr);
    ~ProductManagementWidget();

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
    Ui::ProductManagementWidget *ui;


    QuanLyHangHoa &m_qlhh_ref;
    QuanLyNhaCungCap &m_qlncc_ref;
};

#endif // PRODUCTMANAGEMENTWIDGET_H
