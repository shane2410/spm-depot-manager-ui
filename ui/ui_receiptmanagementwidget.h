/********************************************************************************
** Form generated from reading UI file 'receiptmanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPTMANAGEMENTWIDGET_H
#define UI_RECEIPTMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiptManagementWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *importTab;
    QVBoxLayout *verticalLayout_2;
    QSplitter *importSplitter;
    QGroupBox *importListGroupBox;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *createImportReceiptButton;
    QSpacerItem *horizontalSpacer;
    QTableWidget *importReceiptsTable;
    QGroupBox *importDetailsGroupBox;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *importDetailsTable;
    QWidget *exportTab;
    QVBoxLayout *verticalLayout_5;
    QSplitter *exportSplitter;
    QGroupBox *exportListGroupBox;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createExportReceiptButton;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *exportReceiptsTable;
    QGroupBox *exportDetailsGroupBox;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *exportDetailsTable;

    void setupUi(QWidget *ReceiptManagementWidget)
    {
        if (ReceiptManagementWidget->objectName().isEmpty())
            ReceiptManagementWidget->setObjectName("ReceiptManagementWidget");
        ReceiptManagementWidget->resize(800, 600);
        verticalLayout = new QVBoxLayout(ReceiptManagementWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(ReceiptManagementWidget);
        tabWidget->setObjectName("tabWidget");
        importTab = new QWidget();
        importTab->setObjectName("importTab");
        verticalLayout_2 = new QVBoxLayout(importTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        importSplitter = new QSplitter(importTab);
        importSplitter->setObjectName("importSplitter");
        importSplitter->setOrientation(Qt::Vertical);
        importListGroupBox = new QGroupBox(importSplitter);
        importListGroupBox->setObjectName("importListGroupBox");
        verticalLayout_3 = new QVBoxLayout(importListGroupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget = new QWidget(importListGroupBox);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        createImportReceiptButton = new QPushButton(widget);
        createImportReceiptButton->setObjectName("createImportReceiptButton");

        horizontalLayout->addWidget(createImportReceiptButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(widget);

        importReceiptsTable = new QTableWidget(importListGroupBox);
        if (importReceiptsTable->columnCount() < 4)
            importReceiptsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        importReceiptsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        importReceiptsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        importReceiptsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        importReceiptsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        importReceiptsTable->setObjectName("importReceiptsTable");
        importReceiptsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        importReceiptsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        importReceiptsTable->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(importReceiptsTable);

        importSplitter->addWidget(importListGroupBox);
        importDetailsGroupBox = new QGroupBox(importSplitter);
        importDetailsGroupBox->setObjectName("importDetailsGroupBox");
        verticalLayout_4 = new QVBoxLayout(importDetailsGroupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        importDetailsTable = new QTableWidget(importDetailsGroupBox);
        if (importDetailsTable->columnCount() < 5)
            importDetailsTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        importDetailsTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        importDetailsTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        importDetailsTable->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        importDetailsTable->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        importDetailsTable->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        importDetailsTable->setObjectName("importDetailsTable");
        importDetailsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        importDetailsTable->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout_4->addWidget(importDetailsTable);

        importSplitter->addWidget(importDetailsGroupBox);

        verticalLayout_2->addWidget(importSplitter);

        tabWidget->addTab(importTab, QString());
        exportTab = new QWidget();
        exportTab->setObjectName("exportTab");
        verticalLayout_5 = new QVBoxLayout(exportTab);
        verticalLayout_5->setObjectName("verticalLayout_5");
        exportSplitter = new QSplitter(exportTab);
        exportSplitter->setObjectName("exportSplitter");
        exportSplitter->setOrientation(Qt::Vertical);
        exportListGroupBox = new QGroupBox(exportSplitter);
        exportListGroupBox->setObjectName("exportListGroupBox");
        verticalLayout_6 = new QVBoxLayout(exportListGroupBox);
        verticalLayout_6->setObjectName("verticalLayout_6");
        widget_2 = new QWidget(exportListGroupBox);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        createExportReceiptButton = new QPushButton(widget_2);
        createExportReceiptButton->setObjectName("createExportReceiptButton");

        horizontalLayout_2->addWidget(createExportReceiptButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_6->addWidget(widget_2);

        exportReceiptsTable = new QTableWidget(exportListGroupBox);
        if (exportReceiptsTable->columnCount() < 4)
            exportReceiptsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        exportReceiptsTable->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        exportReceiptsTable->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        exportReceiptsTable->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        exportReceiptsTable->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        exportReceiptsTable->setObjectName("exportReceiptsTable");
        exportReceiptsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        exportReceiptsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        exportReceiptsTable->setAlternatingRowColors(true);

        verticalLayout_6->addWidget(exportReceiptsTable);

        exportSplitter->addWidget(exportListGroupBox);
        exportDetailsGroupBox = new QGroupBox(exportSplitter);
        exportDetailsGroupBox->setObjectName("exportDetailsGroupBox");
        verticalLayout_7 = new QVBoxLayout(exportDetailsGroupBox);
        verticalLayout_7->setObjectName("verticalLayout_7");
        exportDetailsTable = new QTableWidget(exportDetailsGroupBox);
        if (exportDetailsTable->columnCount() < 5)
            exportDetailsTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        exportDetailsTable->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        exportDetailsTable->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        exportDetailsTable->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        exportDetailsTable->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        exportDetailsTable->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        exportDetailsTable->setObjectName("exportDetailsTable");
        exportDetailsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        exportDetailsTable->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout_7->addWidget(exportDetailsTable);

        exportSplitter->addWidget(exportDetailsGroupBox);

        verticalLayout_5->addWidget(exportSplitter);

        tabWidget->addTab(exportTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(ReceiptManagementWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReceiptManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *ReceiptManagementWidget)
    {
        ReceiptManagementWidget->setWindowTitle(QCoreApplication::translate("ReceiptManagementWidget", "Form", nullptr));
        importListGroupBox->setTitle(QCoreApplication::translate("ReceiptManagementWidget", "Danh s\303\241ch Phi\341\272\277u Nh\341\272\255p", nullptr));
        createImportReceiptButton->setText(QCoreApplication::translate("ReceiptManagementWidget", "\342\236\225 T\341\272\241o Phi\341\272\277u Nh\341\272\255p M\341\273\233i", nullptr));
        QTableWidgetItem *___qtablewidgetitem = importReceiptsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ReceiptManagementWidget", "M\303\243 Phi\341\272\277u", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = importReceiptsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ReceiptManagementWidget", "Ng\303\240y Nh\341\272\255p", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = importReceiptsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ReceiptManagementWidget", "Nh\303\240 Cung C\341\272\245p", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = importReceiptsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ReceiptManagementWidget", "T\341\273\225ng Ti\341\273\201n", nullptr));
        importDetailsGroupBox->setTitle(QCoreApplication::translate("ReceiptManagementWidget", "Chi ti\341\272\277t Phi\341\272\277u Nh\341\272\255p \304\221\303\243 ch\341\273\215n", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = importDetailsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ReceiptManagementWidget", "M\303\243 HH", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = importDetailsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ReceiptManagementWidget", "T\303\252n H\303\240ng H\303\263a", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = importDetailsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ReceiptManagementWidget", "S\341\273\221 L\306\260\341\273\243ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = importDetailsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ReceiptManagementWidget", "\304\220\306\241n Gi\303\241 Nh\341\272\255p", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = importDetailsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ReceiptManagementWidget", "Th\303\240nh Ti\341\273\201n", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(importTab), QCoreApplication::translate("ReceiptManagementWidget", "Qu\341\272\243n l\303\275 Phi\341\272\277u Nh\341\272\255p", nullptr));
        exportListGroupBox->setTitle(QCoreApplication::translate("ReceiptManagementWidget", "Danh s\303\241ch Phi\341\272\277u Xu\341\272\245t", nullptr));
        createExportReceiptButton->setText(QCoreApplication::translate("ReceiptManagementWidget", "\360\237\223\244 T\341\272\241o Phi\341\272\277u Xu\341\272\245t M\341\273\233i", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = exportReceiptsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ReceiptManagementWidget", "M\303\243 Phi\341\272\277u", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = exportReceiptsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ReceiptManagementWidget", "Ng\303\240y Xu\341\272\245t", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = exportReceiptsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ReceiptManagementWidget", "T\303\252n Kh\303\241ch H\303\240ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = exportReceiptsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ReceiptManagementWidget", "T\341\273\225ng Ti\341\273\201n", nullptr));
        exportDetailsGroupBox->setTitle(QCoreApplication::translate("ReceiptManagementWidget", "Chi ti\341\272\277t Phi\341\272\277u Xu\341\272\245t \304\221\303\243 ch\341\273\215n", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = exportDetailsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("ReceiptManagementWidget", "M\303\243 HH", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = exportDetailsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("ReceiptManagementWidget", "T\303\252n H\303\240ng H\303\263a", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = exportDetailsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("ReceiptManagementWidget", "S\341\273\221 L\306\260\341\273\243ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = exportDetailsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("ReceiptManagementWidget", "\304\220\306\241n Gi\303\241 B\303\241n", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = exportDetailsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("ReceiptManagementWidget", "Th\303\240nh Ti\341\273\201n", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(exportTab), QCoreApplication::translate("ReceiptManagementWidget", "Qu\341\272\243n l\303\275 Phi\341\272\277u Xu\341\272\245t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReceiptManagementWidget: public Ui_ReceiptManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPTMANAGEMENTWIDGET_H
