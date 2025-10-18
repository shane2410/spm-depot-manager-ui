/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginUI
{
public:
    QLabel *errorLabel;
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;

    void setupUi(QWidget *LoginUI)
    {
        if (LoginUI->objectName().isEmpty())
            LoginUI->setObjectName("LoginUI");
        LoginUI->resize(400, 179);
        errorLabel = new QLabel(LoginUI);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setGeometry(QRect(30, 160, 329, 15));
        QFont font;
        font.setPointSize(9);
        errorLabel->setFont(font);
        buttonBox = new QDialogButtonBox(LoginUI);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 110, 331, 31));
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        widget = new QWidget(LoginUI);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 30, 331, 61));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        usernameLineEdit = new QLineEdit(widget);
        usernameLineEdit->setObjectName("usernameLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);


        retranslateUi(LoginUI);

        QMetaObject::connectSlotsByName(LoginUI);
    } // setupUi

    void retranslateUi(QWidget *LoginUI)
    {
        LoginUI->setWindowTitle(QCoreApplication::translate("LoginUI", "\304\220\304\203ng nh\341\272\255p", nullptr));
        errorLabel->setText(QString());
        label->setText(QCoreApplication::translate("LoginUI", "T\303\252n \304\221\304\203ng nh\341\272\255p: ", nullptr));
        label_2->setText(QCoreApplication::translate("LoginUI", "M\341\272\255t kh\341\272\251u: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginUI: public Ui_LoginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
