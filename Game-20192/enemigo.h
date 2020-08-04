#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Enemigo:public QObject,public QGraphicsPixmapItem //Se hereda de estas clases para utilizar sus funciones públicas
{
    Q_OBJECT

public:
    Enemigo(); //Constructor
    void actualizar(); //Actualizar movimientos
    void DoCollision();//Colision con las paredes

public slots:
    void move(); //Para mover los enemigos
};

#endif // ENEMIGO_H

