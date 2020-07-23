#include "ventana_multijugador.h"
#include "ui_ventana_multijugador.h"

VentanaJuego *game_Multijugador1;
VentanaJuego *game_Multijugador2;

Ventana_Multijugador::Ventana_Multijugador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Multijugador)
{
    ui->setupUi(this);
    int Contador_Multijugador=0;
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
  this->close();//Se cierrae esta ventana
}

void Ventana_Multijugador::on_pushButton_2_clicked()
{
  Multijugador=1;
  Jugar=2; //El jugador 2 esta jugando
  game_Multijugador2=new VentanaJuego();//Se crea un nivel principal
  game_Multijugador2->show();//Mostrar Ventana
  this->close();//Se cierrae esta ventana
}
