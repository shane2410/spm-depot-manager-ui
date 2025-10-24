/********************************************************************************
** Form generated from reading UI file 'adminpanelwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPANELWIDGET_H
#define UI_ADMINPANELWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminPanelWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *userManagementTab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addUserButton;
    QSpacerItem *horizontalSpacer;
    QTableWidget *userTable;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *editUserButton;
    QPushButton *deleteUserButton;

    void setupUi(QWidget *AdminPanelWidget)
    {
        if (AdminPanelWidget->objectName().isEmpty())
            AdminPanelWidget->setObjectName("AdminPanelWidget");
        AdminPanelWidget->resize(750, 550);
        verticalLayout = new QVBoxLayout(AdminPanelWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(AdminPanelWidget);
        tabWidget->setObjectName("tabWidget");
        userManagementTab = new QWidget();
        userManagementTab->setObjectName("userManagementTab");
        verticalLayout_2 = new QVBoxLayout(userManagementTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(userManagementTab);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addUserButton = new QPushButton(widget);
        addUserButton->setObjectName("addUserButton");

        horizontalLayout->addWidget(addUserButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget);

        userTable = new QTableWidget(userManagementTab);
        if (userTable->columnCount() < 3)
            userTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTable->setObjectName("userTable");
        userTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userTable->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(userTable);

        widget_2 = new QWidget(userManagementTab);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        editUserButton = new QPushButton(widget_2);
        editUserButton->setObjectName("editUserButton");

        horizontalLayout_2->addWidget(editUserButton);

        deleteUserButton = new QPushButton(widget_2);
        deleteUserButton->setObjectName("deleteUserButton");

        horizontalLayout_2->addWidget(deleteUserButton);


        verticalLayout_2->addWidget(widget_2);

        tabWidget->addTab(userManagementTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(AdminPanelWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminPanelWidget);
    } // setupUi

    void retranslateUi(QWidget *AdminPanelWidget)
    {
        AdminPanelWidget->setWindowTitle(QCoreApplication::translate("AdminPanelWidget", "Form", nullptr));
        addUserButton->setText(QCoreApplication::translate("AdminPanelWidget", "\342\236\225 Th\303\252m Ng\306\260\341\273\235i d\303\271ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem = userTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminPanelWidget", "T\303\252n \304\220\304\203ng Nh\341\272\255p", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = userTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminPanelWidget", "H\341\273\215 v\303\240 T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = userTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminPanelWidget", "Vai Tr\303\262", nullptr));
        editUserButton->setText(QCoreApplication::translate("AdminPanelWidget", "\342\234\217\357\270\217 S\341\273\255a", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("AdminPanelWidget", "\360\237\227\221\357\270\217 X\303\263a", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(userManagementTab), QCoreApplication::translate("AdminPanelWidget", "Qu\341\272\243n l\303\275 Ng\306\260\341\273\235i d\303\271ng", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPanelWidget: public Ui_AdminPanelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPANELWIDGET_H
