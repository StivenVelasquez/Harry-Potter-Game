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

    int UniJugador_o_Multijugador;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ModoJuego *ui;
     QGraphicsScene *scene;
};

#endif // MODOJUEGO_H
