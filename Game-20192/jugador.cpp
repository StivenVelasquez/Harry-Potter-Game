#include <QGraphicsScene>
#include <QDebug>

#include "modojuego.h"
#include "ventanajuego.h"
#include "jugador.h"

Spell *spell; //Se instancia objeto de la clase Spell

extern ModoJuego *modoJuego;//Se usa clase externa
extern Ventana_Multijugador *multijugador; //Se usa clase externa

Jugador::Jugador() //Declaracion del cosntructor de la clase
{
   /*SI SOLO ES UN JUGADOR*/

    /*------------------------------------------------------------------------*/
    if(modoJuego->Jugador==1){
        setPixmap(QPixmap(":/Imagenes/Personaje.png")); //Imagen del jugador
    }

    /*------------------------------------------------------------------------*/

    /*MODO MULTIJUGADOR*/

    /*------------------------------------------------------------------------*/
    if(modoJuego->Jugador==2){
    //Primer jugador de multijugador
      if(multijugador->Jugar==1){
          setPixmap(QPixmap(":/Imagenes/Personaje.png")); //Imagen del jugador
      }

      //Segundo jugador del multijugador
      if(multijugador->Jugar==2){
        setPixmap(QPixmap(":/Imagenes/Ron.png")); //Imagen del jugador
      }
    }
    /*------------------------------------------------------------------------*/

    //Inicializacion de variables
    contador_Enemigos=0;
}

void Jugador::keyPressEvent(QKeyEvent *event) //Movimiento con las teclas del teclado
{

    if (event->key() == Qt::Key_Left){ //Para movimiento a la izquierda
        if(pos().x() > 0)//Si posición en x es mayor que cero
        setPos(x()-10,y()); //Se le restan 10 posiciones a la posición en 'x'
    }

     if (event->key() == Qt::Key_Right){//Para mover a la derecha
        if(pos().x() + 100 < 905)//Para que la posicion no se vaya mas allá de la escena que puede verse en la pantalla
        setPos(x()+10,y());//Se le suman 10 posiciones a la posición en 'x'
    }

    if (event->key() == Qt::Key_Up){ //Para mover hacia arriba
        if(pos().y() >0)//Para que la posicion no se vaya mas allá de la escena que puede verse en la pantalla
        setPos(x(),y()-10); //Se le restan 10 posiciones a la posición en 'y'
     }

     if (event->key() == Qt::Key_Down){ //Para mover hacia abajo
        if(pos().y()+60<510)//Para que la posicion no se vaya mas allá de la escena que puede verse en la pantalla
        setPos(x(),y()+10); //Se le suman 10 posiciones a la posición en 'y'
     }

     if (event->key()==Qt::Key_Space) { //Para generar hechizos

         spell = new Spell();
         spell->setPos(x()+60,y()+20); //Posicion del Spell en jugador
         scene()->addItem(spell);//Se añade el spell a la escena
    }
}

void Jugador::spawn() //Para generar dementores
{
    if(modoJuego->Jugador==1){ //Si solo es un jugador

        if(contador_Enemigos<=30){ //Se van a crear máximo 6 dementores en la ventana principal

            enemy = new Enemigo();  //Se crea
            scene()->addItem(enemy);//Se agrega a la escena
            contador_Enemigos++;

        }
    }

    if(modoJuego->Jugador==2){ //Cuando juegan en modo multijugador

        if(contador_Enemigos<=30){ //Se van a crear máximo 15 dementores en la ventana principal

            enemy = new Enemigo();  //Se crea
            scene()->addItem(enemy);//Se agrega a la escena
            contador_Enemigos++;

        }
    }
}
