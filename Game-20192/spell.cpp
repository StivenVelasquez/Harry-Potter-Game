#include "spell.h"
#include <QTimer>
#include "jugador.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemigo.h"
#include <QtMath>
#include <typeinfo>
#include <ventanajuego.h>

extern VentanaJuego *game;

Spell::Spell()
{

    setPixmap(QPixmap(":/Imagenes/hechizo.png"));

    //Conectar el movimiento con el timer
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // después de cierto tiempo se llama a la función mover porque se envía la señal timeout ()
    timer->start(50);

    PuntajeJugadorActual=0;
}

void Spell::advance(int phase)
{


        if(!phase) return;

        QPointF location = this->pos();

        setPos(mapToParent(40,0));

}


void Spell::move()
{

    // comprueba si la bala chocó con el enemigo

    Jugador *player= new Jugador();



    QList <QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid (*(colliding_items[i]))==typeid (Enemigo))
    {

            PuntajeJugadorActual=game->score->incrementar();

            qDebug()<<"PUNTAJE"<<PuntajeJugadorActual<<endl;
            

            // eliminarlos a ambos
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);


            // eliminar del montón
            delete colliding_items[i];
            delete this;
            return;
    }
    }

    // mueve la bala
    advance(5);


    // Comprueba si el hechizo ha ido más allá del rango que vemos
    if(pos().y() + 80 < 0)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";

    }
    if(pos().y() + 80 > 800)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";

    }
    if(pos().x() + 80 > 900)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";

    }
    if(pos().x() + 80 < 0)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";

    }

}

