#include "snitch_dorada.h"

#include <QTimer>
#include <QGraphicsScene>

Snitch_Dorada::Snitch_Dorada():QObject (),QGraphicsPixmapItem () // Herencia de QObject y de QGraphics Item
{

    setPos(887,0); //Posicion de la Snitch en la pantalla

    // Se dibuja la Snitch
    setPixmap(QPixmap(":/Imagenes/Snitch_Golden.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover la Snitch

    //Cada 50 milisegundos se va a mover la Snitch
    timer->start(50);

    //Se inicilizan variables
    //-----------------------------------------------------

    //Posiciones
    Posx=0;
    Posy=0;
    //Velocidades
    Velx=60;
    Vely=60;

    v=0; //Magnitud de la velocidad

    //Aceleraciones
    Acelx=0;
    Acely=0;

    rad=20; //Radio de la snitch
    masa=30;//Masa
    e=0.5;//Coefienciente de restitucion
    k=11/1000; //Parametro de rozamiento

    g=10;//Gravedad
    dt=0.1;//Tiempo
}

void Snitch_Dorada::move()
{
     actualizar(); //Se actualiza el movimiento

     //Para colision con las paredes de la pantalla
     if(pos().y() +34 >470 )//Parte inferior
    {
        Vely = -e*Vely; //Restitucion
        actualizar(); //Se actualiza el movimiento
    }

    if(pos().y()+69 < 70)//Parte superior
    {

        Vely = -e*Vely; //Restitucion
        actualizar();//Se actualiza el movimiento
    }

   if(pos().x()+69 > 850)//Parte derecha
    {
       Velx = -e*Velx; //Restitucion
       actualizar(); //Se actualiza el movimiento
    }

     if(pos().x()+69 < 30)//Parte izquierda
    {

        Velx = -e*Velx;//Restitucion
        actualizar();//Se actualiza el movimiento
    }
}

void Snitch_Dorada::actualizar() //Para avanzar dementores
{

       v=sqrt(pow(Velx,2)+pow(Vely,2)); //Magnitud de la velocidad

       //Ángulo
       tet=atan(Vely/Velx);

       //Aceleracion
       Acelx=-(k*pow(v,2)*pow(rad,2)*cos(tet))/masa;
       Acely=(k*(pow(v,2)*pow(rad,2)*sin(tet))/masa)+g;

       //Velocidades
        Velx = (Velx + Acelx*dt);
        Vely = (Vely + Acely*dt);


       //Posiciones
       Posx = Posx + Velx*dt + (Acelx*pow(dt,2))/2;
       Posy= Posy + Vely*dt + (Acelx*pow(dt,2))/2;


       this->setPos(Posx,Posy);//Cambia la posición de la snitch
}
