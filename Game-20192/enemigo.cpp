#include "enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "ventanajuego.h"

Enemigo::Enemigo()
{
    //Imagenl
    setPixmap(QPixmap(":/Imagenes/dementor.png"));
   //random start rotation

    m_x=StartX;
    m_y=StartY;

    //setPos(mapToParent(StartX,StartY));

    angle=(qrand()%360);
    setRotation(angle);

    //random star position
    if((qrand()%1)){
        StartX=(qrand()%200);
        StartY=(qrand()%200);
    }

    else
    {
        StartX=(qrand()%-100);
        StartY=(qrand()%-100);
    }

    setPos(mapToParent(StartX,StartY));

    //set the speed
   // speed=5;

}


/*void Enemigo::advance(int phase)
{
  if(!phase) return;

       QPointF location=this->pos();
   // setPos(mapToParent(0,-(speed)));
//if(personaje->collidesWithItem(tortuga.at(i))){
    // if(Enemigo->collidesWithItem(tortuga)){
    if(!(scene()->collidingItems(this).isEmpty()))
    {
    DoCollision();
    }

       setPos(mapToParent(0,-(speed)));
}*/

/*void Enemigo::DoCollision()
{
    //set a new position
    //Cambiar anglecon a little randomness

    if(((qrand()%1))){
       setRotation(rotation()+180+(qrand()%10));
}
    else
    {
        setRotation(rotation()+180+(qrand()%-10));

    }

    //see if the new position is in bounds

    //QPointF newpoint=mapToParent(-(boundingRect().width()), -(boundingRect().width()+2));
    QPointF newpoint=mapToParent(-150, -133+2);

    if(!scene()->sceneRect().contains((newpoint))){
        //move it back in bounds
        newpoint=mapToParent(0,0);
    }

    else
    {
        //set the new position
        setPos(newpoint);
    }
}*/

