#include "dashboardwidget.h"
#include "ui_dashboardwidget.h"
#include <QLocale>

DashboardWidget::DashboardWidget(QuanLyHangHoa& qlhh, QuanLyPhieu& qlp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardWidget),
    m_qlhh_ref(qlhh),
    m_qlp_ref(qlp)
{
    ui->setupUi(this);
    refreshData();
}

DashboardWidget::~DashboardWidget()
{
    delete ui;
}

void DashboardWidget::refreshData()
{
    ui->productsCountLabel->setText(QString::number(m_qlhh_ref.getDanhSach().getSize()));

    int lowStockCount = 0;
    Node<HangHoa>* hh_node = m_qlhh_ref.getDanhSach().getHead();
    while(hh_node != nullptr) {
        if(hh_node->data.getSoLuongTon() < 10) {
            lowStockCount++;
        }
        hh_node = hh_node->pNext;
    }
    ui->lowStockCountLabel->setText(QString::number(lowStockCount));

    int expiringCount = 0;
    Date today;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    today.setDay(ltm->tm_mday);
    today.setMonth(1 + ltm->tm_mon);
    today.setYear(1900 + ltm->tm_year);

    hh_node = m_qlhh_ref.getDanhSach().getHead();
    while(hh_node != nullptr) {
        // Simple date difference check (approx 30 days)
        // A more robust library would be better for real applications
        Date hsd = hh_node->data.getHanSuDung();
        if (hsd.getYear() == today.getYear() && hsd.getMonth() == today.getMonth()) {
            expiringCount++;
        }
        hh_node = hh_node->pNext;
    }
    ui->expiringCountLabel->setText(QString::number(expiringCount));

    Date firstDayOfMonth = {1, today.getMonth(), today.getYear()};
    double revenue = m_qlp_ref.thongKeDoanhThu(firstDayOfMonth, today);
    ui->revenueLabel->setText(QLocale(QLocale::Vietnamese).toString(revenue, 'f', 0) + " VND");
}
