#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <typeinfo>

#include "ventanajuego.h"
#include "enemigo.h"
#include "ventana_multijugador.h"
#include "modojuego.h"

extern VentanaJuego *game; //Se usa una clase externa
extern VentanaJuego *game_Multijugador1;//Se usa clase externa
extern VentanaJuego *game_Multijugador2;//Se usa clase externa
extern Ventana_Multijugador *multijugador; //Se usa clase externa
extern ModoJuego *modoJuego;

Enemigo::Enemigo():QObject (),QGraphicsPixmapItem () // Herencia de QObject y de QGraphics Item
{
    //Posiciones aleatorias del enemigo en la pantalla

    int numero_aleatorio = (rand() % 887)+110; //Para que salgan de diferentes partes de la parte superior de la pantalla

    setPos(numero_aleatorio,0); //Posicion de los dementores en la pantalla

    // Se dibuja el enemigo
    setPixmap(QPixmap(":/Imagenes/dementor.png"));
    setRotation(180); //Se rota este angulo

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover los dementores

    //Cada 50 milisegundos se van a move los dementores
    timer->start(50);
}

void Enemigo::move()
{

    //Quitar vidas al jugador con las colisiones con los dementores
    QList <QGraphicsItem *>colliding_items = collidingItems(); //Lista de Items que colisionan
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid (*(colliding_items[i]))==typeid (Jugador))//Si el enemigo colisiona con una clase tipo jugador
    {
//            if(bulletsound->state()==QMediaPlayer::PlayingState){
//                bulletsound->setPosition(0);
//            }else if(bulletsound->state()==QMediaPlayer::StoppedState){
//                bulletsound->play();
//            }
            if(modoJuego->Jugador==1){ //Para modo de jugador unitario

                game->health->decrecer(); //Se decrece vida en la ventana de juego
            }

            //Para Multijugador

            if(modoJuego->Jugador==2){
            //Primer jugador de multijugador
          if(multijugador->Jugar==1){
               game_Multijugador1->health->decrecer();
          }
          //Segundo jugador del multijugador
             if(multijugador->Jugar==2){
                 game_Multijugador2->health->decrecer();
            }
            }

//            if(multijugador->Multijugador==1){
//                game_Multijugador1->health->decrecer();
//            }

//            if(multijugador->Multijugador==2){
//                game_Multijugador1->health->decrecer();
//            }
            // game_Multijugador->health->decrecer();// Para decrecer  en el multijugador


             //remove them both
          //scene()->removeItem(colliding_items[i]);
          scene()->removeItem(this); //Se remueve el enemigo con el que colisiono el jugador

          //delete from heap
         // delete colliding_items[i];
          delete this; //Se elimina de la memoria
          return;
    }
    }

    // Se mueve el enemigo hacia abajo
     advance2(5);

     //Para restitución con las paredes de la pantalla
    if(pos().y() +118 > 600)//Parte inferior
    {

        DoCollision();
    }

    if(pos().y()+118 < 90)//Parte superior
    {

        DoCollision();
    }

   if(pos().x()+110 > 980)//Parte derecha
    {

        DoCollision();
    }

     if(pos().x()+110 < 70)//Parte izquierda
    {

        DoCollision();
    }

}


void Enemigo::advance2(int phase) //Para avanzar dementores
{
    if(!phase) return;

       QPointF location = this->pos();

       setPos(mapToParent(0,-(5))); //Para la posicion de los dementores
}


void Enemigo::DoCollision()
{
    //Obtener una nueva posición

     //Cambiar el angulo de movimiento con un poco de aletoriedad
     if(((qrand() %1)))
     {
         setRotation(rotation() + (180 + (qrand() % 10)));
     }
     else
     {
         setRotation(rotation() + (180 + (qrand() % -10)));
     }

     //Ver si la nueva posicion esta dentro de los limites
     QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

     if(!scene()->sceneRect().contains((newpoint)))
     {
         // Se mueve en los limites
         newpoint = mapToParent(0,0);
     }
     else
     {
         //Se establece la nueva posicion
         setPos(newpoint);

     }

}

