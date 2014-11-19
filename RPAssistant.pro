#-------------------------------------------------
#
# Project created by QtCreator 2014-10-27T16:28:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPAssistant
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Form.cpp \
    Item.cpp

HEADERS  += MainWindow.h \
    Form.h \
    Item.h

FORMS    += MainWindow.ui \
    Form.ui

RESOURCES += \
    ressources.qrc
