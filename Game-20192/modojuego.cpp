#include "modojuego.h"
#include "ui_modojuego.h"
#include "cargar_partidas.h"

Ventana_Multijugador *multijugador; //Se instancia un objeto tipo Ventana_Multijugador
Cargar_Partidas *Partidas; //Se instancia  un objeto tipo Cargar_Partidas


ModoJuego::ModoJuego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModoJuego)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/FondoInicio.jpg"))); //Fondo
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
    Jugador=1;
    Partidas =new Cargar_Partidas();//Se crea una ventana de Cargar_Partidas
    Partidas->show();//Se muestra
    this->close();//Se cierra ventana modo_Juego
}

void ModoJuego::on_pushButton_2_clicked()
{
  //Multijugador=2;//Para Multijugador
  Jugador=2;
  multijugador=new Ventana_Multijugador();
  multijugador->show();
  this->close();//Se cierra ventana modo_Juego
}
