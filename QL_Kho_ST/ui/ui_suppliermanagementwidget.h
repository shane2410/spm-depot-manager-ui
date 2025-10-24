/********************************************************************************
** Form generated from reading UI file 'suppliermanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIERMANAGEMENTWIDGET_H
#define UI_SUPPLIERMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupplierManagementWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *toolBarWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QComboBox *searchCriteriaComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QTableWidget *supplierTable;
    QWidget *actionButtonsWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *editButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *SupplierManagementWidget)
    {
        if (SupplierManagementWidget->objectName().isEmpty())
            SupplierManagementWidget->setObjectName("SupplierManagementWidget");
        SupplierManagementWidget->resize(750, 550);
        verticalLayout = new QVBoxLayout(SupplierManagementWidget);
        verticalLayout->setObjectName("verticalLayout");
        toolBarWidget = new QWidget(SupplierManagementWidget);
        toolBarWidget->setObjectName("toolBarWidget");
        horizontalLayout = new QHBoxLayout(toolBarWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(toolBarWidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(toolBarWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        searchCriteriaComboBox = new QComboBox(toolBarWidget);
        searchCriteriaComboBox->addItem(QString());
        searchCriteriaComboBox->addItem(QString());
        searchCriteriaComboBox->setObjectName("searchCriteriaComboBox");

        horizontalLayout->addWidget(searchCriteriaComboBox);

        searchLineEdit = new QLineEdit(toolBarWidget);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        searchButton = new QPushButton(toolBarWidget);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addWidget(toolBarWidget);

        supplierTable = new QTableWidget(SupplierManagementWidget);
        if (supplierTable->columnCount() < 4)
            supplierTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        supplierTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        supplierTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        supplierTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        supplierTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        supplierTable->setObjectName("supplierTable");
        supplierTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        supplierTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        supplierTable->setAlternatingRowColors(true);

        verticalLayout->addWidget(supplierTable);

        actionButtonsWidget = new QWidget(SupplierManagementWidget);
        actionButtonsWidget->setObjectName("actionButtonsWidget");
        horizontalLayout_2 = new QHBoxLayout(actionButtonsWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        editButton = new QPushButton(actionButtonsWidget);
        editButton->setObjectName("editButton");

        horizontalLayout_2->addWidget(editButton);

        deleteButton = new QPushButton(actionButtonsWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout->addWidget(actionButtonsWidget);


        retranslateUi(SupplierManagementWidget);

        QMetaObject::connectSlotsByName(SupplierManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *SupplierManagementWidget)
    {
        SupplierManagementWidget->setWindowTitle(QCoreApplication::translate("SupplierManagementWidget", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("SupplierManagementWidget", "\342\236\225 Th\303\252m Nh\303\240 Cung C\341\272\245p", nullptr));
        label->setText(QCoreApplication::translate("SupplierManagementWidget", "T\303\254m ki\341\272\277m theo:", nullptr));
        searchCriteriaComboBox->setItemText(0, QCoreApplication::translate("SupplierManagementWidget", "T\303\252n Nh\303\240 Cung C\341\272\245p", nullptr));
        searchCriteriaComboBox->setItemText(1, QCoreApplication::translate("SupplierManagementWidget", "M\303\243 Nh\303\240 Cung C\341\272\245p", nullptr));

        searchLineEdit->setPlaceholderText(QCoreApplication::translate("SupplierManagementWidget", "Nh\341\272\255p t\341\273\253 kh\303\263a...", nullptr));
        searchButton->setText(QCoreApplication::translate("SupplierManagementWidget", "\360\237\224\215 T\303\254m", nullptr));
        QTableWidgetItem *___qtablewidgetitem = supplierTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SupplierManagementWidget", "M\303\243 NCC", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = supplierTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SupplierManagementWidget", "T\303\252n Nh\303\240 Cung C\341\272\245p", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = supplierTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SupplierManagementWidget", "\304\220\341\273\213a ch\341\273\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = supplierTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SupplierManagementWidget", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i", nullptr));
        editButton->setText(QCoreApplication::translate("SupplierManagementWidget", "\342\234\217\357\270\217 S\341\273\255a", nullptr));
        deleteButton->setText(QCoreApplication::translate("SupplierManagementWidget", "\360\237\227\221\357\270\217 X\303\263a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierManagementWidget: public Ui_SupplierManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIERMANAGEMENTWIDGET_H
