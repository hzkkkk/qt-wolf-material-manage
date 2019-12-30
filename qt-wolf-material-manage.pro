#-------------------------------------------------
#
# Project created by QtCreator 2019-12-16T20:23:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql widgets

TARGET = qt-wolf-material-manage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    view_startPage.cpp \
    view_aboutDialog.cpp \
    control_materialDelegate.cpp \
    model_accessDatabase.cpp \
    config_configuration.cpp \
    middleware_userAuthentication.cpp \
    control_showTableDialog.cpp

HEADERS += \
    middleware_userAuthentication.h \
    view_startPage.h \
    view_aboutDialog.h \
    control_materialDelegate.h \
    model_accessDatabase.h \
    config_configuration.h \
    control_showTableDialog.h

FORMS += \
    view_aboutDialog.ui \
    view_startPage.ui \
    control_showTableDialog.ui


RESOURCES   =  material.qrc

DISTFILES +=
