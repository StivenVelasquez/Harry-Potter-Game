#include "you_win.h"
#include "ui_you_win.h"

You_Win::You_Win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::You_Win)
{
    ui->setupUi(this);
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,905,510);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/You Win.jpg"))); //Fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

You_Win::~You_Win()
{
    delete ui;
}
