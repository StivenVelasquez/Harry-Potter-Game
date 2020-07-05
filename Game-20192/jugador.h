#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Jugador: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(QGraphicsItem * parent = 0); //Constructor
    void keyPressEvent(QKeyEvent * event); //Para teclado

};

#endif // JUGADOR_H
