#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <QGraphicsTextItem>


class Puntuacion: public QGraphicsTextItem
{
public:
    Puntuacion(QGraphicsItem * parent=0);
    int incrementar();
    int getPuntaje();

private:
    int puntaje;
};


#endif // PUNTUACION_H
