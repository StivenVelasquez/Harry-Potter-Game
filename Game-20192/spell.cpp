#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QtMath>
#include <typeinfo>

#include "enemigo.h"
#include "ventanajuego.h"
#include "login.h"
#include "jugador.h"
#include "spell.h"
#include "nivel2.h"
#include "cargar_partidas.h"

extern VentanaJuego *game;
extern VentanaJuego *game_Multijugador;
extern Nivel2 *nivel;
extern Nivel2 *nivel2;
extern Cargar_Partidas *Partidas;

Spell::Spell() //Constructor
{
    setPixmap(QPixmap(":/Imagenes/hechizo.png"));//Imagen del hechizo
    //Conectar el movimiento con el timer de los hechizos de los mortifagos
    QTimer *timerMortifagos = new QTimer(); //Se crea un Timer
    connect(timerMortifagos,SIGNAL(timeout()),this,SLOT(moveHechizo()));
    // después de cierto tiempo se llama a la función mover porque se envía la señal timeout ()
    timerMortifagos->start(50);
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
            //Para colisiones con los enemigos
            //---------------------------------------------------------------------------------
                if(typeid (*(colliding_items[i]))==typeid (Enemigo)) //Si la colision se da con un enemigo
            {

                   // if(x==1){ //Para modo de jugador unitario


                    PuntajeJugadorActualNivel1=game->score->incrementar();//Se incrementa el puntaje de nivel 1
                   // }

                    //if(x==2){ //Para multijugador

                    //game_Multijugador->score->incrementar();//Se incrementa el puntaje de nivel 2
                    //}

                    // eliminarlos a Enemigo y al hechizo
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);


                    // eliminar del monton
                    delete colliding_items[i];
                    delete this;
                    return;
            }

                //Para colisiones con los mortifagos
                //-----------------------------------------------------------------------------

                if(typeid (*(colliding_items[i]))==typeid (Mortifago)) //Si la colision se da con un enemigo
            {
                   // PuntajeJugadorActual=game->score->getPuntaje();
                    if(Partidas->Para_Jugar_Nivel_1==1){
                    nivel->m_score->incrementar();//Se incrementa el puntaje
                    }
                    if(Partidas->Para_Jugar_Nivel_2==2){
                    nivel2->m_score->incrementar();//Se incrementa el puntaje
                    }
                   // nivel2->m_score->incrementar();//Se incrementa puntaje

                    // eliminarlos a Mortifago y al hechizo
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
    //Quitar vidas al jugador con las colisiones con los dementores
    QList <QGraphicsItem *>colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid (*(colliding_items[i]))==typeid (Jugador))
    {
//            if(bulletsound->state()==QMediaPlayer::PlayingState){
//                bulletsound->setPosition(0);
//            }else if(bulletsound->state()==QMediaPlayer::StoppedState){
//                bulletsound->play();
//            }
               if(Partidas->Para_Jugar_Nivel_1==1){
                 nivel->m_health->decrecer();
               }

               if(Partidas->Para_Jugar_Nivel_2==2){
                 nivel2->m_health->decrecer();
               }
             // nivel2->m_health->decrecer();
             //remove them both
          //scene()->removeItem(colliding_items[i]);
          scene()->removeItem(this);
         // scene()->removeItem();

          //delete from heap
         // delete colliding_items[i];
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
