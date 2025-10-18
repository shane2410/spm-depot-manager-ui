/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGoodsManagement;
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget1;
    QLabel *welcomeLabel;
    QPushButton *logoutButton;
    QHBoxLayout *horizontalLayout;
    QListWidget *navWidget;
    QStackedWidget *contentStackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(914, 583);
        actionGoodsManagement = new QAction(MainWindow);
        actionGoodsManagement->setObjectName("actionGoodsManagement");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 911, 581));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        welcomeLabel = new QLabel(widget1);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(20, 7, 75, 21));
        QFont font;
        font.setPointSize(11);
        welcomeLabel->setFont(font);
        logoutButton = new QPushButton(widget1);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(810, 10, 76, 16));

        verticalLayout->addWidget(widget1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        navWidget = new QListWidget(widget);
        navWidget->setObjectName("navWidget");

        horizontalLayout->addWidget(navWidget);

        contentStackedWidget = new QStackedWidget(widget);
        contentStackedWidget->setObjectName("contentStackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        contentStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        contentStackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(contentStackedWidget);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 17);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionGoodsManagement->setText(QCoreApplication::translate("MainWindow", "Qu\341\272\243n l\303\275 H\303\240ng H\303\263a", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Xin ch\303\240o, ...", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\304\220\304\203ng xu\341\272\245t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
