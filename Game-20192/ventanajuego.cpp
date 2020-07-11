#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include <QtDebug>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>

#include <enemigo.h>

VentanaJuego::VentanaJuego(QWidget *parent) :QMainWindow(parent),ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);

    //Se crea la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,905,510);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/harry potter-fondo.jpg")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //Se crea el jugador
    personaje= new Jugador();

    //Si es multijugador
    personaje2=new Jugador2;

    //Se agrega el personaje a la escena
    scene->addItem(personaje);

    scene->addItem(personaje2);

    //make rect focusable
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->setPos(100,100);

    //Para multijugador

    personaje2->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje2->setFocus();
    personaje2->setPos(800,100);

//-----------------------------------------------------------------------------------
    //Personajes para la decoracion del escenario
    //se inicializan variables
    x=y=0;
    i=0;
    x_=y_=0;
    xc=yc=0;
    vo=30;
    rad=0.01745329252;

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

    //kreiranje enemya
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
    timer->start(7000);

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

  if(CarroVolador->pos().y() >-360){
   xc=vo*cos(60)*i;
   yc=-vo*sin(60)*dt-0.5*(9.8)*i*i;
   CarroVolador->setPos(xc,yc);
   qDebug()<<xc<<endl;
  }

  else{
      if(CarroVolador->pos().x() > -700.351 ){
      xc=CarroVolador->pos().x()-1;
      yc=CarroVolador->pos().y();
      CarroVolador->setPos(xc,yc);
       qDebug()<<xc<<endl;
      }

   int num=ceil(yc);

      if( num== -700 ){
          //Cambiar el angulo de movimiento con un poco de aletoriedad
        /*  if(((qrand() %1)))
          {
              setRotation(rotation() + (180 + (qrand() % 10)));
          }
          else
          {
              setRotation(rotation() + (180 + (qrand() % -10)));
          }

          //Ver si la nueva posicion esta dentro de los limites
          QPointF newpoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

          if(!scene()->sceneRect().contains((newpoint)))
          {
              // Se mueve en los limites
              newpoint = mapToParent(0,0);
          }
          else
          {
              //Se establece la nueva posicion
              qDebug() << "Collision";
              CarroVolador->setPos(newpoint);

          }*/

}
}
}




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

void VentanaJuego::on_pushButton_clicked()
{
    Nivel2 *nivel2 = new Nivel2(0);
    nivel2->show();
}


