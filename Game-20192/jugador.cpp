#include <QGraphicsScene>
//#include <QGraphicsView>
#include <QDebug>

#include "modojuego.h"
#include "ventanajuego.h"
#include "jugador.h"

Spell *spell; //Se instancia objeto de la clase Spell

extern ModoJuego *modoJuego;//Se usa clase externa
extern Ventana_Multijugador *multijugador; //Se usa clase externa

Jugador::Jugador(QGraphicsItem *parent) //Declaracion del cosntructor de la clase
{
   //Si solo es un jugador

    if(modoJuego->Jugador==1){
        setPixmap(QPixmap(":/Imagenes/Personaje.png")); //Imagen del jugador
    }

    //multijugador

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

    //Inicializacion de variables
    contador_Enemigos=0;
}

void Jugador::keyPressEvent(QKeyEvent *event) //Movimiento con las teclas del teclado
{

    if (event->key() == Qt::Key_Left){ //Para movimiento a la izquierda
        if(pos().x() > 0)//Si posición en x es mayor que cero
        setPos(x()-10,y()); //A la posicion en x se le resta 10 posiciones en cada pulsación de la tecla
    }

     if (event->key() == Qt::Key_Right){//Para mover a la derecha
        if(pos().x() + 100 < 905)//Para que la posicion no se vaya mas allá de la escena que puede verse en la pantalla
        setPos(x()+10,y());//A la posicion en x se le suman de posisiones en cada pulsación de la tecla
    }

    if (event->key() == Qt::Key_Up){ //Para mover hacia arriba
        if(pos().y() >0)//Para que la posicion no se vaya mas allá de la escena que puede verse en la pantalla
        setPos(x(),y()-10); //A la posicion en y se le restan 10 posiciones en cada pulsación de la tecla
     }

     if (event->key() == Qt::Key_Down){ //Para mover hacia abajo
        if(pos().y()+60<510)//Para que la posicion no se vaya mas allá de la escena que puede verse en la pantalla
        setPos(x(),y()+10); //A la posicion en y se le suman 10 posiciones en cada pulsación de la tecla
     }

     if (event->key()==Qt::Key_Space) { //Para generar hechizos

         spell = new Spell();
         spell->setPos(x()+60,y()+20); //Posicion del Spell en jugador
         scene()->addItem(spell);     
    }
}

void Jugador::spawn() //Para generar dementores
{
    if(modoJuego->Jugador==1){ //Si solo es un jugador

        if(contador_Enemigos<=6){ //Se van a crear máximo 6 dementores en la ventana principal

            enemy = new Enemigo();  //Se crea
            scene()->addItem(enemy);//Se agrega a la escena
            contador_Enemigos++;

        }
    }

    if(modoJuego->Jugador==2){ //Cuando juegan en modo multijugador

        if(contador_Enemigos<=15){ //Se van a crear máximo 15 dementores en la ventana principal

            enemy = new Enemigo();  //Se crea
            scene()->addItem(enemy);//Se agrega a la escena
            contador_Enemigos++;

        }
    }
}
