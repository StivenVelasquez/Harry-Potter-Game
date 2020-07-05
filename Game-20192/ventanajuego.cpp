#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include <QtDebug>


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

    QPen mypen= QPen(Qt::red);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);

    //Se crea el jugador
    personaje= new Jugador();

    //Se agrega el personaje a la escena
    scene->addItem(personaje);

    //make rect focusable
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->setPos(100,100);

    //Para enemigos
    int EnemyCount=1;

    //----------------------------------------------------------------------------
    //set the speed
    speed=5;

    //------------------------------------------------------------------------------

   // for(int i=0; i< EnemyCount; i++){
        Enemy=new Enemigo;
        scene->addItem(Enemy);
//}

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(avanzar()));
    timer->start(100);

//-----------------------------------------------------------------------------------
    //Personajes para la decoracion del escenario
    //se inicializan variables
    x=y=0;
    i=0;
    x_=y_=0;
    rad=0.01745329252;

    Hermione=new Personaje1_Decoracion;
    Malfoi= new Personaje2_Decoracion;
    time = new QTimer(this);
    scene->addItem(Hermione);//añade los circulos a la escena
    //c2->setPos(x,y);//Asigna la posicion
    scene->addItem(Malfoi);
    Malfoi->setPos(400,200);//Asigna la posicion

    //Para movimiento de los personajes decoracion
    time->start(21);
    connect(time,SIGNAL(timeout()),this,SLOT(posicionPersonajeEscenario()));
    connect(this,SIGNAL(cambiar()),this,SLOT(posicionInvPersonajeEscenario()));
}

VentanaJuego::~VentanaJuego()
{
    delete ui;
    delete timer;
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
}

void VentanaJuego::colliding(void)
{
    collide=Hermione->collidesWithItem(Malfoi);
    if(collide==true){
       emit cambiarDireccion();
    }
}

/*void VentanaJuego::PosicionEnemigos()
{
    m_x=StartX;
    m_y=StartY;

   // setPos(mapToParent(StartX,StartY));
    QPointF newpoin=Enemy->mapToParent(StartX,StartY);
    Enemy->setPos(newpoin);

    angle=(qrand()%360);
    Enemy->setRotation(angle);

    //random star position
    if((qrand()%1)){
        StartX=(qrand()%200);
        StartY=(qrand()%200);
    }

    else
    {
        StartX=(qrand()%-100);
        StartY=(qrand()%-100);
    }

    //set the speed
    speed=5;
}*/

void VentanaJuego::DoCollision()
{
    //set a new position
    //Cambiar anglecon a little randomness

    if(((qrand()%1))){
       Enemy->setRotation(Enemy->rotation()+180+(qrand()%10));
}
    else
    {
       Enemy->setRotation(Enemy->rotation()+180+(qrand()%-10));

    }


    //see if the new position is in bounds

    //QPointF newpoint=mapToParent(-(boundingRect().width()), -(boundingRect().width()+2));
    QPointF newpoint=Enemy->mapToParent(-150, -133+2);

    if(!scene->sceneRect().contains((newpoint))){
        //move it back in bounds
        newpoint=Enemy->mapToParent(0,0);
    }

    else
    {
        //set the new position
        Enemy->setPos(newpoint);
    }
}

void VentanaJuego::avanzar()
{
    //if(!phase) return;

         QPointF location=Enemy->pos();
     // setPos(mapToParent(0,-(speed)));
  //if(personaje->collidesWithItem(tortuga.at(i))){
      // if(Enemigo->collidesWithItem(tortuga)){
          if(!(scene->collidingItems(Enemy).isEmpty()))
     // if((Enemy->collidesWithItem(Hermione))||!(Enemy->collidesWithItem(Malfoi))||!(Enemy->collidesWithItem(personaje)))

      {
      DoCollision();

     }

      QPointF newpoi=Enemy->mapToParent(0, -(speed));

      Enemy->setPos(newpoi);
}

void VentanaJuego::posicionInvPersonajeEscenario()
{

    rad=-1*rad;
}



