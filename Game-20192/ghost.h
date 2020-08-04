#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>
#include <QTimer>

class ghost:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT

public: 
    ghost();//Constructor
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
private:
    /*Posiciones*/
   float Posx;
   float Posy;
   /*Largo de la cuerda*/
   unsigned int Cuerda;
   double  	 Angulo;
   double    Velocidad_Angular;
   float Phi;

public slots:
   void move();//Para mover el fantasma
};

#endif // GHOST_H
