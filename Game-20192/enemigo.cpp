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
    setRotation(180); //Se rota este angulo para que salga mirando para que la cabeza del dementor quede mirando a la parte inferior de la pantalla

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

              scene()->removeItem(this); //Se remueve el enemigo con el que colisiono el jugador

              delete this; //Se elimina de la memoria
              return;
        }
    }

    // actualizar movimiento de dementores
     actualizar();

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

void Enemigo::actualizar() //Para actualizar posición de dementores
{
  setPos(mapToParent(0,-(5))); //Se busca la posicion actual del enemigo y dependiendo donde se encuentre se le resta a la posicion en 'y', la posicion en 'x' no se ve afectada.
}

void Enemigo::DoCollision()
{
     //Cambiar el angulo de movimiento con un poco de aletoriedad
     if(((qrand() %1)))
     {
         setRotation(rotation() + (180) + (qrand() % 10));
     }

     else
     {
         setRotation(rotation() + (180)+ (qrand() % -10));
     }

     //Obtener una nueva posición
     QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().height())); //A las posiciones se les cambia el sentido

     //Se establece la nueva posicion
     setPos(newpoint);
}

