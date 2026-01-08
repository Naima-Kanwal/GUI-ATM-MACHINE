QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    account.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    account.h \
    mainwindow.h

FORMS += \
    mainwindow.ui


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
