#ifndef SNITCH_DORADA_H
#define SNITCH_DORADA_H

#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>

class Snitch_Dorada:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Snitch_Dorada(); //Constructor
    void actualizar(); //Actualizacion de imagenes

public slots:
    void move(); //Para mover la Snitch

private:
    int g; //Gravedad
    float dt; //Tiempo
    float Posx,Posy; //Para posiciones
    float Velx,Vely; //Para Velocidades
    float Acelx, Acely;//Aceleracion
    float k; //Friccion
    float tet; //Ángulo
    float v; //Magnitud de la velocidad
    float rad;//Radio de la Snitch
    float masa;//Masa
    float e;//Coeficiente de restitucion,
};

#endif // SNITCH_DORADA_H
