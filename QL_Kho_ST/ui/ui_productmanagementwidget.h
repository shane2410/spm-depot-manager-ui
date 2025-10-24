/********************************************************************************
** Form generated from reading UI file 'productmanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTMANAGEMENTWIDGET_H
#define UI_PRODUCTMANAGEMENTWIDGET_H

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

class Ui_ProductManagementWidget
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
    QTableWidget *productTable;
    QWidget *actionButtonsWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *editButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *ProductManagementWidget)
    {
        if (ProductManagementWidget->objectName().isEmpty())
            ProductManagementWidget->setObjectName("ProductManagementWidget");
        ProductManagementWidget->resize(750, 550);
        verticalLayout = new QVBoxLayout(ProductManagementWidget);
        verticalLayout->setObjectName("verticalLayout");
        toolBarWidget = new QWidget(ProductManagementWidget);
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

        productTable = new QTableWidget(ProductManagementWidget);
        productTable->setObjectName("productTable");
        productTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        productTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        productTable->setAlternatingRowColors(true);

        verticalLayout->addWidget(productTable);

        actionButtonsWidget = new QWidget(ProductManagementWidget);
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


        retranslateUi(ProductManagementWidget);

        QMetaObject::connectSlotsByName(ProductManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *ProductManagementWidget)
    {
        ProductManagementWidget->setWindowTitle(QCoreApplication::translate("ProductManagementWidget", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("ProductManagementWidget", "\342\236\225 Th\303\252m m\341\273\233i", nullptr));
        label->setText(QCoreApplication::translate("ProductManagementWidget", "T\303\254m ki\341\272\277m theo:", nullptr));
        searchCriteriaComboBox->setItemText(0, QCoreApplication::translate("ProductManagementWidget", "T\303\252n H\303\240ng H\303\263a", nullptr));
        searchCriteriaComboBox->setItemText(1, QCoreApplication::translate("ProductManagementWidget", "M\303\243 H\303\240ng H\303\263a", nullptr));

        searchLineEdit->setPlaceholderText(QCoreApplication::translate("ProductManagementWidget", "Nh\341\272\255p t\341\273\253 kh\303\263a...", nullptr));
        searchButton->setText(QCoreApplication::translate("ProductManagementWidget", "\360\237\224\215 T\303\254m", nullptr));
        editButton->setText(QCoreApplication::translate("ProductManagementWidget", "\342\234\217\357\270\217 S\341\273\255a", nullptr));
        deleteButton->setText(QCoreApplication::translate("ProductManagementWidget", "\360\237\227\221\357\270\217 X\303\263a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagementWidget: public Ui_ProductManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGEMENTWIDGET_H
