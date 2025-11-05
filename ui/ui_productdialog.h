/********************************************************************************
** Form generated from reading UI file 'productdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTDIALOG_H
#define UI_PRODUCTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProductDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *maHHEdit;
    QLabel *label_2;
    QLineEdit *tenHHEdit;
    QLabel *label_3;
    QLineEdit *dvtEdit;
    QLabel *label_4;
    QDoubleSpinBox *giaNhapSpinBox;
    QLabel *label_5;
    QDoubleSpinBox *giaBanSpinBox;
    QLabel *label_6;
    QSpinBox *soLuongSpinBox;
    QLabel *label_7;
    QComboBox *nccComboBox;
    QLabel *label_8;
    QDateEdit *nsxDateEdit;
    QLabel *label_9;
    QDateEdit *hsdDateEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ProductDialog)
    {
        if (ProductDialog->objectName().isEmpty())
            ProductDialog->setObjectName("ProductDialog");
        ProductDialog->resize(450, 350);
        verticalLayout = new QVBoxLayout(ProductDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(ProductDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        maHHEdit = new QLineEdit(ProductDialog);
        maHHEdit->setObjectName("maHHEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, maHHEdit);

        label_2 = new QLabel(ProductDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        tenHHEdit = new QLineEdit(ProductDialog);
        tenHHEdit->setObjectName("tenHHEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, tenHHEdit);

        label_3 = new QLabel(ProductDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        dvtEdit = new QLineEdit(ProductDialog);
        dvtEdit->setObjectName("dvtEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, dvtEdit);

        label_4 = new QLabel(ProductDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        giaNhapSpinBox = new QDoubleSpinBox(ProductDialog);
        giaNhapSpinBox->setObjectName("giaNhapSpinBox");

        formLayout->setWidget(3, QFormLayout::FieldRole, giaNhapSpinBox);

        label_5 = new QLabel(ProductDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        giaBanSpinBox = new QDoubleSpinBox(ProductDialog);
        giaBanSpinBox->setObjectName("giaBanSpinBox");

        formLayout->setWidget(4, QFormLayout::FieldRole, giaBanSpinBox);

        label_6 = new QLabel(ProductDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        soLuongSpinBox = new QSpinBox(ProductDialog);
        soLuongSpinBox->setObjectName("soLuongSpinBox");

        formLayout->setWidget(5, QFormLayout::FieldRole, soLuongSpinBox);

        label_7 = new QLabel(ProductDialog);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        nccComboBox = new QComboBox(ProductDialog);
        nccComboBox->setObjectName("nccComboBox");

        formLayout->setWidget(6, QFormLayout::FieldRole, nccComboBox);

        label_8 = new QLabel(ProductDialog);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        nsxDateEdit = new QDateEdit(ProductDialog);
        nsxDateEdit->setObjectName("nsxDateEdit");

        formLayout->setWidget(7, QFormLayout::FieldRole, nsxDateEdit);

        label_9 = new QLabel(ProductDialog);
        label_9->setObjectName("label_9");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        hsdDateEdit = new QDateEdit(ProductDialog);
        hsdDateEdit->setObjectName("hsdDateEdit");

        formLayout->setWidget(8, QFormLayout::FieldRole, hsdDateEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ProductDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ProductDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ProductDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ProductDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ProductDialog);
    } // setupUi

    void retranslateUi(QDialog *ProductDialog)
    {
        ProductDialog->setWindowTitle(QCoreApplication::translate("ProductDialog", "Th\303\264ng tin H\303\240ng H\303\263a", nullptr));
        label->setText(QCoreApplication::translate("ProductDialog", "M\303\243 h\303\240ng h\303\263a:", nullptr));
        label_2->setText(QCoreApplication::translate("ProductDialog", "T\303\252n h\303\240ng h\303\263a:", nullptr));
        label_3->setText(QCoreApplication::translate("ProductDialog", "\304\220\306\241n v\341\273\213 t\303\255nh:", nullptr));
        label_4->setText(QCoreApplication::translate("ProductDialog", "Gi\303\241 nh\341\272\255p:", nullptr));
        label_5->setText(QCoreApplication::translate("ProductDialog", "Gi\303\241 b\303\241n:", nullptr));
        label_6->setText(QCoreApplication::translate("ProductDialog", "S\341\273\221 l\306\260\341\273\243ng t\341\273\223n:", nullptr));
        label_7->setText(QCoreApplication::translate("ProductDialog", "Nh\303\240 cung c\341\272\245p:", nullptr));
        label_8->setText(QCoreApplication::translate("ProductDialog", "Ng\303\240y s\341\272\243n xu\341\272\245t:", nullptr));
        label_9->setText(QCoreApplication::translate("ProductDialog", "H\341\272\241n s\341\273\255 d\341\273\245ng:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductDialog: public Ui_ProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTDIALOG_H
