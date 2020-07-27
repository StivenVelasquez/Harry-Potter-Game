#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>
#include <QTimer>

class ghost:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT

public: 
    ghost();    
private:
   float Posx;
   float Posy;
   unsigned int m_Length;
   double  	 m_Angle;
   double    m_AngleVelocity;
   float Phi;

public slots:
   void move();
};

#endif // GHOST_H
