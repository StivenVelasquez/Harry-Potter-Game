#ifndef MODOJUEGO_H
#define MODOJUEGO_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "ventanajuego.h"
#include "ventana_multijugador.h"

namespace Ui {
class ModoJuego;
}

class ModoJuego : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModoJuego(QWidget *parent = nullptr);
    ~ModoJuego();

    int Jugador; //Variable para indicar si se quiere jugar con un jugador o multijugador
    int Contador_Multijugador;

private slots:
    void on_pushButton_clicked();//Un jugador
    void on_pushButton_2_clicked();//multijugador

private:
    Ui::ModoJuego *ui;
     QGraphicsScene *scene; //Se crea un objeto tipo QGraphicsScene
};

#endif // MODOJUEGO_H
