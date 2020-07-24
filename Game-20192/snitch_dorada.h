#ifndef SNITCH_DORADA_H
#define SNITCH_DORADA_H

#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>

//#define dt 0.1
//#define g 10


class Snitch_Dorada:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Snitch_Dorada(); //Constructor

    int vo;
    int g;
    float dt;
    float Posx,Posy,i; //Para posiciones
    float Velx,Vely; //Para Velocidades
    float Acelx, Acely;//Aceleracion
    float k; //Friccion
    float tet;
    float v;
    float rad;
    float masa;
    float e;

public slots:

    void move();
    void advance2(int phase); //avance de enemigos

private:
    void DoCollision();//Colision con las paredes
};

#endif // SNITCH_DORADA_H
