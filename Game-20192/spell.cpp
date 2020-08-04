#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QtMath>
#include <typeinfo>
#include <QMediaPlayer>

#include "enemigo.h"
#include "ventanajuego.h"
#include "login.h"
#include "jugador.h"
#include "spell.h"
#include "nivel2.h"
#include "cargar_partidas.h"
#include "ventana_multijugador.h"
#include "modojuego.h"
#include "you_win.h"
#include "game_over.h"

/*Clases externas*/
extern VentanaJuego *game;
extern VentanaJuego *game_Multijugador1;
extern VentanaJuego *game_Multijugador2;
extern Nivel2 *nivel;
extern Nivel2 *nivel2;
extern Cargar_Partidas *Partidas;
extern Ventana_Multijugador *multijugador; //Se usa clase externa
extern ModoJuego *modoJuego; //Se usa clase externa

//Instancia de clases
You_Win *ganar;
Game_Over *perder;

Spell::Spell() //Constructor
{
    setPixmap(QPixmap(":/Imagenes/hechizo.png"));//Imagen del hechizo

    //Conectar el movimiento con el timer de los hechizos de los mortifagos
    QTimer *timerMortifagos = new QTimer(); //Se crea un Timer
    connect(timerMortifagos,SIGNAL(timeout()),this,SLOT(moveHechizo()));
    // después de cierto tiempo se llama a la función mover porque se envía la señal timeout ()
    timerMortifagos->start(50);
 }

void Spell::actualizar()
{
  setPos(mapToScene(40,0));//Para actualizar posicion de los hechizos
}

void Spell::moveHechizo()
{
    // comprueba si la bala chocó con el enemigo

    QList <QGraphicsItem *>colliding_items = collidingItems(); //Lista de items de colision del spell
    for(int i=0,n=colliding_items.size();i<n;i++) //Menor al numero de items para colisionar
    {
        //Para colisiones con los enemigos
        //---------------------------------------------------------------------------------
            if(typeid (*(colliding_items[i]))==typeid (Enemigo)) //Si la colision se da con un enemigo
        {

                /*MUSICA DE SPELL*/
                 QMediaPlayer * Spellsound=new QMediaPlayer();
                  Spellsound->setMedia(QUrl("qrc:/Musica/harry_potter_Spell.mp3"));
                  Spellsound->setVolume(20); //Volumen

                  if(Spellsound->state()==QMediaPlayer::PlayingState){
                      Spellsound->setPosition(0);
                  }else if(Spellsound->state()==QMediaPlayer::StoppedState){
                      Spellsound->play();
                  }

                  /*PARA MODO EN JUGADOR UNITARIO*/
                if(modoJuego->Jugador==1){ //Para modo de jugador unitario

                   game->score->incrementar();//Se incrementa el puntaje de nivel 1

                   /*PARA CREAR NIVEL 2*/
                   if(game->health->getVidas_Jugador()>0){//Para crear nivel 2
                        if(game->score->getPuntaje()==10){
                           game->close();
                           nivel= new Nivel2();
                           nivel->show();

                         }
                    }
                }

                /*PARA MULTIJUGADOR*/

                if(modoJuego->Jugador==2){
                //Primer jugador de multijugador

                  if(multijugador->Jugar==1){
                      if(game_Multijugador1->health->getVidas_Jugador()>=0){
                         game_Multijugador1->score->incrementar(); //Se incrementa el puntaje
                      }
                  }


                  //Segundo jugador del multijugador
                  if(multijugador->Jugar==2){
                      if(game_Multijugador2->health->getVidas_Jugador()>=0){
                       game_Multijugador2->score->incrementar();//Se incrementa el puntaje
                      }
                  }
                }

                // eliminarlos a Enemigo y al hechizo
                scene()->removeItem(colliding_items[i]);//Enemigo
                scene()->removeItem(this);//Spell


                // eliminar de la memoria
                delete colliding_items[i];//Enemigo
                delete this;//Spell
                return;
        }

            //Para colisiones con los mortifagos
            //-----------------------------------------------------------------------------

            if(typeid (*(colliding_items[i]))==typeid (Mortifago)) //Si la colision se da con un enemigo
        {
                /*MUSICA DE SPELL*/
                QMediaPlayer * Spellsound=new QMediaPlayer();
                 Spellsound->setMedia(QUrl("qrc:/Musica/harry_potter_Spell.mp3"));
                 Spellsound->setVolume(20); //Volumen

                 if(Spellsound->state()==QMediaPlayer::PlayingState){
                     Spellsound->setPosition(0);
                 }else if(Spellsound->state()==QMediaPlayer::StoppedState){
                     Spellsound->play();
                 }


                /*PARA PARTIDAS EN MODO JUGADOR UNITARIO*/
                 // if(modoJuego->Jugador==1){
                 if(Partidas->Para_Jugar_Nivel_1==1 ){
                     nivel->m_score->incrementar();//Se incrementa el puntaje

                     if(nivel->m_health->getVidas_Jugador()>0){//Para el fin del juego

                         if(nivel->m_score->getPuntaje()==20){ //para crear fin del juego
                             nivel->close();

                             //Si gana
                             ganar=new You_Win();
                             ganar->show();

                          }
                    }
                 }
                 if(Partidas->Para_Jugar_Nivel_1==2 ){
                     nivel->m_score->incrementar();//Se incrementa el puntaje

                     if(nivel->m_health->getVidas_Jugador()>0){//Para el fin del juego

                         if(nivel->m_score->getPuntaje()==20){ //para crear fin del juego
                             nivel->close();

                             //Si gana
                             ganar=new You_Win();
                             ganar->show();

                          }
                    }
                 }

                   /*PARA PARTIDAS QUE SE ABREN EN NIVEL 2*/
                     if(Partidas->Para_Jugar_Nivel_2==2){
                          nivel2->m_score->incrementar();//Se incrementa el puntaje
                     }

                // eliminarlos a Mortifago y al hechizo
                scene()->removeItem(colliding_items[i]);//Mortifago
                scene()->removeItem(this);//Spell

                // eliminar de la memoria
                delete colliding_items[i];//Mortifago
                delete this;//Spell
                return;
        }

    }

    // Se actualizan las posiciones
    actualizar();

    // Comprueba si el hechizo ha ido más allá del rango que vemos

    if(pos().x() + 80 > 900)
    {
        scene()->removeItem(this); //Se remueve de la escena
        delete this; //Se remueve de la memoria
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

void SpellMortifago::actualizar()
{
  setPos(mapToScene(-40,0)); //Se actualiza la posicion de los spells
}

void SpellMortifago::moveHechizo()
{
    //Quitar vidas al jugador con las colisiones con Spell de los mortifagos
    QList <QGraphicsItem *>colliding_items = collidingItems(); //Lista de items con los que colisiona el Spell
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid (*(colliding_items[i]))==typeid (Jugador)) //Si el Spell le da al jugador
        {

            /*MUSICA DE SPELL*/
             QMediaPlayer * Spellsound=new QMediaPlayer();
              Spellsound->setMedia(QUrl("qrc:/Musica/harry_potter_Spell.mp3"));
              Spellsound->setVolume(20); //Volumen

              if(Spellsound->state()==QMediaPlayer::PlayingState){
                  Spellsound->setPosition(0);
              }else if(Spellsound->state()==QMediaPlayer::StoppedState){
                  Spellsound->play();
              }

              if(Partidas->Para_Jugar_Nivel_1==1){//Cuando se esta jugando en una partida iniciada desde cero

                 nivel->m_health->decrecer();

                 if(nivel->m_health->getVidas_Jugador()==0){

                     //Si Pierde

                     nivel->close();

                     /*SE CREA VENTANA DE FIN DE JUEGO*/
                     perder=new Game_Over();
                     perder->show();
                 }
                 }

                 if(Partidas->Para_Jugar_Nivel_2==2){//Cuando se carga partida
                    nivel2->m_health->decrecer();//Se decrece la vida

                    if(nivel2->m_health->getVidas_Jugador()==0){//Si las vidas son iguales a cero

                        //Si Pierde
                        nivel2->close();

                        /*PARA CREAR VENTANA DE FIN DE JUEGO*/
                        perder=new Game_Over();
                        perder->show();
                    }


               }

              scene()->removeItem(this); //Se remueve de la escena
              delete this;//Se remueve de la memoria
              return;
         }
      }

      // actualizar posiciones
      actualizar();

        //Si se sale de la escena
        if(pos().x() + 80 < 0)
        {
            scene()->removeItem(this); //Se remueve de la escena
            delete this;//Se remueve de la memoria
        }
}
