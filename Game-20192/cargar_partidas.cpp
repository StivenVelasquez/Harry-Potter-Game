#include "cargar_partidas.h"
#include "ui_cargar_partidas.h"
#include "login.h"
#include "ventanajuego.h"
#include "nivel2.h"

#include <QDebug>

extern Login *login; //Se usa clase externa
VentanaJuego *game; //Se usa clase externa
Nivel2 * nivel2;

Cargar_Partidas::Cargar_Partidas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cargar_Partidas)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/FondoInicio.jpg")));
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical


    a=login->jugador;//Nombre del jugador actual
}


Cargar_Partidas::~Cargar_Partidas()
{
    delete ui;
}

void Cargar_Partidas::on_pushButton_clicked()
{
    ifstream lectura;
    bool encontrado_=false;
    string jugador,auxJugador, NombreJugador, Contra;
    int Puntaje, Nivel, Vidas;

    lectura.open("JUGADORES.txt",ios::in);

    if(lectura.is_open()){
      lectura>>jugador;
       while(!lectura.eof()){
           lectura>>Contra>>Puntaje>>Vidas>>Nivel;
           if(jugador==a){
               encontrado_=true;

             Puntaje_Jugador=Puntaje;
             Vidas_Jugador=Vidas;
             Nivel_Juego=Nivel;
           }

            lectura>>jugador;
     }

    }

     lectura.close();

     if(Nivel_Juego==1){
         Para_Jugar_Nivel_1=2;
         game= new VentanaJuego();
         game->show();
         this->close();
     }


     if(Nivel_Juego==2){
         nivel2= new Nivel2();//Se abre en modo de guardado de partida
         nivel2->show();
         Para_Jugar_Nivel_2=2;
         this->close();
    }


     qDebug()<<"NIVEL JUEGO"<<Nivel_Juego<<endl;

}


void Cargar_Partidas::on_pushButton_2_clicked()
{
    Para_Jugar_Nivel_1=1;
    game= new VentanaJuego();
    game->show();
    this->close();
}
