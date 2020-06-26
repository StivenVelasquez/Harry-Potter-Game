#include "ventanajuego.h"
#include "ui_ventanajuego.h"

VentanaJuego::VentanaJuego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);
}

VentanaJuego::~VentanaJuego()
{
    delete ui;
}

