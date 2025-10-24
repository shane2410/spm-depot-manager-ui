/********************************************************************************
** Form generated from reading UI file 'reportwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWIDGET_H
#define UI_REPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *revenueTab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *fromDateEdit;
    QLabel *label_2;
    QDateEdit *toDateEdit;
    QPushButton *viewReportButton;
    QSpacerItem *horizontalSpacer;
    QTableWidget *revenueTable;
    QLabel *totalRevenueLabel;
    QWidget *inventoryTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *inventoryTable;

    void setupUi(QWidget *ReportWidget)
    {
        if (ReportWidget->objectName().isEmpty())
            ReportWidget->setObjectName("ReportWidget");
        ReportWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(ReportWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(ReportWidget);
        tabWidget->setObjectName("tabWidget");
        revenueTab = new QWidget();
        revenueTab->setObjectName("revenueTab");
        verticalLayout_2 = new QVBoxLayout(revenueTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(revenueTab);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        fromDateEdit = new QDateEdit(widget);
        fromDateEdit->setObjectName("fromDateEdit");
        fromDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(fromDateEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        toDateEdit = new QDateEdit(widget);
        toDateEdit->setObjectName("toDateEdit");
        toDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(toDateEdit);

        viewReportButton = new QPushButton(widget);
        viewReportButton->setObjectName("viewReportButton");

        horizontalLayout->addWidget(viewReportButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget);

        revenueTable = new QTableWidget(revenueTab);
        if (revenueTable->columnCount() < 4)
            revenueTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        revenueTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        revenueTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        revenueTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        revenueTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        revenueTable->setObjectName("revenueTable");

        verticalLayout_2->addWidget(revenueTable);

        totalRevenueLabel = new QLabel(revenueTab);
        totalRevenueLabel->setObjectName("totalRevenueLabel");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        totalRevenueLabel->setFont(font);
        totalRevenueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(totalRevenueLabel);

        tabWidget->addTab(revenueTab, QString());
        inventoryTab = new QWidget();
        inventoryTab->setObjectName("inventoryTab");
        verticalLayout_3 = new QVBoxLayout(inventoryTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        inventoryTable = new QTableWidget(inventoryTab);
        if (inventoryTable->columnCount() < 3)
            inventoryTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        inventoryTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        inventoryTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        inventoryTable->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        inventoryTable->setObjectName("inventoryTable");

        verticalLayout_3->addWidget(inventoryTable);

        tabWidget->addTab(inventoryTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(ReportWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReportWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportWidget)
    {
        ReportWidget->setWindowTitle(QCoreApplication::translate("ReportWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ReportWidget", "T\341\273\253 ng\303\240y:", nullptr));
        label_2->setText(QCoreApplication::translate("ReportWidget", "\304\220\341\272\277n ng\303\240y:", nullptr));
        viewReportButton->setText(QCoreApplication::translate("ReportWidget", "Xem B\303\241o c\303\241o", nullptr));
        QTableWidgetItem *___qtablewidgetitem = revenueTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ReportWidget", "M\303\243 Phi\341\272\277u Xu\341\272\245t", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = revenueTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ReportWidget", "Ng\303\240y Xu\341\272\245t", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = revenueTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ReportWidget", "T\303\252n Kh\303\241ch H\303\240ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = revenueTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ReportWidget", "T\341\273\225ng Ti\341\273\201n", nullptr));
        totalRevenueLabel->setText(QCoreApplication::translate("ReportWidget", "T\341\273\225ng Doanh thu: 0 VND", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(revenueTab), QCoreApplication::translate("ReportWidget", "Th\341\273\221ng k\303\252 Doanh thu", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = inventoryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ReportWidget", "M\303\243 HH", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = inventoryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ReportWidget", "T\303\252n H\303\240ng H\303\263a", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = inventoryTable->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ReportWidget", "S\341\273\221 L\306\260\341\273\243ng T\341\273\223n", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(inventoryTab), QCoreApplication::translate("ReportWidget", "B\303\241o c\303\241o T\341\273\223n kho", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportWidget: public Ui_ReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWIDGET_H
