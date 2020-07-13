#ifndef JUGADOR2_H
#define JUGADOR2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "enemigo.h"
#include "spell.h"

class Jugador2: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador2(QGraphicsItem * parent = 0); //Constructor
    void keyPressEvent(QKeyEvent * event); //Para teclado
private:
    int contador_Enemigos=0;
    Enemigo *enemy; //Se instancia la clase Enemigo

};

#endif // JUGADOR2_H
