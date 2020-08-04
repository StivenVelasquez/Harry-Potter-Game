#include "hermione.h"
#include <QPainter>

float Hermione::getposx()
{
    posx=getRadio()*cos(getPhi()*2);
    return posx;
}

float Hermione::getposy()
{
    posy=getRadio()*sin(getPhi()*2);
    return posy;
}

float Hermione::getRadio()
{
    Radio=100;
    return Radio;
}


float Hermione::getPhi()
{
   Phi+=0.01745329252;//Cuando llegue a pi habra dado una vuelta circular completa
    return Phi;
}

//Hermione
Hermione::Hermione()
{
    m_P.load(":/Imagenes/hermione.png");
    Phi=0;
}

QRectF Hermione::boundingRect() const
{
    return QRectF(300, 300, 120, 80);    //rectángulo que demarca los límites del item gráfico
}

void Hermione::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(300,300,120,80,m_P);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Hermione::advance(int phase)

{
    //Movimiento circular

    getposx();
    getposy();
    setPos(posx,posy);//Cambia la posición de Hermione con 'x' y 'y'

}


