#-------------------------------------------------
#
# Project created by QtCreator 2014-04-07T11:29:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snowPix
TEMPLATE = app


SOURCES += src/drawarea.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/newfiledialog.cpp

HEADERS += \
    src/drawarea.hpp \
    src/mainwindow.hpp \
    src/newfiledialog.hpp

FORMS += src/drawarea.ui \
    src/mainwindow.ui \
    src/newfiledialog.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES += data/data.qrc
