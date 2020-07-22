#include "ventana_multijugador.h"
#include "ui_ventana_multijugador.h"

VentanaJuego *game_Multijugador;

Ventana_Multijugador::Ventana_Multijugador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana_Multijugador)
{
    ui->setupUi(this);
}

Ventana_Multijugador::~Ventana_Multijugador()
{
    delete ui;
}

void Ventana_Multijugador::on_pushButton_clicked()
{
  Multijugador=1;
  game_Multijugador=new VentanaJuego();//Se crea un nivel principal
  game_Multijugador->show();//Mostrar Ventana
  this->close();//Se cierrae esta ventana
}

void Ventana_Multijugador::on_pushButton_2_clicked()
{
  Multijugador=1;
  game_Multijugador=new VentanaJuego();//Se crea un nivel principal
  game_Multijugador->show();//Mostrar Ventana
  this->close();//Se cierrae esta ventana
}
