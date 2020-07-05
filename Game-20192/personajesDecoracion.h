#ifndef PERSONAJEDECORACION_H
#define PERSONAJEDECORACION_H

#include <QGraphicsPixmapItem>
#include <QObject>


class Personaje1_Decoracion: public QGraphicsPixmapItem, public QObject
{

public:
    Personaje1_Decoracion(QGraphicsItem * parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:

    QPixmap m_P;
};

class Personaje2_Decoracion: public QGraphicsPixmapItem, public QObject
{

public:
    Personaje2_Decoracion(QGraphicsItem * parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:

    QPixmap m_P,m_P2;
};

#endif // PERSONAJESESCENARIO_H
