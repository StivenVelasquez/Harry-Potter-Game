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
#include <QTransform>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include <QPointF>

#include "jugador.h"
#include "enemigo.h"
#include "personajesDecoracion.h"
#include "puntuacion.h"
#include "spell.h"
#include "login.h"
#include "vidas_jugador.h"
#include "snitch_dorada.h"


#define dt 0.02

namespace Ui {
class VentanaJuego;
}

class VentanaJuego : public QMainWindow{
    Q_OBJECT

public:
    explicit VentanaJuego(QWidget *parent = nullptr);//constructor
    ~VentanaJuego();//destructor

     Puntuacion *score; //Se instancia la clase Puntuacion
     Vidas_Jugador *health; //Se instancia la clase Vidas_jugador

     //------------------------------------------------------------

     int contador = 0; //Para el cronometro que aparece en la pantalla

     int Multijugador;

     int Contador_Multijugador;

private:
    Ui::VentanaJuego*ui;
    QGraphicsScene *scene;//Para crear la escena

    //-------------------------------------------------------------------

    //Snicth Dorada
    Snitch_Dorada *snich; //Se instancia un objeto tipo Snitch_Dorada

    //-------------------------------------------------------------------

    string Nombre_Jugador;

    //-------------------------------------------------------------------

    //Para el jugador principal
    Jugador *personaje;
    //Timers
    QTimer *time;//Crea el tiempo para los personajes Decoración Escenario
    QTimer *timer;//Crea el tiempo para los enemigos

    //-------------------------------------------------------------------

    //Para los personajes del escenario

    Personaje1_Decoracion *Hermione;//Crea 1 personaje de decoración del escenario
    Personaje2_Decoracion *Malfoi;//crea 2 personaje de decoración del escenario
    Personaje3_Decoracion *CarroVolador;

    //Variables para personajes de decoración del escenario
    float rad;//Ángulo(radianes)
    float Posx_Hermione,Posy_Hermione,i; //Para posiciones
    float Posx_Malfoi,Posy_Malfoi;

public slots:
    void posicionPersonajeEscenario();
    void funcionActivacionTimer(); // Para el cronometro que aparece en la pantalla

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // VENTANAJUEGO_H
