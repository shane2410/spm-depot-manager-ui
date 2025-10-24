#ifndef RECEIPTMANAGEMENTWIDGET_H
#define RECEIPTMANAGEMENTWIDGET_H

#include <QWidget>
#include "../backend_headers/QuanLyPhieu.h"
#include "../backend_headers/QuanLyHangHoa.h"
#include "../backend_headers/QuanLyNhaCungCap.h"

namespace Ui {
class ReceiptManagementWidget;
}

class ReceiptManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiptManagementWidget(QuanLyPhieu& qlp, QuanLyHangHoa& qlhh, QuanLyNhaCungCap& qlncc, QWidget *parent = nullptr);
    ~ReceiptManagementWidget();

public slots:
    void refreshTables();

private slots:
    void on_createImportReceiptButton_clicked();
    void on_createExportReceiptButton_clicked();
    void on_importReceiptsTable_itemSelectionChanged();
    void on_exportReceiptsTable_itemSelectionChanged();

private:
    void setupTables();
    void loadImportReceipts();
    void loadExportReceipts();
    void showImportReceiptDetails(const std::string& maPhieu);
    void showExportReceiptDetails(const std::string& maPhieu);

    Ui::ReceiptManagementWidget *ui;
    QuanLyPhieu& m_qlp_ref;
    QuanLyHangHoa& m_qlhh_ref;
    QuanLyNhaCungCap& m_qlncc_ref;
};

#endif // RECEIPTMANAGEMENTWIDGET_H
