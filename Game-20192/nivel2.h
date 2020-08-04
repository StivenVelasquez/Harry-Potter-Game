#ifndef NIVEL2_H
#define NIVEL2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>

#include "mortifago.h"
#include "jugador.h"
#include "vidas_jugador.h"
#include "puntuacion.h"
#include "hedwig.h"
#include "ventanajuego.h"

using namespace  std;

namespace Ui {
class Nivel2;
}

class Nivel2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = nullptr);//Constructor
    ~Nivel2();//Destructor
    Puntuacion *m_score; //Se instancia la clase Puntuacion
    Vidas_Jugador *m_health; //Se instancia la clase Vidas_jugador

    string Nombre_Jugador; //Variable utilizada en el guardado de las partidas

public slots:
    void spawn(); //Para crear los mortifagos

private slots:
    void on_pushButton_clicked();//Para guardar las partidas
    void actualizar(); //Actualizacion

private:
    Ui::Nivel2 *ui;
     QGraphicsScene *scene;//Para crear la escena
     QTimer *timer;//Crea el tiempo para los enemigos    
     QTimer *cronometro; //Se instancia un objeto tipo QTimer
     Hedwig *Lechuzas[3];//Se instancia objeto tipo Hedwig
     Jugador *personajeNivel2; //Se crea el personaje principal
};

#endif // NIVEL2_H
