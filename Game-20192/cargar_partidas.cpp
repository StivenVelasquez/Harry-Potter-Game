#include "cargar_partidas.h"
#include "ui_cargar_partidas.h"
#include "login.h"
#include "ventanajuego.h"
#include "nivel2.h"

extern Login *login; //Se usa clase externa
VentanaJuego *game; //Se instancia un objeto de la clase VentanaJuego
Nivel2 * nivel2;//Se instancia un objeto de la lcase Nivel2

Cargar_Partidas::Cargar_Partidas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cargar_Partidas)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/FondoInicio.jpg")));//Se agrega fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical


    Nombre_Jugador=login->jugador;//Nombre del jugador actual, el cual es el último nombre que se digito en el login
}


Cargar_Partidas::~Cargar_Partidas()
{
    delete ui;
}

void Cargar_Partidas::on_pushButton_clicked()
{
    //Variables usadas para el proceso de los archivos
    ifstream lectura; //Variable para lectura de archivos
    string jugador, Contra;
    int Puntaje, Nivel, Vidas;

    lectura.open("JUGADORES.txt",ios::in); //Se abre o se crea el fichero "JUGADORES.txt"

    if(lectura.is_open()){ //Si el ficheroe sta abierto
      lectura>>jugador;//Se van leyendo las primeras palabras de cada fila
       while(!lectura.eof()){ //Mientras el fichero no haya llegado a su fin
           lectura>>Contra>>Puntaje>>Vidas>>Nivel; //Se lee lo que haya en esa fila donde se encontró el nombre
           if(jugador==Nombre_Jugador){

                 //Se hace asignación a variables
                 Puntaje_Jugador=Puntaje;
                 Vidas_Jugador=Vidas;
                 Nivel_Juego=Nivel;
           }

            lectura>>jugador; //Iteración hasta que encuentre el nombre
        }

    }

    lectura.close();

     if(Nivel_Juego==1){ //Si el nivel en el que quedó es nivel 1

         if(Vidas_Jugador<=0){
             //Para que aparezca mensaje en pantalla
             QMessageBox msgBox;
             msgBox.setText("No puede cargar partida. Por favor cargue una NUEVA PARTIDA");
             msgBox.exec();
         }

         else{
             Para_Jugar_Nivel_1=2; //Se tiene esta variable porque se va a trabajar con una ventana de juego creada a partir de las partidas guardadas

             //Se crea la ventana de juego
             game= new VentanaJuego();
             game->show();//Se muestra en la pantalla principal
             this->close();//Se cierra la ventana de Cargar_Partidas
         }
     }


     if(Nivel_Juego==2){//Si el nivel en el que quedó es nivel 2
         Para_Jugar_Nivel_2=2;//Se tiene esta variable porque se va a trabajar con una ventana de juego creada a partir de las partidas guardadas

         //Se crea ventana de nivel2
         nivel2= new Nivel2();
         nivel2->show();//Se muestra
         this->close();//Se cierra la ventana de Cargar_Partidas
    }

}


void Cargar_Partidas::on_pushButton_2_clicked()
{
    Para_Jugar_Nivel_1=1;//Se tiene esta variable porque se va a trabajar con una ventana de juego creada iniciando una partida nueva

    //Se crea la ventana de juego
    game= new VentanaJuego();
    game->show();//Se muestra
    this->close();//Se cierra la ventana de Cargar_Partidas
}
