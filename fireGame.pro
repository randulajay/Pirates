#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T22:34:57
#
#-------------------------------------------------

QT       += core gui sql \
         multimedia \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Piaret
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    Player.cpp \
    gameover.cpp \
    life.cpp \
    menubar.cpp \
    bigenemy.cpp \
    login.cpp \
    loginform.cpp \
    signup.cpp \
    scorecard.cpp \
    about.cpp

HEADERS += \
    bullet.h \
    enemy.h \
    game.h \
    score.h \
    health.h \
    Player.h \
    gameover.h \
    life.h \
    menubar.h \
    login.h \
    loginform.h \
    signup.h \
    scorecard.h \
    about.h \
    bigenemy.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

FORMS += \
    gameover.ui \
    menubar.ui \
    login.ui \
    loginform.ui \
    signup.ui \
    scorecard.ui \
    about.ui

DISTFILES +=

