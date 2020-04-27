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
    Backend/audioplayer.cpp \
    Backend/camhelper.cpp \
    Backend/micphonehelper.cpp \
    Main-widget/samplerelative.cpp \
    Main-widget/showrole.cpp \
    Main-widget/uimanager.cpp \
    Main-widget/userbuttonpanel.cpp \
    Main-widget/videoplayer.cpp \
    Main-widget/videospace.cpp \
    Main-widget/votingsfield.cpp \
    Network/networker_c.cpp \
    Network/systemfunctions_c.cpp \
    Settings-widget/idcheckbox.cpp \
    Settings-widget/idpushbutton.cpp \
    Settings-widget/idspinbox.cpp \
    Settings-widget/settingswindow.cpp \
    clientmanager.cpp \
    main.cpp

HEADERS += \
    Backend/audioplayer.h \
    Backend/camhelper.h \
    Backend/micphonehelper.h \
    Main-widget/samplerelative.h \
    Main-widget/showrole.h \
    Main-widget/uimanager.h \
    Main-widget/userbuttonpanel.h \
    Main-widget/videoplayer.h \
    Main-widget/videospace.h \
    Main-widget/votingsfield.h \
    Network/defines_c.h \
    Network/include_c.h \
    Network/networker_c.h \
    Network/systemfunctions_c.h \
    Settings-widget/idcheckbox.h \
    Settings-widget/idpushbutton.h \
    Settings-widget/idspinbox.h \
    Settings-widget/settingswindow.h \
    clientmanager.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
