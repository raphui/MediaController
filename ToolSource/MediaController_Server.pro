TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.c \
    server.c \
    mediaPlayManager.c

HEADERS += \
    server.h \
    types.h \
    mediaPlayManager.h

INCLUDEPATH += "./vlc-2.0.4/include"

LIBS += -lpthread

target.path = /home/pi/Development
INSTALLS += target
