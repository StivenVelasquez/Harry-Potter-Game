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

