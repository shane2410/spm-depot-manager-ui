/********************************************************************************
** Form generated from reading UI file 'dashboardwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARDWIDGET_H
#define UI_DASHBOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *infoCard;
    QHBoxLayout *horizontalLayout;
    QLabel *iconLabel;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *productsCountLabel;
    QFrame *infoCard1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *iconLabel1;
    QVBoxLayout *verticalLayout_2;
    QLabel *titleLabel1;
    QLabel *lowStockCountLabel;
    QFrame *infoCard2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *iconLabel2;
    QVBoxLayout *verticalLayout_3;
    QLabel *titleLabel2;
    QLabel *expiringCountLabel;
    QFrame *infoCard3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *iconLabel3;
    QVBoxLayout *verticalLayout_4;
    QLabel *titleLabel3;
    QLabel *revenueLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DashboardWidget)
    {
        if (DashboardWidget->objectName().isEmpty())
            DashboardWidget->setObjectName("DashboardWidget");
        DashboardWidget->resize(780, 550);
        DashboardWidget->setStyleSheet(QString::fromUtf8("QFrame#infoCard {\n"
"    background-color: rgb(255, 255, 255);\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"}\n"
"QLabel#valueLabel {\n"
"    font-size: 28pt;\n"
"    font-weight: bold;\n"
"    color: #005a9e;\n"
"}\n"
"QLabel#titleLabel {\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
"QLabel#iconLabel {\n"
"    font-size: 32pt;\n"
"}"));
        gridLayout = new QGridLayout(DashboardWidget);
        gridLayout->setObjectName("gridLayout");
        infoCard = new QFrame(DashboardWidget);
        infoCard->setObjectName("infoCard");
        infoCard->setFrameShape(QFrame::StyledPanel);
        infoCard->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(infoCard);
        horizontalLayout->setObjectName("horizontalLayout");
        iconLabel = new QLabel(infoCard);
        iconLabel->setObjectName("iconLabel");

        horizontalLayout->addWidget(iconLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(infoCard);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        productsCountLabel = new QLabel(infoCard);
        productsCountLabel->setObjectName("productsCountLabel");

        verticalLayout->addWidget(productsCountLabel);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addWidget(infoCard, 0, 0, 1, 1);

        infoCard1 = new QFrame(DashboardWidget);
        infoCard1->setObjectName("infoCard1");
        infoCard1->setStyleSheet(QString::fromUtf8("QLabel#valueLabel {\n"
"    color: #e67e22;\n"
"}"));
        infoCard1->setFrameShape(QFrame::StyledPanel);
        infoCard1->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(infoCard1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        iconLabel1 = new QLabel(infoCard1);
        iconLabel1->setObjectName("iconLabel1");

        horizontalLayout_2->addWidget(iconLabel1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        titleLabel1 = new QLabel(infoCard1);
        titleLabel1->setObjectName("titleLabel1");

        verticalLayout_2->addWidget(titleLabel1);

        lowStockCountLabel = new QLabel(infoCard1);
        lowStockCountLabel->setObjectName("lowStockCountLabel");

        verticalLayout_2->addWidget(lowStockCountLabel);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addWidget(infoCard1, 0, 1, 1, 1);

        infoCard2 = new QFrame(DashboardWidget);
        infoCard2->setObjectName("infoCard2");
        infoCard2->setStyleSheet(QString::fromUtf8("QLabel#valueLabel {\n"
"    color: #c0392b;\n"
"}"));
        infoCard2->setFrameShape(QFrame::StyledPanel);
        infoCard2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(infoCard2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        iconLabel2 = new QLabel(infoCard2);
        iconLabel2->setObjectName("iconLabel2");

        horizontalLayout_3->addWidget(iconLabel2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        titleLabel2 = new QLabel(infoCard2);
        titleLabel2->setObjectName("titleLabel2");

        verticalLayout_3->addWidget(titleLabel2);

        expiringCountLabel = new QLabel(infoCard2);
        expiringCountLabel->setObjectName("expiringCountLabel");

        verticalLayout_3->addWidget(expiringCountLabel);


        horizontalLayout_3->addLayout(verticalLayout_3);


        gridLayout->addWidget(infoCard2, 1, 0, 1, 1);

        infoCard3 = new QFrame(DashboardWidget);
        infoCard3->setObjectName("infoCard3");
        infoCard3->setStyleSheet(QString::fromUtf8("QLabel#valueLabel {\n"
"    color: #27ae60;\n"
"}"));
        infoCard3->setFrameShape(QFrame::StyledPanel);
        infoCard3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(infoCard3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        iconLabel3 = new QLabel(infoCard3);
        iconLabel3->setObjectName("iconLabel3");

        horizontalLayout_4->addWidget(iconLabel3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        titleLabel3 = new QLabel(infoCard3);
        titleLabel3->setObjectName("titleLabel3");

        verticalLayout_4->addWidget(titleLabel3);

        revenueLabel = new QLabel(infoCard3);
        revenueLabel->setObjectName("revenueLabel");

        verticalLayout_4->addWidget(revenueLabel);


        horizontalLayout_4->addLayout(verticalLayout_4);


        gridLayout->addWidget(infoCard3, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);


        retranslateUi(DashboardWidget);

        QMetaObject::connectSlotsByName(DashboardWidget);
    } // setupUi

    void retranslateUi(QWidget *DashboardWidget)
    {
        DashboardWidget->setWindowTitle(QCoreApplication::translate("DashboardWidget", "Form", nullptr));
        iconLabel->setText(QCoreApplication::translate("DashboardWidget", "\360\237\223\246", nullptr));
        titleLabel->setText(QCoreApplication::translate("DashboardWidget", "T\341\273\225ng S\341\273\221 S\341\272\243n Ph\341\272\251m", nullptr));
        productsCountLabel->setObjectName(QCoreApplication::translate("DashboardWidget", "valueLabel", nullptr));
        productsCountLabel->setText(QCoreApplication::translate("DashboardWidget", "0", nullptr));
        iconLabel1->setText(QCoreApplication::translate("DashboardWidget", "\342\232\240\357\270\217", nullptr));
        titleLabel1->setText(QCoreApplication::translate("DashboardWidget", "S\341\272\243n Ph\341\272\251m S\341\272\257p H\341\272\277t H\303\240ng", nullptr));
        lowStockCountLabel->setObjectName(QCoreApplication::translate("DashboardWidget", "valueLabel", nullptr));
        lowStockCountLabel->setText(QCoreApplication::translate("DashboardWidget", "0", nullptr));
        iconLabel2->setText(QCoreApplication::translate("DashboardWidget", "\342\217\263", nullptr));
        titleLabel2->setText(QCoreApplication::translate("DashboardWidget", "S\341\272\243n Ph\341\272\251m S\341\272\257p H\341\272\277t H\341\272\241n", nullptr));
        expiringCountLabel->setObjectName(QCoreApplication::translate("DashboardWidget", "valueLabel", nullptr));
        expiringCountLabel->setText(QCoreApplication::translate("DashboardWidget", "0", nullptr));
        iconLabel3->setText(QCoreApplication::translate("DashboardWidget", "\360\237\222\260", nullptr));
        titleLabel3->setText(QCoreApplication::translate("DashboardWidget", "Doanh Thu Th\303\241ng N\303\240y", nullptr));
        revenueLabel->setObjectName(QCoreApplication::translate("DashboardWidget", "valueLabel", nullptr));
        revenueLabel->setText(QCoreApplication::translate("DashboardWidget", "0 VND", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardWidget: public Ui_DashboardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDWIDGET_H
