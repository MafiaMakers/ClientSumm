QT += core gui
QT += multimedia
QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -lws2_32

RESOURCES += imgs.qrc

SOURCES += \
    audioplayer.cpp \
    clientmanager.cpp \
    main.cpp \
    camhelper.cpp \
    micphonehelper.cpp \
    samplerelative.cpp \
    systemfunctions_c.cpp \
    uimanager.cpp \
    networker_c.cpp \
    userbuttonpanel.cpp \
    videoplayer.cpp \
    videospace.cpp \
    votingsfield.cpp \
    showrole.cpp

HEADERS += \
    camhelper.h \
    audioplayer.h \
    clientmanager.h \
    include_c.h \
    micphonehelper.h \
    samplerelative.h \
    systemfunctions_c.h \
    uimanager.h \
    networker_c.h \
    defines_c.h \
    userbuttonpanel.h \
    videoplayer.h \
    videospace.h \
    votingsfield.h \
    showrole.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
