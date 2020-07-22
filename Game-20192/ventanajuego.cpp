#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include <QtDebug>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <nivel2.h>
#include "cargar_partidas.h"

extern Login *login; //Se usa clase externa
extern Spell *spell;//Se usa clase externa
extern Cargar_Partidas *Partidas; //Se usa clase externa

Nivel2 *nivel;

VentanaJuego::VentanaJuego(QWidget *parent) :QMainWindow(parent),ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);

    //Se crea la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,905,510);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/harry potter-fondo.jpg")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setScene(scene);//Se añade la escena
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //------------------------------------------------------------------------------------------
    //Se crea el jugador 1
    personaje= new Jugador();

    //Se agrega el personaje a la escena
    scene->addItem(personaje);

    //make rect focusable
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->setPos(100,100);

//-----------------------------------------------------------------------------------
    //Personajes para la decoracion del escenario

    //se inicializan variables para Hermione
    x=y=0;
    i=0;
    rad=0.01745329252; //Radio para Hermione y Malfoi

    //==============================================

    //se inicializan variables para Malfoi
    x_=y_=0;

    //==============================================
    //se inicializan variables para el Carro Volador
    xc=yc=0;
    vo=30;

     XIzquierda=-700.351;
     XDerecha=0;
     YSuperior=-360;
     YInferior=0;

    //==============================================

    //Se crean los personajes

    Hermione=new Personaje1_Decoracion;
    Malfoi= new Personaje2_Decoracion;
    CarroVolador=new Personaje3_Decoracion;

    time = new QTimer(this);

    scene->addItem(Hermione);//añade los circulos a la escena
    scene->addItem(Malfoi);
    scene->addItem(CarroVolador);

    Malfoi->setPos(400,200);//Asigna la posicion

    //Para movimiento de los personajes decoracion
    time->start(21);
    connect(time,SIGNAL(timeout()),this,SLOT(posicionPersonajeEscenario()));
    connect(this,SIGNAL(cambiar()),this,SLOT(posicionInvPersonajeEscenario()));

    //-------------------------------------------------------------------------

    //Generar enemigos
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
    timer->start(7000);

    //---------------------------------------------------------------------

    qDebug()<<"Para Jugar "<<Partidas->Para_Jugar_Nivel_1<<endl;

    if(Partidas->Para_Jugar_Nivel_1==1){
    //Para la puntuación de los jugadores
    score = new Puntuacion(0);//Se crea la puntuacion
    scene->addItem(score);//Se añade a la escena
    score->setPos(score->x()+750,score->y());//posicion en la escena

    //---------------------------------------------------------------------

    //Para las vidas de los jugadores
    health=new Vidas_Jugador(3);//Se crean las vidas
    scene->addItem(health);//Se añade a la escena
    health->setPos(health->x()+650, health->y());//Posicion en la escena
    }

    if(Partidas->Para_Jugar_Nivel_1==2){
        //Para la puntuación de los jugadores
        score = new Puntuacion(Partidas->Puntaje_Jugador);//Se crea la puntuacion
        scene->addItem(score);//Se añade a la escena
        score->setPos(score->x()+750,score->y());//posicion en la escena

        //---------------------------------------------------------------------

        //Para las vidas de los jugadores
        health=new Vidas_Jugador(Partidas->Vidas_Jugador);//Se crean las vidas
        scene->addItem(health);//Se añade a la escena
        health->setPos(health->x()+650, health->y());//Posicion en la escena
    }


    a=login->jugador;//Nombre del jugador actual

}


VentanaJuego::~VentanaJuego()
{
    delete ui;
    delete time;
}

void VentanaJuego::posicionPersonajeEscenario(void)
{
    int r=100;
    i+=rad;
    x=-1*r*cos(i*2);
    y=-1*r*sin(i*2);
    Hermione->setPos(x,y);//Cambia la posición de Hermione con x y y
    x_=r*pow(cos(i),3);
    y_=r*pow(sin(i),3);
    Malfoi->setPos(x_,y_);//Cambia la posición de Malfoi 2
    colliding();

  if(CarroVolador->pos().y() >YSuperior){ //Si llega hasta esta parte de la escena se movera con un movimiento parabolico
   xc=vo*cos(60)*i; //Posicion en 'x' del carro
   yc=-vo*sin(60)*dt-0.5*(9.8)*i*i;//Posicion en 'y' del carro
   CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
  // qDebug()<<xc<<endl;
  }

  if(CarroVolador->pos().x() > XIzquierda){//Mientras la posicion en x sea mayor a esto
  xc=CarroVolador->pos().x()-1; //Posicion en 'x' del carro
  yc=CarroVolador->pos().y();//Posicion en 'y' del carro
  CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena


     if(int(CarroVolador->pos().x()) ==int(XIzquierda)){
          while(CarroVolador->pos().x()<=0){
          xc=CarroVolador->pos().x()+20; //Posicion en 'x' del carro
          yc=CarroVolador->pos().y();//Posicion en 'y' del carro
          CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
          }
  }

  }


  /*if(CarroVolador->pos().x()<XDerecha){
     xc=CarroVolador->pos().x()+1; //Posicion en 'x' del carro
      yc=CarroVolador->pos().y();//Posicion en 'y' del carro
      CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
  }*/

          }
      //CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
      // qDebug()<<xc<<endl;




void VentanaJuego::colliding(void)
{
    collide=Hermione->collidesWithItem(Malfoi);
    if(collide==true){
       emit cambiarDireccion();
    }
}

void VentanaJuego::posicionInvPersonajeEscenario()
{

    rad=-1*rad;

}


void VentanaJuego::on_pushButton_2_clicked()
{
    ofstream aux;
    ifstream lectura;
    bool encontrado_=false;
    string jugador,auxJugador, NombreJugador, Contra;
    int Puntaje, Nivel, Vidas;

    aux.open("auxiliar.txt",ios::out|ios::app);
    lectura.open("JUGADORES.txt",ios::in);

    if(lectura.is_open() && aux.is_open()){
      lectura>>jugador;
       while(!lectura.eof()){
           lectura>>Contra>>Puntaje>>Vidas>>Nivel;
           if(jugador==a){
               encontrado_=true;

              aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<< score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< health->getVidas_Jugador()<<setw(7)<<setprecision(2)<<right<<1<<endl;

           }

           else{

               aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<<Puntaje<<endl<<setw(7)<<setprecision(2)<<right<<Vidas<<setw(7)<<setprecision(2)<<right<<Nivel<<endl;

           }
            lectura>>jugador;
     }

    }

    else

   qDebug()<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;




     lectura.close();
     aux.close();

     remove("JUGADORES.txt");
     rename("auxiliar.txt","JUGADORES.txt");

}

void VentanaJuego::on_pushButton_clicked()
{

    nivel= new Nivel2();
    nivel->show();
}
