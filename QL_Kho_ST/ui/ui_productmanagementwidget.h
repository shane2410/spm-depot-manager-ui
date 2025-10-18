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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManagementWidget
{
public:
    QTableWidget *productTable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *searchButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *editButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *ProductManagementWidget)
    {
        if (ProductManagementWidget->objectName().isEmpty())
            ProductManagementWidget->setObjectName("ProductManagementWidget");
        ProductManagementWidget->resize(743, 569);
        productTable = new QTableWidget(ProductManagementWidget);
        if (productTable->columnCount() < 14)
            productTable->setColumnCount(14);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        productTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        productTable->setObjectName("productTable");
        productTable->setGeometry(QRect(10, 70, 721, 431));
        productTable->setTabKeyNavigation(true);
        productTable->setProperty("showDropIndicator", QVariant(true));
        productTable->setDragDropOverwriteMode(true);
        productTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        productTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        productTable->setColumnCount(14);
        widget = new QWidget(ProductManagementWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 30, 721, 30));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(300);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(widget);
        addButton->setObjectName("addButton");

        horizontalLayout_2->addWidget(addButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        searchButton = new QPushButton(widget);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        widget1 = new QWidget(ProductManagementWidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(387, 520, 251, 28));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(21);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        editButton = new QPushButton(widget1);
        editButton->setObjectName("editButton");

        horizontalLayout_3->addWidget(editButton);

        deleteButton = new QPushButton(widget1);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_3->addWidget(deleteButton);


        retranslateUi(ProductManagementWidget);

        QMetaObject::connectSlotsByName(ProductManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *ProductManagementWidget)
    {
        ProductManagementWidget->setWindowTitle(QCoreApplication::translate("ProductManagementWidget", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = productTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ProductManagementWidget", "M\303\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = productTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ProductManagementWidget", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = productTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ProductManagementWidget", "\304\220\306\241n v\341\273\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = productTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ProductManagementWidget", "S\341\273\221 l\306\260\341\273\243ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = productTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ProductManagementWidget", "Gi\303\241 b\303\241n", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = productTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ProductManagementWidget", "HSD", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = productTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ProductManagementWidget", "H\303\240nh \304\221\341\273\231ng", nullptr));
        addButton->setText(QCoreApplication::translate("ProductManagementWidget", "Th\303\252m m\341\273\233i", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("ProductManagementWidget", "Nh\341\272\255p t\341\273\253 kh\303\263a", "kh\303\263a"));
        searchButton->setText(QCoreApplication::translate("ProductManagementWidget", "T\303\254m ki\341\272\277m", nullptr));
        editButton->setText(QCoreApplication::translate("ProductManagementWidget", "S\341\273\255a", nullptr));
        deleteButton->setText(QCoreApplication::translate("ProductManagementWidget", "X\303\263a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagementWidget: public Ui_ProductManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGEMENTWIDGET_H
