
    QT       += core gui widgets

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

    TARGET = QL_Kho_ST
    TEMPLATE = app

    CONFIG += c++17
    TARGET = QL_Kho_ST


    HEADERS_DIR = $$PWD/backend_headers
    SOURCES_DIR = $$PWD/backend_sources
    UI_DIR = $$PWD/ui
    INCLUDEPATH += $$HEADERS_DIRR
    DATA_DIR = $$PWD/Data

    BUILD_DIR = $$OUT_PWD
    INCLUDEPATH += $$BUILD_DIR

    data.files = $$PWD/Data
    DEFINES += PROJECT_SOURCE_DIR=\\\"$$PWD\\\"

    SOURCES += \
        adminpanelwidget.cpp \
        dashboardwidget.cpp \
        main.cpp \
        mainwindow.cpp \
        logindialog.cpp \
        userdialog.cpp\
        $$SOURCES_DIR/Date.cpp \
        $$SOURCES_DIR/FileManager.cpp \
        $$SOURCES_DIR/HangHoa.cpp \
        $$SOURCES_DIR/NguoiDung.cpp \
        $$SOURCES_DIR/NhaCungCap.cpp \
        $$SOURCES_DIR/Phieu.cpp \
        $$SOURCES_DIR/QuanLyHangHoa.cpp \
        $$SOURCES_DIR/QuanLyNguoiDung.cpp \
        $$SOURCES_DIR/QuanLyNhaCungCap.cpp\
        $$SOURCES_DIR/QuanLyPhieu.cpp \
        productdialog.cpp \
        productmanagementwidget.cpp \
        receiptdialog.cpp \
        receiptmanagementwidget.cpp \
        reportwidget.cpp \
        supplierdialog.cpp \
        suppliermanagementwidget.cpp
    HEADERS += \
        adminpanelwidget.h \
        dashboardwidget.h \
        mainwindow.h \
        logindialog.h \
        userdialog.h \
        $$HEADERS_DIR/Date.h \
        $$HEADERS_DIR/FileManager.h \
        $$HEADERS_DIR/HangHoa.h \
        $$HEADERS_DIR/LinkedList.h \
        $$HEADERS_DIR/NguoiDung.h \
        $$HEADERS_DIR/NhaCungCap.h \
        $$HEADERS_DIR/Node.h \
        $$HEADERS_DIR/Phieu.h \
        $$HEADERS_DIR/QuanLyHangHoa.h \
        $$HEADERS_DIR/QuanLyNguoiDung.h \
        $$HEADERS_DIR/QuanLyNhaCungCap.h \
        $$HEADERS_DIR/QuanLyPhieu.h \
        productdialog.h \
        productmanagementwidget.h \
        receiptdialog.h \
        receiptmanagementwidget.h \
        reportwidget.h \
        supplierdialog.h \
        suppliermanagementwidget.h


    FORMS += \
        $$UI_DIR/mainwindow.ui \
        $$UI_DIR/logindialog.ui \
        $$UI_DIR/productdialog.ui \
        $$UI_DIR/logindialog.ui \
        $$UI_DIR/productmanagementwidget.ui \
        $$UI_DIR/dashboardwidget.ui \
        $$UI_DIR/receiptdialog.ui \
        $$UI_DIR/receiptmanagementwidget.ui \
        $$UI_DIR/reportwidget.ui \
        $$UI_DIR/supplierdialog.ui \
        $$UI_DIR/suppliermanagementwidget.ui \
        $$UI_DIR/adminpanelwidget.ui \
        $$UI_DIR/userdialog.ui


    DISTFILES += \
        $$DATA_DIR/chitietphieunhap \
        $$DATA_DIR/chitietphieuxuat \
        $$DATA_DIR/hanghoa \
        $$DATA_DIR/nguoidung \
        $$DATA_DIR/nhacungcap\
        $$DATA_DIR/phieunhap\
        $$DATA_DIR/phieuxuat


