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
    void advance2(int phase);

private:
    void DoCollision();

};

#endif // ENEMIGO_H

