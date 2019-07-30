#-------------------------------------------------
#
# Project created by QtCreator 2019-05-26T23:01:10
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = TechCloud
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

#Libs
INCLUDEPATH += \
            include\ui \

INCLUDEPATH += C:\libs\vcpkg\installed\x64-windows\include\*
LIBS += C:\libs\vcpkg\installed\x64-windows\lib\*

#Set res or Icon
#win32:RC_ICONS += res\icon\computing-cloud.svg

SOURCES += \
        main.cpp \
        src\ui\ResultWindow.cpp \
        src\ui\MainWindow.cpp

HEADERS += \
        include\ui\ResultWindow.h \
        include\ui\MainWindow.h

FORMS += \
        src\ui\ResultWindow.ui \
        src\ui\MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
