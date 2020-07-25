#include "ventana_multijugador.h"
#include "ui_ventana_multijugador.h"

VentanaJuego *game_Multijugador1; //Se instancia objeto de la clase VentanaJuego para Player1
VentanaJuego *game_Multijugador2; //Se instancia objeto de la clase VentanaJuego para Player2

Ventana_Multijugador::Ventana_Multijugador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Multijugador)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Harry_Potter_Fondo_Ventana_Multijugador.png"))); //Fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical

    // Se iniciliza el Contador de los Multijugadores
    Contador_Multijugador=0;
}

Ventana_Multijugador::~Ventana_Multijugador()
{
    delete ui;
}

void Ventana_Multijugador::on_pushButton_clicked()
{
  Multijugador=1;
  Jugar=1; //El jugador 1 esta jugando

  game_Multijugador1=new VentanaJuego();//Se crea un nivel principal
  game_Multijugador1->show();//Mostrar Ventana

  this->close();//Se cierra esta ventana
}

void Ventana_Multijugador::on_pushButton_2_clicked()
{
  Multijugador=1;
  Jugar=2; //El jugador 2 esta jugando

  game_Multijugador2=new VentanaJuego();//Se crea un nivel principal
  game_Multijugador2->show();//Mostrar Ventana

  this->close();//Se cierra esta ventana
}
