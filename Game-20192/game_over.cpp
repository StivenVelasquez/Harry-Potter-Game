#include "game_over.h"
#include "ui_game_over.h"

Game_Over::Game_Over(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game_Over)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,905,510);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Game_Over.png"))); //Fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

Game_Over::~Game_Over()
{
    delete ui;
}
