#include "enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <typeinfo>

Enemigo::Enemigo():QObject (),QGraphicsPixmapItem () // Herencia de QObject y de QGraphics Item
{
    //Posiciones aleatorias del enemigo en la pantalla

    int numero_aleatorio = (rand() % 887)+110; //Para que salgan de diferentes partes de la parte superior de la pantalla

    setPos(numero_aleatorio,0); //Posicion de los dementores en la pantalla

    // Se dibuja el enemigo
    setPixmap(QPixmap(":/Imagenes/dementor.png"));
    setRotation(180); //Se rota este angulo

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover los dementores

    timer->start(50);
}

void Enemigo::move()
{

    // Se mueve el enemigo hacia abajo

     advance2(5);

     //Para restitución con las paredes de la pantalla
    if(pos().y() +118 > 600)
    {

        DoCollision();
    }

    if(pos().y()+118 < 90)
    {

        DoCollision();
    }

   if(pos().x()+110 > 980)
    {

        DoCollision();
    }

     if(pos().x()+110 < 70)
    {

        DoCollision();
    }

}


void Enemigo::advance2(int phase)
{
    if(!phase) return;

       QPointF location = this->pos();

       setPos(mapToParent(0,-(5)));
}

void Enemigo::DoCollision()
{
    //Obtener una nueva posición

     //Cambiar el angulo de movimiento con un poco de aletoriedad
     if(((qrand() %1)))
     {
         setRotation(rotation() + (180 + (qrand() % 10)));
     }
     else
     {
         setRotation(rotation() + (180 + (qrand() % -10)));
     }

     //Ver si la nueva posicion esta dentro de los limites
     QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

     if(!scene()->sceneRect().contains((newpoint)))
     {
         // Se mueve en los limites
         newpoint = mapToParent(0,0);
     }
     else
     {
         //Se establece la nueva posicion
         qDebug() << "Collision";
         setPos(newpoint);

     }

}

