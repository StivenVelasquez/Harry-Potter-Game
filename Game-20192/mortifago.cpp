#include "mortifago.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>

SpellMortifago *Spell; //Instanciacion de la clase SpellMortifago

Mortifago::Mortifago(QObject *parent) : QObject(parent)//constructor
{
   timerImagenes=new QTimer();
   filas=0;
   columnas=0;

   //Set random de los mortifagos
           if(random_Mortifago==1){ //Para que aparezca snape
               int random_number=(rand()%100+75); //Aparece en la parte derecha de la pantalla
               setPos(910,random_number);

               pixmap =new QPixmap(":/Imagenes/Snape.png");//Imagenes

               //Dimensiones de cada una de las imagenes
               ancho=50;
               alto=75;

               timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
               connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);

               //Para mover los mortifagos
               QTimer *timer=new QTimer(this);
               connect(timer, SIGNAL(timeout()),this,SLOT(move()));
               timer->start(50);

               //Para crear los hechizos
               QTimer *timerHechizos=new QTimer(this);
               connect(timerHechizos, SIGNAL(timeout()),this,SLOT(crearHechizos()));
               timerHechizos->start(1000);

           }

           if(random_Mortifago==2){
               int random_number=(rand()%200+75);
               setPos(910,random_number);
               pixmap =new QPixmap(":/Imagenes/umbridge.png");//   Antes era dolores

               //Dimensiones de cada una de las imagenes
               ancho=66.6666666;
               alto=65.75;
              // ancho=50;
              // alto=75;
               timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
               connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);

               QTimer *timer=new QTimer(this);
               connect(timer, SIGNAL(timeout()),this,SLOT(move()));
               timer->start(50);
           }

           if(random_Mortifago==3){
               int random_number=(rand()%300+75);
               setPos(910,random_number);
               pixmap =new QPixmap(":/Imagenes/Voldemort.png");// antes era voldemort

               //Dimensiones de cada una de las imagenes
               ancho=64.333333;
               alto=62;
               //ancho=50;
               //alto=75;

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
      if(columnas>=200){//Si llega al final de la imagen
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

void Mortifago::crearHechizos()
{
    Spell = new SpellMortifago(); //Se crea el hechizo
    Spell->setPos(x()-60,y()-50);//Posicion del hechizo en el mortifago
    scene()->addItem(Spell); //Se añade a la escena
}

QRectF Mortifago::boundingRect() const
{
   return QRectF(-ancho,-alto, ancho, alto) ;
}

void Mortifago::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(random_Mortifago==1){
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,75, ancho, alto);
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
    setPos(x()-5,y());
    if(pos().x() < 0){
        //decrease the health
       // game->health->decrease();

        scene()->removeItem(this);
        delete this;

    }

}


