#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsPixmapItem>
#include <math.h>

#include "jugador.h"
#include "enemigo.h"
#include "personajesDecoracion.h"

#include <QDebug>
#include <QList>
#include <stdlib.h>
#include <QPointF>

namespace Ui {
class VentanaJuego;
}

class VentanaJuego : public QMainWindow{
    Q_OBJECT

public:
    explicit VentanaJuego(QWidget *parent = nullptr);//constructor
    ~VentanaJuego();//destructor
    void colliding();//metodo colisión entre personajes de decoración.

    //void PosicionEnemigos();//Funcion para posicion de enemigos

    //Posiciones iniciales de los enemigos
    int StartX = 450;
    int StartY = 250;

private:
    Ui::VentanaJuego*ui;
    QGraphicsScene *scene;//Para crear la escena

    //Para el jugador principal
    Jugador *personaje;

    //Enemigo
    Enemigo *Enemy;

    //Timers
    QTimer *timer;//Para los enemigos
    QTimer *time;//Crea el tiempo para los personajes Decoración Escenario


    Personaje1_Decoracion *Hermione;//Crea 1 personaje de decoración del escenario
    Personaje2_Decoracion *Malfoi;//crea 2 personaje de decoración del escenario


    //Variables para personajes de decoración del escenario
    float rad;//Ángulo(radianes)
    float x,y,i; //Para posiciones
    float x_,y_;
    bool collide;//Variable que me dice si colisiona

    //Para posicion de los enemigos
    qreal angle;
    qreal speed;
    void DoCollision();
    int  m_x;
    int  m_y;

//protected:
    //void advan(int phase);

public slots:
    void posicionPersonajeEscenario();
    void posicionInvPersonajeEscenario();
    //void PosicionEnemigos();//Funcion para posicion de enemigo
    void avanzar();

signals:
    void cambiarDireccion();

};

#endif // VENTANAJUEGO_H
