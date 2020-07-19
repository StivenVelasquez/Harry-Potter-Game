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

Spell::Spell() //Constructor
{

    setPixmap(QPixmap(":/Imagenes/hechizo.png"));//Imagen del hechizo

    //Conectar el movimiento con el timer de los hechizos de los mortifagos
    QTimer *timerMortifagos = new QTimer(); //Se crea un Timer
    connect(timerMortifagos,SIGNAL(timeout()),this,SLOT(moveHechizo()));
    // después de cierto tiempo se llama a la función mover porque se envía la señal timeout ()
    timerMortifagos->start(50);

    PuntajeJugadorActual=0; //Se inicializa el puntaje del jugador

}

void Spell::advance(int phase)
{

        if(!phase) return;

        QPointF location = this->pos(); //Dice la posicion en que se encuentra el hechizo

        setPos(mapToParent(40,0));//Para su avance
    }


void Spell::moveHechizo()
{

            // comprueba si la bala chocó con el enemigo

            Jugador *player= new Jugador(); //Se crea un nuevo jugador

            QList <QGraphicsItem *>colliding_items = collidingItems();
            for(int i=0,n=colliding_items.size();i<n;i++)
            {
                if(typeid (*(colliding_items[i]))==typeid (Enemigo)) //Si la colision se da con un enemigo
            {

                    PuntajeJugadorActual=game->score->incrementar();//Se incrementa el puntaje

                    // eliminarlos a Enemigo y al hechizo
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);


                    // eliminar del monton
                    delete colliding_items[i];
                    delete this;
                    return;
            }
            }

            // mueve la bala
            advance(5);

            // Comprueba si el hechizo ha ido más allá del rango que vemos

            if(pos().x() + 80 > 900)

            {
                scene()->removeItem(this);
                delete this;
                qDebug() << "Bullet deleted";

            }
 }

SpellMortifago::SpellMortifago()
{
      setPixmap(QPixmap(":/Imagenes/hechizoMortifa.png"));//Imagen del hechizo

        //Conectar el movimiento con el timer de los hechizos del jugador
        QTimer *timer = new QTimer(); //Se crea un Timer
        connect(timer,SIGNAL(timeout()),this,SLOT(moveHechizo()));
        // después de cierto tiempo se llama a la función mover porque se envía la señal timeout ()
        timer->start(50);
}

void SpellMortifago::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(-40,0));
}

void SpellMortifago::moveHechizo()
{

    QList <QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid (*(colliding_items[i]))==typeid (Jugador)) //Si la colision se da con un mortifago
    {
           // PuntajeJugadorActual=game->score->incrementar();//Se incrementa el puntaje

            // eliminarlos a Enemigo y al hechizo
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // eliminar del monton
            delete colliding_items[i];
            delete this;
            return;
    }
    }
    // mueve la bala
    advance(5);

    if(pos().x() + 80 < 0)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted";

    }
}
