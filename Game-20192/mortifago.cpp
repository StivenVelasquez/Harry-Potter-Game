#include "mortifago.h"
#include <QTimer>
#include <QGraphicsScene>

SpellMortifago *Spell; //Instanciación de la clase SpellMortifago

Mortifago::Mortifago(QObject *parent) : QObject(parent)//constructor
{
   timerImagenes=new QTimer(); //timer para actualizar las imagenes

   /*INICIALIZACION DE VARIABLES*/
   filas=0; //Filas de la imagen principal
   columnas=0;//Columnas de la imagen principal

   //Set random de los mortifagos
   if(random_Mortifago==1){ //Para que aparezca Ojo Loco

       int random_number=(rand()%100+75); //Numero aleatorio
       setPos(910,random_number);//Para que aparezca en la parte derecha de la pantalla

       pixmap =new QPixmap(":/Imagenes/Ojo loco.png");//Imagen

       //Dimensiones de cada una de las imagenes
       ancho=80.66666666;
       alto=77;

       timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
       connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar); //Se van actualizando las imagenes del sprite

       //Para mover los mortifagos
       QTimer *timer=new QTimer(this);
       connect(timer, SIGNAL(timeout()),this,SLOT(move())); //Para mover los mortifagos
       timer->start(50); //Se mueve cada 50 milisegundos

       //Para crear los hechizos
       QTimer *timerHechizos=new QTimer(this);
       connect(timerHechizos, SIGNAL(timeout()),this,SLOT(crearHechizos()));//Para crear hechizos de los mortifagos
       timerHechizos->start(1000);//Tira hechizos cada 1000 milisegundos
   }

   if(random_Mortifago==2){
       int random_number=(rand()%200+75);//Numero aleatorio

       setPos(910,random_number);//Posiciones en la pantalla, parte derecha

       pixmap =new QPixmap(":/Imagenes/Lucius.png");//Imagen

       //Dimensiones de cada una de las imagenes
       ancho=80.333333;
       alto=76.25;

       timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
       connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);//Se van actualizando las imagenes

       QTimer *timer=new QTimer(this);
       connect(timer, SIGNAL(timeout()),this,SLOT(move()));//para mover el mortifago
       timer->start(50);//Se mueve cada 50 milisegundos

       //Para crear los hechizos
       QTimer *timerHechizos=new QTimer(this);
       connect(timerHechizos, SIGNAL(timeout()),this,SLOT(crearHechizos()));//Para crear hechizos
       timerHechizos->start(1000);//Crea hechizos cada 1000 milisegundos
   }

   if(random_Mortifago==3){//Para que aparezca Voldemort
       int random_number=(rand()%300+75);//'y' random

       setPos(910,random_number);//Posicion

       pixmap =new QPixmap(":/Imagenes/Voldem.png"); //Imagen

       //Dimensiones de cada una de las imagenes
       ancho=80.333333;
       alto=76.75;

       timerImagenes->start(150);//modifica la velocidad en que itera entre las imagenes
       connect(timerImagenes,&QTimer::timeout,this,&Mortifago::actualizar);//Se van actualizando las imagenes

       QTimer *timer=new QTimer(this);
       connect(timer, SIGNAL(timeout()),this,SLOT(move()));//para mover mortifago
       timer->start(50);

       //Para crear los hechizos
       QTimer *timerHechizos=new QTimer(this);
       connect(timerHechizos, SIGNAL(timeout()),this,SLOT(crearHechizos())); //para crear hechizos
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
      columnas+=80.333333;
      if(columnas>=241){//Si llega al final de la imagen
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
        float fila=77;
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,fila, ancho, alto);//Para ir pintando las imagenes
    }

    if(random_Mortifago==2){
        float fila=76.25;
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,fila, ancho, alto);
    }
    if(random_Mortifago==3){
        float fila=76.75;
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,fila, ancho, alto);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
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


