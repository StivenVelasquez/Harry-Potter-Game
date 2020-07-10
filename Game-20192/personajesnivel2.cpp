#include "personajesnivel2.h"
#include <QPainter>

PersonajesNivel2::PersonajesNivel2(const QString &filename, int x, int y, int vx, int vy, QGraphicsItem *parent): QGraphicsItem(parent)//Constructor de la clase
{
    mPixmap=QPixmap(filename); //se recibe nombre de archivo
    mX=x;
    mY=y;
    mVy=vx;
    mVx=vy;
}

QRectF PersonajesNivel2::boundingRect() const
{
    return mPixmap.rect();
}

void PersonajesNivel2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(mX,mY, mPixmap);
    (void) option;
    (void) widget;
}


