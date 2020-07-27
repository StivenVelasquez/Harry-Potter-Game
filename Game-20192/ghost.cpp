#include "ghost.h"

ghost::ghost():QObject (),QGraphicsPixmapItem () // Herencia de QObject y de QGraphics Item
{
     setPixmap(QPixmap(":/Imagenes/Ghost.png"));

     // connect
     QTimer * timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover la Snitch

     //Cada 50 milisegundos se va a mover la Snitch
     timer->start(50);

     Phi=3.1416;
     m_Length = 20;
     m_Angle    = Phi/2.;
     m_AngleVelocity = 0;
}

void ghost::move()
{

    //this->setPos(Posx, Posy);

    double angleAccel, dt = 0.15;

    angleAccel = (-9.81 / m_Length) * sin(m_Angle);
    m_AngleVelocity += angleAccel * dt;
    m_Angle += m_AngleVelocity * dt;

    int anchorX = 800, anchorY = 300;
     // int ballX = anchorX + (int)(sin(m_Angle) * m_Length);
     // int ballY = anchorY + (int)(cos(m_Angle) * m_Length);

     Posx = anchorX + (int)(sin(m_Angle) * m_Length);
     Posy= anchorY + (int)(cos(m_Angle) * m_Length);

      this->setPos(Posx, Posy);
}
