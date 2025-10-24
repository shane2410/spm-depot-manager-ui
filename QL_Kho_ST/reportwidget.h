#ifndef REPORTWIDGET_H
#define REPORTWIDGET_H

#include <QWidget>
#include "../backend_headers/QuanLyPhieu.h"
#include "../backend_headers/QuanLyHangHoa.h"

namespace Ui {
class ReportWidget;
}

class ReportWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReportWidget(QuanLyPhieu& qlp, QuanLyHangHoa& qlhh, QWidget *parent = nullptr);
    ~ReportWidget();

private slots:
    void on_viewReportButton_clicked();
    void on_tabWidget_currentChanged(int index);

private:
    void setupInitialState();
    void loadRevenueReport();
    void loadInventoryReport();

    Ui::ReportWidget *ui;
    QuanLyPhieu& m_qlp_ref;
    QuanLyHangHoa& m_qlhh_ref;
};

#endif // REPORTWIDGET_H
