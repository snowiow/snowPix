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
    src/newfiledialog.cpp \
    src/newfiledialogresult.cpp \
    src/drawcontents.cpp \
    src/brushdialog.cpp

HEADERS += \
    src/drawarea.hpp \
    src/mainwindow.hpp \
    src/newfiledialog.hpp \
    src/newfiledialogresult.hpp \
    src/drawcontents.hpp \
    src/brushdialog.hpp

FORMS += src/drawarea.ui \
    src/mainwindow.ui \
    src/newfiledialog.ui \
    src/drawcontents.ui \
    src/brushdialog.ui

QMAKE_CXXFLAGS += -std=c++11\
            -Wall

RESOURCES += data/data.qrc

release: DESTDIR = build/release
debug:   DESTDIR = build/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
