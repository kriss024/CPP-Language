QT += core
QT -= gui

TEMPLATE = app

TARGET = Aplikacja
CONFIG += c++11
CONFIG += console

SOURCES += main.cpp \
    biblioteka.cpp

HEADERS += \
    biblioteka.h

DISTFILES += \
    myapp.rc

RC_FILE = myapp.rc
