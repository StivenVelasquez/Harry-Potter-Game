#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDebug>
#include <fstream>
#include <QMessageBox>
#include <iomanip>
#include <QGraphicsScene>

#include "modojuego.h"
#include "inicio.h"

using namespace std;

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);//Constructor
    ~Login();//Destructor

    string Contra, jugador; //Jugador/Contraseña

private slots:
    void on_pushButton_clicked(); //Para verificar datos

private:
    Ui::Login *ui;
    QGraphicsScene *scene; //Instanciación de clase


};

#endif // LOGIN_H
