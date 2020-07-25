#include "inicio.h"
#include "ui_inicio.h"

//Instancias de clases
Registrar *Registro;
Login *login;

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

    //Para la música
    mMediaPlayer =new QMediaPlayer(this);
    mMediaPlayer->setMedia(QUrl("qrc:/Musica/harry-potter_Musica Inicio.mp3")); //Se obtiene la dirección
    mMediaPlayer->setVolume(15); //Volumen
    mMediaPlayer->play();//Para iniciar la música

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
