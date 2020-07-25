#ifndef CARGAR_PARTIDAS_H
#define CARGAR_PARTIDAS_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <fstream>

using namespace std;

namespace Ui {
class Cargar_Partidas;
}

class Cargar_Partidas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cargar_Partidas(QWidget *parent = nullptr); //Constructor
    ~Cargar_Partidas();//Destructor

    string Nombre_Jugador;//Nombre de jugador que se compara con los del archivo "JUGADORES.txt"
    int Puntaje_Jugador,Vidas_Jugador, Nivel_Juego; //Aquí se guarda el valor de las variables que tiene el archivo en su interior

    int Para_Jugar_Nivel_1; //Variable para las partidas, para saber que nivel se abrirá
    int Para_Jugar_Nivel_2;//Variable para las partidas, para saber que nivel se abrirá

private slots:
    void on_pushButton_clicked();//Botón para cargar partida
    void on_pushButton_2_clicked();//Botón para partida nueva

private:
    Ui::Cargar_Partidas *ui;
     QGraphicsScene *scene; //Se instancia un objeto tipo QGraphicsScene
};

#endif // CARGAR_PARTIDAS_H
