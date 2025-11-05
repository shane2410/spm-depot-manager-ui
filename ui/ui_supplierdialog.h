/********************************************************************************
** Form generated from reading UI file 'supplierdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIERDIALOG_H
#define UI_SUPPLIERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SupplierDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *maNccEdit;
    QLabel *label_2;
    QLineEdit *tenNccEdit;
    QLabel *label_3;
    QLineEdit *diaChiEdit;
    QLabel *label_4;
    QLineEdit *sdtEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SupplierDialog)
    {
        if (SupplierDialog->objectName().isEmpty())
            SupplierDialog->setObjectName("SupplierDialog");
        SupplierDialog->resize(400, 220);
        verticalLayout = new QVBoxLayout(SupplierDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(SupplierDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        maNccEdit = new QLineEdit(SupplierDialog);
        maNccEdit->setObjectName("maNccEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, maNccEdit);

        label_2 = new QLabel(SupplierDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        tenNccEdit = new QLineEdit(SupplierDialog);
        tenNccEdit->setObjectName("tenNccEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, tenNccEdit);

        label_3 = new QLabel(SupplierDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        diaChiEdit = new QLineEdit(SupplierDialog);
        diaChiEdit->setObjectName("diaChiEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, diaChiEdit);

        label_4 = new QLabel(SupplierDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        sdtEdit = new QLineEdit(SupplierDialog);
        sdtEdit->setObjectName("sdtEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, sdtEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(SupplierDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SupplierDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SupplierDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SupplierDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SupplierDialog);
    } // setupUi

    void retranslateUi(QDialog *SupplierDialog)
    {
        SupplierDialog->setWindowTitle(QCoreApplication::translate("SupplierDialog", "Th\303\264ng tin Nh\303\240 Cung C\341\272\245p", nullptr));
        label->setText(QCoreApplication::translate("SupplierDialog", "M\303\243 Nh\303\240 Cung C\341\272\245p:", nullptr));
        label_2->setText(QCoreApplication::translate("SupplierDialog", "T\303\252n Nh\303\240 Cung C\341\272\245p:", nullptr));
        label_3->setText(QCoreApplication::translate("SupplierDialog", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        label_4->setText(QCoreApplication::translate("SupplierDialog", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierDialog: public Ui_SupplierDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIERDIALOG_H
