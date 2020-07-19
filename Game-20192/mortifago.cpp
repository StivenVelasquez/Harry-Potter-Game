#include "mortifago.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>

/*Mortifago::Mortifago(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    //set random posicion
    int random_Mortifago = rand() % 5;
            if(random_Mortifago==1){
                int random_number=(rand()%100);
                setPos(0,random_number);

                //drew mortifago
                setPixmap(QPixmap(":/Imagenes/bellatrix.png"));

                //connect

                QTimer *timer=new QTimer(this);
                connect(timer, SIGNAL(timeout()),this,SLOT(move()));
                timer->start(50);
            }
//    setPos(random_number,0);

//    //draw the bullet
//    setPixmap(QPixmap(":/images/enemy.png"));

//    //connect
//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

//    timer->start(50);

}

void Mortifago::move()
{
    //move enemy up
    setPos(x()+5,y());
    if(pos().x() > 900){
        //decrease the health
       // game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
*/

Mortifago::Mortifago(QObject *parent) : QObject(parent)//constructor
{
   timerImagenes=new QTimer();
   filas=0;
   columnas=0;

   //set random posicion
           if(random_Mortifago==1){
               int random_number=(rand()%100+75);
               setPos(0,random_number);
               pixmap =new QPixmap(":/Imagenes/Snape.png");

               //Dimensiones de cada una de las imagenes
               ancho=50;
               alto=75;

               timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
               connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);

               QTimer *timer=new QTimer(this);
               connect(timer, SIGNAL(timeout()),this,SLOT(move()));
               timer->start(50);
           }

           if(random_Mortifago==2){
               int random_number=(rand()%200+75);
               setPos(0,random_number);
               pixmap =new QPixmap(":/Imagenes/umbridge.png");

               //Dimensiones de cada una de las imagenes
               ancho=66.6666666;
               alto=65.75;

               timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
               connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);

               QTimer *timer=new QTimer(this);
               connect(timer, SIGNAL(timeout()),this,SLOT(move()));
               timer->start(50);
           }

           if(random_Mortifago==3){
               int random_number=(rand()%300+75);
               setPos(0,random_number);
               pixmap =new QPixmap(":/Imagenes/Voldemort.png");

               //Dimensiones de cada una de las imagenes
               ancho=64.333333;
               alto=62;

               timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
               connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);

               QTimer *timer=new QTimer(this);
               connect(timer, SIGNAL(timeout()),this,SLOT(move()));
               timer->start(50);
           }
}

void Mortifago::actualizar()
{
    if(random_Mortifago==1){
      columnas+=50;
      if(columnas>=200){
         columnas=0;
      }
     this->update(-ancho,-alto,ancho, alto);//Se  actualizan las dimensiones en tiempo de que el timer vaya corriendo
    }

    if(random_Mortifago==2){
      columnas+=66.6666666;
      if(columnas>=200){
         columnas=0;
      }
     this->update(-ancho,-alto,ancho, alto);//Se  actualizan las dimensiones en tiempo de que el timer vaya corriendo
    }

    if(random_Mortifago==3){
      columnas+=64.333333;
      if(columnas>=193){
         columnas=0;
      }
     this->update(-ancho,-alto,ancho, alto);//Se  actualizan las dimensiones en tiempo de que el timer vaya corriendo
    }


}

QRectF Mortifago::boundingRect() const
{
   return QRectF(-ancho,-alto, ancho, alto) ;
}

void Mortifago::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(random_Mortifago==1){
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,150, ancho, alto);
    }

    if(random_Mortifago==2){
        float a=131.5;
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,a, ancho, alto);
    }
    if(random_Mortifago==3){
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,124, ancho, alto);
    }
}

void Mortifago::move()
{
    //move enemy up
    setPos(x()+5,y());
    if(pos().x() > 900){
        //decrease the health
       // game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}


