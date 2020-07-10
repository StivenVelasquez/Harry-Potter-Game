#include "jugador.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

//int contador_Enemigos=0;

Jugador::Jugador(QGraphicsItem *parent) //Declaracion del cosntructor de la clase
{
    setPixmap(QPixmap(":/Imagenes/Personaje.png"));
    contador_Enemigos=0;

}

void Jugador::keyPressEvent(QKeyEvent *event) //Movimiento con las teclas del teclado
{
    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
     if (event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 905)
        setPos(x()+10,y());
    }

     if (event->key() == Qt::Key_Up){
        if(pos().y() >0)
        setPos(x(),y()-10);
     }
     if (event->key() == Qt::Key_Down){
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

void Jugador::spawn()
{

    if(contador_Enemigos<=6){

    enemy = new Enemigo();
    scene()->addItem(enemy);

    qDebug()<<contador_Enemigos<<endl;

    contador_Enemigos++;

    }

}

