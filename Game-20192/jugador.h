#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "enemigo.h"
#include "spell.h"

class Jugador: public QObject, public QGraphicsPixmapItem //Herencia de la clase QObject y QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(); //Constructor
    void keyPressEvent(QKeyEvent * event); //Para teclado

public slots:
    void spawn();//Para generacion de enemigos

private:
    int contador_Enemigos=0; //Contador de enemigos
     Enemigo *enemy; //Se instancia la clase Enemigo
};

#endif // JUGADOR_H
