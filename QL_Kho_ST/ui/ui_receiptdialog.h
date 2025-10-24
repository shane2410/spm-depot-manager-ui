/********************************************************************************
** Form generated from reading UI file 'receiptdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPTDIALOG_H
#define UI_RECEIPTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiptDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *maPhieuEdit;
    QLabel *label_2;
    QDateEdit *ngayLapDateEdit;
    QLabel *providerCustomerLabel;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *nccComboBox;
    QLineEdit *khachHangEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *searchLayout;
    QLabel *label_4;
    QLineEdit *maHHEdit;
    QPushButton *findProductButton;
    QHBoxLayout *addDetailsLayout;
    QLabel *label_5;
    QLabel *tenHHLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QSpinBox *soLuongSpinBox;
    QPushButton *addItemButton;
    QTableWidget *detailsTable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLabel *tongTienLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *removeItemButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ReceiptDialog)
    {
        if (ReceiptDialog->objectName().isEmpty())
            ReceiptDialog->setObjectName("ReceiptDialog");
        ReceiptDialog->resize(750, 600);
        verticalLayout = new QVBoxLayout(ReceiptDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(ReceiptDialog);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        maPhieuEdit = new QLineEdit(groupBox);
        maPhieuEdit->setObjectName("maPhieuEdit");
        maPhieuEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, maPhieuEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        ngayLapDateEdit = new QDateEdit(groupBox);
        ngayLapDateEdit->setObjectName("ngayLapDateEdit");
        ngayLapDateEdit->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, ngayLapDateEdit);

        providerCustomerLabel = new QLabel(groupBox);
        providerCustomerLabel->setObjectName("providerCustomerLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, providerCustomerLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        nccComboBox = new QComboBox(groupBox);
        nccComboBox->setObjectName("nccComboBox");

        horizontalLayout_3->addWidget(nccComboBox);

        khachHangEdit = new QLineEdit(groupBox);
        khachHangEdit->setObjectName("khachHangEdit");

        horizontalLayout_3->addWidget(khachHangEdit);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ReceiptDialog);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        searchLayout->addWidget(label_4);

        maHHEdit = new QLineEdit(groupBox_2);
        maHHEdit->setObjectName("maHHEdit");

        searchLayout->addWidget(maHHEdit);

        findProductButton = new QPushButton(groupBox_2);
        findProductButton->setObjectName("findProductButton");

        searchLayout->addWidget(findProductButton);


        verticalLayout_2->addLayout(searchLayout);

        addDetailsLayout = new QHBoxLayout();
        addDetailsLayout->setObjectName("addDetailsLayout");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        addDetailsLayout->addWidget(label_5);

        tenHHLabel = new QLabel(groupBox_2);
        tenHHLabel->setObjectName("tenHHLabel");
        QFont font;
        font.setBold(true);
        tenHHLabel->setFont(font);
        tenHHLabel->setStyleSheet(QString::fromUtf8("color: rgb(32, 74, 135);"));

        addDetailsLayout->addWidget(tenHHLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        addDetailsLayout->addItem(horizontalSpacer_2);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        addDetailsLayout->addWidget(label_6);

        soLuongSpinBox = new QSpinBox(groupBox_2);
        soLuongSpinBox->setObjectName("soLuongSpinBox");
        soLuongSpinBox->setEnabled(false);
        soLuongSpinBox->setMinimum(1);
        soLuongSpinBox->setMaximum(99999);

        addDetailsLayout->addWidget(soLuongSpinBox);

        addItemButton = new QPushButton(groupBox_2);
        addItemButton->setObjectName("addItemButton");
        addItemButton->setEnabled(false);

        addDetailsLayout->addWidget(addItemButton);


        verticalLayout_2->addLayout(addDetailsLayout);


        verticalLayout->addWidget(groupBox_2);

        detailsTable = new QTableWidget(ReceiptDialog);
        detailsTable->setObjectName("detailsTable");
        detailsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        detailsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        detailsTable->setAlternatingRowColors(true);

        verticalLayout->addWidget(detailsTable);

        widget = new QWidget(ReceiptDialog);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_7->setFont(font1);

        horizontalLayout_2->addWidget(label_7);

        tongTienLabel = new QLabel(widget);
        tongTienLabel->setObjectName("tongTienLabel");
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        tongTienLabel->setFont(font2);
        tongTienLabel->setStyleSheet(QString::fromUtf8("color: rgb(224, 27, 36);"));

        horizontalLayout_2->addWidget(tongTienLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        removeItemButton = new QPushButton(widget);
        removeItemButton->setObjectName("removeItemButton");

        horizontalLayout_2->addWidget(removeItemButton);


        verticalLayout->addWidget(widget);

        buttonBox = new QDialogButtonBox(ReceiptDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ReceiptDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ReceiptDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ReceiptDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ReceiptDialog);
    } // setupUi

    void retranslateUi(QDialog *ReceiptDialog)
    {
        ReceiptDialog->setWindowTitle(QCoreApplication::translate("ReceiptDialog", "T\341\272\241o Phi\341\272\277u M\341\273\233i", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ReceiptDialog", "Th\303\264ng tin chung", nullptr));
        label->setText(QCoreApplication::translate("ReceiptDialog", "M\303\243 Phi\341\272\277u:", nullptr));
        label_2->setText(QCoreApplication::translate("ReceiptDialog", "Ng\303\240y L\341\272\255p:", nullptr));
        providerCustomerLabel->setText(QCoreApplication::translate("ReceiptDialog", "Nh\303\240 Cung C\341\272\245p:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ReceiptDialog", "Th\303\252m H\303\240ng H\303\263a v\303\240o Phi\341\272\277u", nullptr));
        label_4->setText(QCoreApplication::translate("ReceiptDialog", "T\303\254m M\303\243 HH:", nullptr));
        findProductButton->setText(QCoreApplication::translate("ReceiptDialog", "\360\237\224\215 T\303\254m", nullptr));
        label_5->setText(QCoreApplication::translate("ReceiptDialog", "T\303\252n HH:", nullptr));
        tenHHLabel->setText(QCoreApplication::translate("ReceiptDialog", "(Vui l\303\262ng t\303\254m m\303\243 h\303\240ng h\303\263a)", nullptr));
        label_6->setText(QCoreApplication::translate("ReceiptDialog", "S\341\273\221 l\306\260\341\273\243ng:", nullptr));
        addItemButton->setText(QCoreApplication::translate("ReceiptDialog", "\342\236\225 Th\303\252m v\303\240o phi\341\272\277u", nullptr));
        label_7->setText(QCoreApplication::translate("ReceiptDialog", "T\341\273\225ng Ti\341\273\201n:", nullptr));
        tongTienLabel->setText(QCoreApplication::translate("ReceiptDialog", "0 VND", nullptr));
        removeItemButton->setText(QCoreApplication::translate("ReceiptDialog", "\360\237\227\221\357\270\217 X\303\263a m\341\273\245c \304\221\303\243 ch\341\273\215n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReceiptDialog: public Ui_ReceiptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPTDIALOG_H
