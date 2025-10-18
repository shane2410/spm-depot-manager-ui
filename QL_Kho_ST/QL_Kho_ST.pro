
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

BUILD_DIR = $$OUT_PWD
INCLUDEPATH += $$BUILD_DIR

SOURCES += \
    backend_sources/QuanLyPhieu.cpp \
    main.cpp \
    mainwindow.cpp \
    logindialog.cpp \
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
    productmanagementwidget.cpp
HEADERS += \
    mainwindow.h \
    logindialog.h \
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
    productmanagementwidget.h


FORMS += \
    $$UI_DIR/mainwindow.ui \
    $$UI_DIR/logindialog.ui \
    ui/logindialog.ui \
    ui/productmanagementwidget.ui


DISTFILES += \
    $$PWD/Data/chitietphieunhap.csv \
    $$PWD/Data/chitietphieuxuat.csv \
    $$PWD/Data/hanghoa.csv \
    $$PWD/Data/nguoidung.csv \
    $$PWD/Data/nhacungcap.csv \
    $$PWD/Data/phieunhap.csv \
    $$PWD/Data/phieuxuat.csv


