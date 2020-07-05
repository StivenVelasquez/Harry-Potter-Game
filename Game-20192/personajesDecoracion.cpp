#include "personajesDecoracion.h"
#include <QPainter>
#include <cmath>

//Hermione
Personaje1_Decoracion::Personaje1_Decoracion(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    m_P.load(":/Imagenes/hermione.png");
}

QRectF Personaje1_Decoracion::boundingRect() const
{
    return QRectF(300, 300, 120, 80);    //rectángulo que demarca los límites del item gráfico
}

void Personaje1_Decoracion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(300,300,120,80,m_P);
}

//Draco
Personaje2_Decoracion::Personaje2_Decoracion(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{

    m_P2.load(":/Imagenes/malfoi.png");
}


QRectF Personaje2_Decoracion::boundingRect() const
{
    return QRectF(300, 300, 80, 62); //rectángulo que demarca los límites del item gráfico
}


void Personaje2_Decoracion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(300,300,80,62,m_P2);
}



