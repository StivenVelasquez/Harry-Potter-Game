#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "ventanajuego.h"
#include "registrar.h"
#include "login.h"

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);//Constructor
    ~Inicio();//Destructor

private slots:
    void on_pushButton_clicked(); //Para registro
    void on_pushButton_2_clicked();//Para login

private:
    Ui::Inicio *ui;
     QGraphicsScene *scene;
};

#endif // INICIO_H
