
#ifndef PERSONAJEDECORACION_H
#define PERSONAJEDECORACION_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Personaje1_Decoracion: public QGraphicsPixmapItem, public QObject
{

public:
    Personaje1_Decoracion(); //Constructor
    QRectF boundingRect() const;//Limites del rectangulo donde esta el personaje
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//Para pinta el pixmap
private:

    QPixmap m_P;
};

class Personaje2_Decoracion: public QGraphicsPixmapItem, public QObject
{

public:
    Personaje2_Decoracion(); //Constructor
    QRectF boundingRect() const;//Limites del rectangulo donde esta el personaje
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//Para pinta el pixmap
private:

    QPixmap m_P2;
};


#endif // PERSONAJESESCENARIO_H
