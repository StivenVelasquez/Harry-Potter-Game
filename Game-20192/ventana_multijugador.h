#ifndef VENTANA_MULTIJUGADOR_H
#define VENTANA_MULTIJUGADOR_H

#include <QMainWindow>
#include "ventanajuego.h"

namespace Ui {
class Ventana_Multijugador;
}

class Ventana_Multijugador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana_Multijugador(QWidget *parent = nullptr);
    ~Ventana_Multijugador();

    int Multijugador;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Ventana_Multijugador *ui;
};

#endif // VENTANA_MULTIJUGADOR_H
