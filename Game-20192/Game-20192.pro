QT       += core gui multimedia

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
    cargar_partidas.cpp \
    enemigo.cpp \
    game_over.cpp \
    ghost.cpp \
    hedwig.cpp \
    hermione.cpp \
    inicio.cpp \
    jugador.cpp \
    login.cpp \
    main.cpp \
    malfoi.cpp \
    modojuego.cpp \
    mortifago.cpp \
    nivel2.cpp \
    player1_ganador.cpp \
    player2_ganador.cpp \
    puntuacion.cpp \
    registrar.cpp \
    snitch_dorada.cpp \
    spell.cpp \
    ventana_multijugador.cpp \
    ventanajuego.cpp \
    vidas_jugador.cpp \
    you_win.cpp

HEADERS += \
    cargar_partidas.h \
    enemigo.h \
    game_over.h \
    ghost.h \
    hedwig.h \
    hermione.h \
    inicio.h \
    jugador.h \
    login.h \
    malfoi.h \
    modojuego.h \
    mortifago.h \
    nivel2.h \
    player1_ganador.h \
    player2_ganador.h \
    puntuacion.h \
    registrar.h \
    snitch_dorada.h \
    spell.h \
    ventana_multijugador.h \
    ventanajuego.h \
    vidas_jugador.h \
    you_win.h

FORMS += \
    cargar_partidas.ui \
    game_over.ui \
    inicio.ui \
    login.ui \
    modojuego.ui \
    nivel2.ui \
    player1_ganador.ui \
    player2_ganador.ui \
    registrar.ui \
    ventana_multijugador.ui \
    ventanajuego.ui \
    you_win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc

DISTFILES += \
    Imagenes/harry potter-fondo.jpg

#QMAKE_CXXFLAGS += -std=gnu++14
