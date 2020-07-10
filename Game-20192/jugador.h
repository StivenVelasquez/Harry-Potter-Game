#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "enemigo.h"
#include "spell.h"

class Jugador: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(QGraphicsItem * parent = 0); //Constructor
    void keyPressEvent(QKeyEvent * event); //Para teclado

public slots:
    void spawn();

private:
    int contador_Enemigos=0;
    Enemigo *enemy; //Se instancia la clase Enemigo

};

#endif // JUGADOR_H
