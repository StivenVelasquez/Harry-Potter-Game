#ifndef NIVEL2_H
#define NIVEL2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "mortifago.h"
#include "jugador.h"
#include "vidas_jugador.h"
#include "puntuacion.h"
#include "hedwig.h"

//#include "mortifago.h"
//#include "jugador.h"
//#include "puntuacion.h"
//#include "vidas_jugador.h"
//#include "ventanajuego.h"
//#include "spell.h"
//#include "ventanajuego.h"
//#include "jugador.h"

namespace Ui {
class Nivel2;
}

class Nivel2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = nullptr);
    ~Nivel2();
     Puntuacion *m_score; //Se instancia la clase Puntuacion
     Vidas_Jugador *m_health; //Se instancia la clase Vidas_jugador

     string a;


public slots:
    void spawn(); //Para crear los mortifagos

private slots:
    void on_pushButton_clicked();
    void actualizar(); //Actualizacion

private:
    Ui::Nivel2 *ui;
     QGraphicsScene *scene;//Para crear la escena
     QTimer *timer;//Crea el tiempo para los enemigos    
     QTimer *cronometro;
     Hedwig *Cuerpos[3];
     Jugador *personajeNivel2; //Se crea el personaje principal

};

#endif // NIVEL2_H
