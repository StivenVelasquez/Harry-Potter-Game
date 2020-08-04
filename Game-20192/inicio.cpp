#include "inicio.h"
#include "ui_inicio.h"

//Instancias de clases
Registrar *Registro;
Login *login;
QMediaPlayer *Iniciosound; //Se instancia un objeto tipo QMediaPlayer

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Harry Potter-Fondo_Inicio.jpg"))); //Fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical

    //Para musica de inicio
     Iniciosound=new QMediaPlayer();
     Iniciosound->setMedia(QUrl("qrc:/Musica/Lumos Hedwigs Theme.mp3"));
     Iniciosound->setVolume(25); //Volumen

     if(Iniciosound->state()==QMediaPlayer::PlayingState){
         Iniciosound->setPosition(0);
     }

     else if(Iniciosound->state()==QMediaPlayer::StoppedState){
         Iniciosound->play();
     }

    remove("MULTIJUGADOR.txt");//Se remueva fichero de multijugadores

   }

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_pushButton_clicked() //Para registro
{

    Registro= new Registrar(); //Se crea una ventana de registro
    Registro->show();//Se muestra
}

void Inicio::on_pushButton_2_clicked()//Para Login
{
    login=new Login();//Se crea una ventana de login
    login->show();//Se muestra
}
