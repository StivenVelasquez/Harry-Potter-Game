#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMediaPlayer>

#include "ventanajuego.h"
#include "registrar.h"
#include "login.h"

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow //Clase inicio.
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);//Constructor
    ~Inicio();//Destructor

private slots: //slots
    void on_pushButton_clicked(); //Para registro
    void on_pushButton_2_clicked();//Para login

private:
    Ui::Inicio *ui;
    QGraphicsScene *scene; //Se instancia un objeto tipo QGraphicsScene
    QMediaPlayer *mMediaPlayer; //Se instancia un objeto tipo QMediaPlayer
};

#endif // INICIO_H
