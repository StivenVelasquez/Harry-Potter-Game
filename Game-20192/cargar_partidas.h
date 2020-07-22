#ifndef CARGAR_PARTIDAS_H
#define CARGAR_PARTIDAS_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <fstream>
//#include "nivel2.h"

//#include "nivel2.h"

using namespace std;

namespace Ui {
class Cargar_Partidas;
}

class Cargar_Partidas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cargar_Partidas(QWidget *parent = nullptr);
    ~Cargar_Partidas();

    string a;
    int Puntaje_Jugador,Vidas_Jugador, Nivel_Juego;

    int Para_Jugar_Nivel_1;
    int Para_Jugar_Nivel_2;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Cargar_Partidas *ui;
     QGraphicsScene *scene;
};

#endif // CARGAR_PARTIDAS_H
