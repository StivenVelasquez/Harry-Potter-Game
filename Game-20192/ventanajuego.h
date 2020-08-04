#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMainWindow>
#include <iostream>

#include "jugador.h"
#include "enemigo.h"
#include "puntuacion.h"
#include "spell.h"
#include "login.h"
#include "vidas_jugador.h"
#include "snitch_dorada.h"
#include "ghost.h"
#include "hermione.h"
#include "malfoi.h"

using namespace std;

namespace Ui {
class VentanaJuego;
}

class VentanaJuego : public QMainWindow{
    Q_OBJECT

public:
    explicit VentanaJuego(QWidget *parent = nullptr);//constructor
    ~VentanaJuego();//destructor

    void Pasar_Nivel2();

     Puntuacion *score; //Se instancia la clase Puntuacion
     Vidas_Jugador *health; //Se instancia la clase Vidas_jugador

     //-----------------------------------------------------------------

     int contador = 0; //Para el cronometro que aparece en la pantalla
     int Contador_Multijugador; //Para contar los dos jugadores en multijugador

private:
    Ui::VentanaJuego*ui;
    QGraphicsScene *scene;//Para crear la escena

    //-------------------------------------------------------------------

    //Snicth Dorada
    Snitch_Dorada *snich; //Se instancia un objeto tipo Snitch_Dorada

    //-------------------------------------------------------------------

    //Ghost
    ghost *fantasma;

    string Nombre_Jugador;

    //-------------------------------------------------------------------

    //Para el jugador principal
    Jugador *personaje;

    //Timers
    QTimer *time;//Crea el tiempo para los personajes Decoración Escenario
    QTimer *timer;//Crea el tiempo para los enemigos
    QTimer *cronometro;

    //-------------------------------------------------------------------
    //Hermione y Malfoi

    Hermione *Amiga;
    malfoi *Amigo;

    //--------------------------------------------------------------------

public slots:
    void funcionActivacionTimer(); // Para el cronometro que aparece en la pantalla

private slots:
    void on_pushButton_2_clicked();//nivel 2
    void on_pushButton_clicked();//Guardar partidas
};

#endif // VENTANAJUEGO_H
