#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <QGraphicsTextItem>

class Puntuacion: public QGraphicsTextItem//Se hereda de QGraphicsTextItem
{
public:
    Puntuacion(int x);//Constructor
    int incrementar();//Se incrementa
    int getPuntaje();//Para obtener Puntaje

private:
    int puntaje;
};


#endif // PUNTUACION_H
