#ifndef VENTANA_MULTIJUGADOR_H
#define VENTANA_MULTIJUGADOR_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "ventanajuego.h"

namespace Ui {
class Ventana_Multijugador;
}

class Ventana_Multijugador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Multijugador(QWidget *parent = nullptr); //Constructor
    ~Ventana_Multijugador(); //Destructor

    int Multijugador;
    int Jugar; //Variable para saber si el jugador ya jugó o no ha jugado
    int Contador_Multijugador;//Contador de jugadores que han jugado

private slots:
    void on_pushButton_clicked();//jugador1
    void on_pushButton_2_clicked();//jugador 2

private:
    Ui::Ventana_Multijugador *ui;
     QGraphicsScene *scene; //Se instancia un objeto tipo QGraphicsScene
};

#endif // VENTANA_MULTIJUGADOR_H
