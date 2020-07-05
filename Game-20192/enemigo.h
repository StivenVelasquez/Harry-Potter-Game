#ifndef ENEMIGO_H
#define ENEMIGO_H
//#include <ventanajuego.h>
#include <QGraphicsPixmapItem>

class Enemigo: public QGraphicsPixmapItem
{
public:
    Enemigo(); //Constructor
    int StartX = 450;
    int StartY = 250;//
//protected:
    //void advance(int phase);
//private:
    qreal angle;
   // qreal speed;
   // void DoCollision();
    int  m_x;
     int  m_y;
};

#endif // ENEMIGO_H
