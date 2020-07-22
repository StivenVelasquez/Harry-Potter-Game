#include "hedwig.h"
#include <QGraphicsScene>

float Hedwig::getposx()
{
    return Pposx;
}

float Hedwig::getposy()
{
    return Pposy;
}

float Hedwig::getvelx()
{
    return Pvelx;
}

float Hedwig::getvely()
{
    return Pvely;
}

float Hedwig::getmasa()
{
    return Pmasa;
}


Hedwig::Hedwig(float x, float y, float vx, float vy, float m, float r, QObject *parent): QObject(parent)//Constructor de la clase
 {


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

      timer=new QTimer();
      filas=0;
      columnas=0;
      pixmap =new QPixmap(":/Imagenes/Hedwig.png");

      //Dimensiones de cada una de las imagenes
      ancho=95;
      alto=97.83333333;

      timer->start(150);//modifica la velocidad en que itera entre las imagenes

      connect(timer,&QTimer::timeout,this,&Hedwig::actualizacion);

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

float Hedwig::CalcularAcelx(Hedwig *A)//Para aceleración en 'X'
{
    float dist,ang;

    dist=sqrt( pow(A->getposx()-getposx(),2)+ pow( A->getposy()-getposy(),2));
    ang= atan2(( A->getposy()-getposy()) , A->getposx()-getposx());
    Acelx +=(((G * A->getmasa()) / pow(dist,2))*cos(ang) );

 return Acelx;

}

float Hedwig::CalcularAcely(Hedwig *A)//Para aceleracion en 'Y'
{
    float dist,ang;

    dist=sqrt( pow( A->getposx()-getposx(),2)+ pow( A->getposy()-getposy(),2));
    ang= atan2(( A->getposy()-getposy()) , A->getposx()-getposx());
    Acely += (((G * A->getmasa()) / pow(dist,2))*sin(ang));

    return Acely;
}

float Hedwig::CalcularVelx()//Para velocidad en 'X'
{
 Velx= getvelx() + (Acelx* dtt);
         return Velx;
}

float Hedwig::CalcularVely()//Para velocidad en 'Y'
{
    Vely= getvely() + (Acely* dtt);
            return Vely;

}

float Hedwig::getPosx()//Para la Posición en 'X'
{
    Posx=getposx()+(getvelx() * dtt) + ((Acelx* pow(dtt,2)/2));
     return Posx;

}

float Hedwig::getPosy()//Para la Posición en 'Y'
{
    Posy=getposy()+(getvely() * dtt) + ((Acely* pow(dtt,2)/2));
     return Posy;

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

void Hedwig::mover()
{
    setPos(Posx*es,-Posy*es);
}

