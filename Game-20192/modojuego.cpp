#include "modojuego.h"
#include "ui_modojuego.h"

VentanaJuego *game;

ModoJuego::ModoJuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModoJuego)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/FondoInicio.jpg")));
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

ModoJuego::~ModoJuego()
{
    delete ui;
}

void ModoJuego::on_pushButton_clicked()
{
    game=new VentanaJuego();
    game->show();
    this->close();
}

void ModoJuego::on_pushButton_2_clicked()
{

}
