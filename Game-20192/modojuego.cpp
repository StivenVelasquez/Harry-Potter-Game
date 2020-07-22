#include "modojuego.h"
#include "ui_modojuego.h"
#include "cargar_partidas.h"

//VentanaJuego *game;
Ventana_Multijugador *multijugador;
Cargar_Partidas *Partidas;


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
    Partidas =new Cargar_Partidas();
     Partidas->show();
   // game=new VentanaJuego();
    //game->show();
   // UniJugador_o_Multijugador=1;//Para Jugador Unitario
    this->close();    
}

void ModoJuego::on_pushButton_2_clicked()
{
 // multijugador=new Ventana_Multijugador();
  //multijugador->show();
  //UniJugador_o_Multijugador=2;//Para Multijugador
}
