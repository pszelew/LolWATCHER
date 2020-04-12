QT       += core gui network
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

SOURCES += \
    author.cpp \
    enemy.cpp \
    enemy_window.cpp \
    events_window.cpp \
    hero_window.cpp \
    main.cpp \
    menu.cpp \
    start.cpp \
    tips_window.cpp \
    ustawienia.cpp \
    your_hero.cpp

HEADERS += \
    author.h \
    enemy.h \
    enemy_window.h \
    events_window.h \
    hero_window.h \
    menu.h \
    start.h \
    tips_window.h \
    ustawienia.h \
    your_hero.h

FORMS += \
    author.ui \
    enemy_window.ui \
    events_window.ui \
    hero_window.ui \
    menu.ui \
    start.ui \
    tips_window.ui \
    ustawienia.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc

unix: CONFIG += link_pkgconfig


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../vcpkg/installed/x64-linux/lib/release/ -ljsoncpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../vcpkg/installed/x64-linux/lib/debug/ -ljsoncpp
else:unix: LIBS += -L$$PWD/../../vcpkg/installed/x64-linux/lib/ -ljsoncpp

INCLUDEPATH += $$PWD/../../vcpkg/installed/x64-linux/include
DEPENDPATH += $$PWD/../../vcpkg/installed/x64-linux/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../vcpkg/installed/x64-linux/lib/release/libjsoncpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../vcpkg/installed/x64-linux/lib/debug/libjsoncpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../vcpkg/installed/x64-linux/lib/release/jsoncpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../vcpkg/installed/x64-linux/lib/debug/jsoncpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../vcpkg/installed/x64-linux/lib/libjsoncpp.a
