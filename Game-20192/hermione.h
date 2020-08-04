#ifndef HERMIONE_H
#define HERMIONE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <math.h>
#include <QTimer>

class Hermione: public QGraphicsPixmapItem, public QObject
{

public:
    Hermione(); //Constructor
    QRectF boundingRect() const;//Limites del rectangulo donde esta el personaje
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//Para pinta el pixmap
    float getposx();
    float getposy();
    float getRadio();
    float getPhi();

    void advance(int phase);
private:
    QPixmap m_P;

    float Radio;
    float Phi,pi;
    float posx,posy; //Para posiciones

};

#endif // HERMIONE_H
