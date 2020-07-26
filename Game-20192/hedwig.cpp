#include "hedwig.h"
#include <QGraphicsScene>

Hedwig::Hedwig(float x, float y, float vx, float vy, float m, float r, QObject *parent): QObject(parent)//Constructor de la clase
 {

    //Inicializacion de variables
      Pposx =x;
      Pposy = y;
      Pvelx = vx;
      Pvely =vy;
      Pmasa=m;
      Pradio =r;
      Velx=0;
      Vely=0;
      Acelx=0;
      Acely=0;

      timer=new QTimer(); //Se crea el timer para actualizar la imagenes
      filas=0; //Filas de la imagen original
      columnas=0;//Columnas de la imagen orginal
      pixmap =new QPixmap(":/Imagenes/Hedwig.png"); //Imagen original

      //Dimensiones de cada una de las imagenes
      ancho=95;
      alto=97.83333333;

      timer->start(150);//modifica la velocidad en que itera entre las imagenes
      connect(timer,&QTimer::timeout,this,&Hedwig::actualizacion);//Se actualizan las imagenes

}

void Hedwig::actualizacion()
{
   columnas+=95;//Para trabajar por sectores de la imagen principal
   if(columnas>=760){ //Si se llega esta posicion de la imagen
       columnas=0;
   }
   this->update(-ancho,-alto,ancho, alto);//Se  actualizan las dimensiones en tiempo de que el timer vaya corriendo
}

QRectF Hedwig::boundingRect() const
{
   return QRectF(-ancho,-alto, ancho, alto) ;
}

void Hedwig::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    float Fila=97.83333; //Fila de la imagen en la que trabajara
    painter->drawPixmap(-ancho, -alto,*pixmap,columnas,Fila, ancho, alto);//Para dibujar la imagen
}

void Hedwig::ModValor()
{
    Pposx=Posx;
    Pposy=Posy;
    Pvelx=Velx;
    Pvely=Vely;
    Acelx=0;
    Acely=0;

}

void Hedwig::mover(Hedwig *A)
{

    float dist,ang;

    dist=sqrt( pow(A->Pposx-Pposx,2)+ pow( A->Pposy-Pposy,2));
    ang= atan2(( A->Pposy-Pposy) , A->Pposx-Pposx);

    //Aceleraciones
    Acelx +=(((G * A->Pmasa) / pow(dist,2))*cos(ang) );
    Acely += (((G * A->Pmasa) / pow(dist,2))*sin(ang));

    //Velocidades
    Velx= Pvelx + (Acelx* dtt);
    Vely= Pvely + (Acely* dtt);

    //Posiciones
    Posx=Pposx+(Pvelx * dtt) + ((Acelx* pow(dtt,2)/2));
    Posy=Pposy+(Pvely * dtt) + ((Acely* pow(dtt,2)/2));

    this-> setPos(Posx*es,-Posy*es);
}
