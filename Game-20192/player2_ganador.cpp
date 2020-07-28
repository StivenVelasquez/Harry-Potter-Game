#include "player2_ganador.h"
#include "ui_player2_ganador.h"
#include "ventana_multijugador.h"

extern Ventana_Multijugador *multijugador; //Se usa clase externa
extern VentanaJuego *game_Multijugador1; //Se instancia objeto de la clase VentanaJuego para Player1
extern VentanaJuego *game_Multijugador2; //Se instancia objeto de la clase VentanaJuego para Player2

Player2_Ganador::Player2_Ganador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player2_Ganador)
{    
    ui->setupUi(this);

    multijugador->close();
    game_Multijugador1->close();
    game_Multijugador2->close();

    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,905,510);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Player2_Wins.png"))); //Fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

Player2_Ganador::~Player2_Ganador()
{
    delete ui;
}
