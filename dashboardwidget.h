#ifndef DASHBOARDWIDGET_H
#define DASHBOARDWIDGET_H

#include <QWidget>
#include "../backend_headers/QuanLyHangHoa.h"
#include "../backend_headers/QuanLyPhieu.h"

namespace Ui {
class DashboardWidget;
}

class DashboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardWidget(QuanLyHangHoa& qlhh, QuanLyPhieu& qlp, QWidget *parent = nullptr);
    ~DashboardWidget();

public slots:
    void refreshData();

private:
    Ui::DashboardWidget *ui;
    QuanLyHangHoa& m_qlhh_ref;
    QuanLyPhieu& m_qlp_ref;
};

#endif // DASHBOARDWIDGET_H
