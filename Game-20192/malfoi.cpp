#include "malfoi.h"
#include <QPainter>

malfoi::malfoi()
{
  m_P2.load(":/Imagenes/malfoi.png");
}

float malfoi::getpos_x()
{
    posx=getRadio()*pow(cos(getPhi()),3);
    return posx;
}

float malfoi::getpos_y()
{
    posy=getRadio()*pow(sin(getPhi()),3);
    return posy;
}

void malfoi::advance(int phase)
{
    //Hipocicloide de 4 puntas
    //http://www.salonhogar.net/Mat/Geometria/Diferencial/Curvas/Enelplano/Hipocic4.html
  getpos_x();
  getpos_y();
  setPos(posx,posy);
}

void malfoi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(300,300,80,62,m_P2);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

