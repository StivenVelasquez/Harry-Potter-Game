#include "jugador2.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <modojuego.h>

extern ModoJuego *modoJuego;

Jugador2::Jugador2(QGraphicsItem *parent) //Declaracion del cosntructor de la clase
{
    setPixmap(QPixmap(":/Imagenes/dumbeldore.png"));
    contador_Enemigos=0;

}

void Jugador2::keyPressEvent(QKeyEvent *event) //Movimiento con las teclas del teclado
{
    if (event->key() == Qt::Key_A){
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
     if (event->key() == Qt::Key_D){
        if(pos().x() + 100 < 905)
        setPos(x()+10,y());
    }

     if (event->key() == Qt::Key_W){
        if(pos().y() >0)
        setPos(x(),y()-10);
     }
     if (event->key() == Qt::Key_S){
        if(pos().y()+60<510)
        setPos(x(),y()+10);
     }

     if (event->key()==Qt::Key_Space) {


         Spell *spell = new Spell();
         qDebug() << "Bullet created";
        // spell->setPos(mapToScene(5,-50));
        // spell->setRotation(rotation());
          spell->setPos(x()+60,y()+20);
         scene()->addItem(spell);
        /* if(bulletsound->state()==QMediaPlayer::PlayingState){
             bulletsound->setPosition(0);
         }else if(bulletsound->state()==QMediaPlayer::StoppedState){
             bulletsound->play();
         }
         }*/
}
}
