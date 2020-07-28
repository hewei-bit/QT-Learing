#-------------------------------------------------
#
# Project created by QtCreator 2020-07-27T17:29:32
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = intelligent_community
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

CONFIG += c++11

SOURCES += \
        advertisement.cpp \
        community_service.cpp \
        keybutton.cpp \
        leisure.cpp \
        login.cpp \
        main.cpp \
        intelligent_community.cpp \
        mylabel.cpp \
        news.cpp \
        selfinfo.cpp \
        softkey.cpp \
        weatherinfo.cpp

HEADERS += \
        advertisement.h \
        community_service.h \
        intelligent_community.h \
        keybutton.h \
        leisure.h \
        login.h \
        mylabel.h \
        news.h \
        selfinfo.h \
        softkey.h \
        weatherinfo.h

FORMS += \
        advertisement.ui \
        community_service.ui \
        intelligent_community.ui \
        leisure.ui \
        login.ui \
        news.ui \
        selfinfo.ui \
        softkey.ui \
        weatherinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
