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
           if(random_Mortifago==1){ //Para que aparezca Ojo Loco
               int random_number=(rand()%100+75); //Aparece en la parte derecha de la pantalla
               setPos(910,random_number);

               pixmap =new QPixmap(":/Imagenes/Ojo loco.png");//Imagenes

               //Dimensiones de cada una de las imagenes
               ancho=80.66666666;
               alto=77;

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
               int random_number=(rand()%200+75);//Para que aparezca Dollores
               setPos(910,random_number);//Posiciones en la pantalla
               pixmap =new QPixmap(":/Imagenes/Dollores.png");

               //Dimensiones de cada una de las imagenes
               ancho=80.66666;
               alto=77.75;
               timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
               connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);

               QTimer *timer=new QTimer(this);
               connect(timer, SIGNAL(timeout()),this,SLOT(move()));
               timer->start(50);

               //Para crear los hechizos
               QTimer *timerHechizos=new QTimer(this);
               connect(timerHechizos, SIGNAL(timeout()),this,SLOT(crearHechizos()));
               timerHechizos->start(1000);
           }

           if(random_Mortifago==3){//Para que aparezca Voldemort
               int random_number=(rand()%300+75);//'y' random
               setPos(910,random_number);//Posicion
               pixmap =new QPixmap(":/Imagenes/Voldem.png"); //Imagen

               //Dimensiones de cada una de las imagenes
               ancho=80.333333;
               alto=76.75;

               timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
               connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);

               QTimer *timer=new QTimer(this);
               connect(timer, SIGNAL(timeout()),this,SLOT(move()));
               timer->start(50);

               //Para crear los hechizos
               QTimer *timerHechizos=new QTimer(this);
               connect(timerHechizos, SIGNAL(timeout()),this,SLOT(crearHechizos()));
               timerHechizos->start(1000);
           }
}

void Mortifago::actualizar()
{
    if(random_Mortifago==1){
      columnas+=80.66666666;
      if(columnas>=242){//Si llega al final de la imagen
         columnas=0;//Se hace cero
      }
     this->update(-ancho,-alto,ancho, alto);//Se  actualizan las dimensiones en tiempo de que el timer vaya corriendo

       }

    if(random_Mortifago==2){
      columnas+=80.666666;
      if(columnas>=242){//Si llega al final de la imagen
         columnas=0;
      }
     this->update(-ancho,-alto,ancho, alto);//Se  actualizan las dimensiones en tiempo de que el timer vaya corriendo
    }

    if(random_Mortifago==3){
      columnas+=80.333333;
      if(columnas>=241){//Si llega al final de la imagen
         columnas=0;
      }
     this->update(-ancho,-alto,ancho, alto);//Se  actualizan las dimensiones en tiempo de que el timer vaya corriendo
    }


}

void Mortifago::crearHechizos()
{
    Spell = new SpellMortifago(); //Se crea el hechizo
    Spell->setPos(x()-100,y()-50);//Posicion del hechizo en el mortifago
    scene()->addItem(Spell); //Se añade a la escena
}

QRectF Mortifago::boundingRect() const
{
   return QRectF(-ancho,-alto, ancho, alto) ;
}

void Mortifago::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)//Para pintar los Pixmap
{
    if(random_Mortifago==1){
        float a=77;
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,a, ancho, alto);
    }

    if(random_Mortifago==2){
        float a=75.75;
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,a, ancho, alto);
    }
    if(random_Mortifago==3){
        float a=76.75;
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,a, ancho, alto);
    }
}

void Mortifago::move()
{
    //move mortifago
    setPos(x()-5,y());//Se le va restando a la posicion en 'x'
    if(pos().x() < 0){;
        scene()->removeItem(this);//Se remueve
        delete this;//Se elimina de la memoria

    }

}


