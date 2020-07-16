#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>

class Enemigo:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemigo(); //Constructor

public slots:

    void move();
    void advance2(int phase); //avance de enemigos

private:
    void DoCollision();//Colision con las paredes

};

#endif // ENEMIGO_H

