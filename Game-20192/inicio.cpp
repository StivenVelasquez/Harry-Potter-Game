#include "inicio.h"
#include "ui_inicio.h"

//VentanaJuego *game;
Registrar *Registro;
Login *login;

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/FondoInicio.jpg")));
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_pushButton_clicked()
{

    Registro= new Registrar();
    Registro->show();
}

void Inicio::on_pushButton_2_clicked()
{
    login=new Login();
    login->show();
}
