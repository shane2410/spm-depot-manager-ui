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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *navWidget;
    QWidget *contentWidget;
    QVBoxLayout *verticalLayout;
    QWidget *headerWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *welcomeLabel;
    QPushButton *logoutButton;
    QStackedWidget *contentStackedWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 768);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        navWidget = new QListWidget(centralWidget);
        navWidget->setObjectName("navWidget");
        navWidget->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(navWidget);

        contentWidget = new QWidget(centralWidget);
        contentWidget->setObjectName("contentWidget");
        verticalLayout = new QVBoxLayout(contentWidget);
        verticalLayout->setObjectName("verticalLayout");
        headerWidget = new QWidget(contentWidget);
        headerWidget->setObjectName("headerWidget");
        horizontalLayout_2 = new QHBoxLayout(headerWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        welcomeLabel = new QLabel(headerWidget);
        welcomeLabel->setObjectName("welcomeLabel");

        horizontalLayout_2->addWidget(welcomeLabel);

        logoutButton = new QPushButton(headerWidget);
        logoutButton->setObjectName("logoutButton");

        horizontalLayout_2->addWidget(logoutButton);


        verticalLayout->addWidget(headerWidget);

        contentStackedWidget = new QStackedWidget(contentWidget);
        contentStackedWidget->setObjectName("contentStackedWidget");

        verticalLayout->addWidget(contentStackedWidget);


        horizontalLayout->addWidget(contentWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "H\341\273\207 th\341\273\221ng Qu\341\272\243n l\303\275 Kho", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Xin ch\303\240o,", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\304\220\304\203ng xu\341\272\245t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
