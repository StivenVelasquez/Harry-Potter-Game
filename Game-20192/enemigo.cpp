#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <typeinfo>

#include "ventanajuego.h"
#include "enemigo.h"
#include "ventana_multijugador.h"
#include "modojuego.h"
#include "game_over.h"

Game_Over *perderGame;

extern VentanaJuego *game; //Se usa una clase externa
extern VentanaJuego *game_Multijugador1;//Se usa clase externa
extern VentanaJuego *game_Multijugador2;//Se usa clase externa
extern Ventana_Multijugador *multijugador; //Se usa clase externa
extern ModoJuego *modoJuego;//Se usa clase externa

Enemigo::Enemigo():QObject (),QGraphicsPixmapItem () // Herencia de QObject y de QGraphics Item
{

    int Dementores = rand()%4;
    //Posiciones aleatorias del enemigo en la pantalla

    if(Dementores==1){

        int numero_aleatorio = (rand() % 887)+110; //Para que salgan de diferentes partes de la parte superior de la pantalla

        setPos(numero_aleatorio,0); //Posicion de los dementores en la pantalla

        // Se dibuja el enemigo
        setPixmap(QPixmap(":/Imagenes/dementor.png"));
        setRotation(180); //Se rota este angulo para que salga mirando para que la cabeza del dementor quede mirando a la parte inferior de la pantalla

        // connect
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover los dementores

        //Cada 50 milisegundos se van a move los dementores
        timer->start(25);

    }

    if(Dementores==2){

        int numero_aleatorio = (rand() % 610); //Para que salgan de diferentes partes de la parte inferior de la pantalla

        setPos(numero_aleatorio,510); //Posicion de los dementores en la pantalla

        // Se dibuja el enemigo
        setPixmap(QPixmap(":/Imagenes/dementor.png"));
        setRotation(180); //Se rota este angulo para que salga mirando para que la cabeza del dementor quede mirando a la parte inferior de la pantalla

        // connect
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover los dementores

        //Cada 50 milisegundos se van a move los dementores
        timer->start(25);

    }

    if(Dementores==3){

        int numero_aleatorio = (rand() % 810); //Para que salgan de diferentes partes de la parte derecha de la pantalla

        setPos(700,numero_aleatorio); //Posicion de los dementores en la pantalla

        // Se dibuja el enemigo
        setPixmap(QPixmap(":/Imagenes/dementor.png"));
        setRotation(-90); //Se rota este angulo para que salga mirando para que la cabeza del dementor quede mirando a la parte izquierda de la pantalla

        // connect
        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));//Para mover los dementores

        //Cada 50 milisegundos se van a move los dementores
        timer->start(25);
    }
}

void Enemigo::move()
{
    //Quitar vidas al jugador con las colisiones con los dementores
    QList <QGraphicsItem *>colliding_items = collidingItems(); //Lista de Items que colisionan con el enemigo

    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid (*(colliding_items[i]))==typeid (Jugador))//Si el enemigo colisiona con una clase tipo jugador
        {

            /*Musica de choque*/
            QMediaPlayer * Choquesound=new QMediaPlayer();
             Choquesound->setMedia(QUrl("qrc:/Musica/harry-potter_Choque  Dementores.mp3"));
             Choquesound->setVolume(20); //Volumen

             if(Choquesound->state()==QMediaPlayer::PlayingState){
                 Choquesound->setPosition(0);
             }

             else if(Choquesound->state()==QMediaPlayer::StoppedState){
                 Choquesound->play();
             }

             /*MODO DE JUGADOR UNITARIO*/
            if(modoJuego->Jugador==1){

                game->health->decrecer(); //Se decrece vida en la ventana de juego

                /*SI LA VIDA ES IGUAL A CERO*/
                if(game->health->getVidas_Jugador()==0){

                    game->close();
                    /*SE CREA LA VENTANA DE FIN DE JUEGO*/
                    perderGame=new Game_Over();
                    perderGame->show();
               }
            }

            /*MODO MULTIJUGADOR*/
            if(modoJuego->Jugador==2){

            //Primer jugador de multijugador
               if(multijugador->Jugar==1){
                   if(game_Multijugador1->health->getVidas_Jugador()>0){
                         game_Multijugador1->health->decrecer();//Se decrecen las vidas
                   }

               }

            //Segundo jugador del multijugador
               if(multijugador->Jugar==2){
                  if(game_Multijugador2->health->getVidas_Jugador()>0){
                     game_Multijugador2->health->decrecer();//Se decrecen la vidas
                  }
               }
            }

          scene()->removeItem(this); //Se remueve el enemigo con el que colisiono el jugador

          delete this; //Se elimina de la memoria
          return;
        }
    }

    // actualizar movimiento de dementores
     actualizar();

    //Para choques con las paredes de la pantalla
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
  setPos(mapToScene(0,-(5))); //Se busca la posicion actual del enemigo y dependiendo donde se encuentre se le resta a la posicion en 'y', la posicion en 'x' no se ve afectada.
}

void Enemigo::DoCollision()
{
     //Cambiar el angulo de movimiento con un poco de aletoriedad
     if(((qrand() %2)))
     {
         setRotation(rotation() + (180) + (qrand() % 10));
     }

     else
     {
         setRotation(rotation() + (180)+ (qrand() % -10));
     }

     /*PARA CAMBIAR EL SENTIDO DEL DEMENTOR*/

     //Obtener una nueva posición
     QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().height())); //A las posiciones se les cambia el sentido

     //Se establece la nueva posicion
     setPos(newpoint);
}
