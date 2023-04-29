QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    enemy.cpp \
    gameMenu.cpp \
    main.cpp \
    gameEngine.cpp \
    map.cpp \
    object.cpp \
    player.cpp \
    server.cpp

HEADERS += \
    Config.h \
    client.h \
    enemy.h \
    gameEngine.h \
    gameMenu.h \
    map.h \
    object.h \
    player.h \
    server.h

FORMS += \
    gameEngine.ui \
    gameMenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
