#include "snitch_dorada.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <typeinfo>

Snitch_Dorada::Snitch_Dorada():QObject (),QGraphicsPixmapItem () // Herencia de QObject y de QGraphics Item
{

    setPos(887,0); //Posicion de los dementores en la pantalla

    // Se dibuja el enemigo
    setPixmap(QPixmap(":/Imagenes/Snitch_Dorada.png"));
    setRotation(180); //Se rota este angulo

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover los dementores

    //Cada 50 milisegundos se van a move los dementores
    timer->start(50);

    Posx=0;
    Posy=0;
    Velx=30;
    Vely=30;
    Acelx=0;
    Acely=0;
    i=0;
    v=0;
    rad=20;
    masa=30;
    e=0.5;
    g=10;
    dt=0.1;

}

void Snitch_Dorada::move()
{

    // Se mueve el enemigo hacia abajo
     advance2(5);

     //Para restitución con las paredes de la pantalla
    if(pos().y() +118 > 600)//Parte inferior
    {
        Vely = -e*Vely;

        advance2(5);
    }

    if(pos().y()+118 < 90)//Parte superior
    {

        Vely = -e*Vely;
        advance2(5);
    }

   if(pos().x()+110 > 980)//Parte derecha
    {
       Velx = -e*Velx;

       advance2(5);
    }

     if(pos().x()+110 < 70)//Parte izquierda
    {

        Velx = -e*Velx;
        advance2(5);
    }

}


void Snitch_Dorada::advance2(int phase) //Para avanzar dementores
{
    if(!phase) return;

       v=sqrt(pow(Velx,2)+pow(Vely,2));

       tet=atan(Vely/Velx);

       Acelx=-(k*pow(v,2)*pow(rad,2)*cos(tet))/masa;
       Acely=((k*pow(v,2)*pow(rad,2)*sin(tet))/masa)+g;

       Velx = Velx + Acelx*dt;
       Vely = Vely + Acely*dt;

       Posx = Posx + Velx*dt + (Acelx*pow(dt,2))/2;
       Posy= Posy + Vely*dt + (Acelx*pow(dt,2))/2;
       this->setPos(Posx,Posy);//Cambia la posición de Hermione con x y y
}


void Snitch_Dorada::DoCollision()
{

     advance2(5);

}

