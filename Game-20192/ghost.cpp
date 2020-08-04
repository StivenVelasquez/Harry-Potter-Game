#include "ghost.h"

float ghost::getPx() const
{
    return Posx;
}

void ghost::setPx(float value)
{
    Posx = value;
}

float ghost::getPy() const
{
    return Posy;
}

void ghost::setPy(float value)
{
    Posy= value;
}

ghost::ghost():QObject (),QGraphicsPixmapItem () // Herencia de QObject y de QGraphics Item
{
    //Imagen del Fantasma
     setPixmap(QPixmap(":/Imagenes/Ghost.png"));

     // connect
     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover el fantasma

     //Cada 50 milisegundos se va a mover el fantasma
     timer->start(50);

     //Inicializacion de variables
     Phi=3.1416;
     Cuerda = 20;
     Angulo = Phi/2;
     Velocidad_Angular = 0;
}

void ghost::move()
{   
    /*MOVIMIENTO PENDULAR*/
    double Aceleracion_Angular, dt = 0.15;

    Aceleracion_Angular = (-9.81 / Cuerda) * sin(Angulo);//Alteracion de la velocidad angular
    Velocidad_Angular += Aceleracion_Angular * dt;//Alteracion del desplazamiento angular en un lapso de tiempo
    Angulo += Velocidad_Angular* dt;//Angulo

    int anchorX = 800, anchorY = 300;

    float Px,Py;

    Px = anchorX + (int)(sin(Angulo) * Cuerda);
    Py= anchorY + (int)(cos(Angulo) * Cuerda);

    setPx(Px);
    setPy(Py);

    this->setPos(getPx(), getPy());
}
