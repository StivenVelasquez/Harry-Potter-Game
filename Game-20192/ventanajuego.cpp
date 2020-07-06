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
    int EnemyCount=5;

    //----------------------------------------------------------------------------
    //set the speed
    speed=5;

    //------------------------------------------------------------------------------

    for(int i=0; i< EnemyCount; i++){
        Enemy[i]=new Enemigo;
        scene->addItem(Enemy[i]);
}

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(avanzar()));
    timer->start(100);

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

     int num=ceil(xc);


      if(num == -700 ){

       CarroVolador->setRotation(CarroVolador->rotation()+180+(qrand()%10));

       //see if the new position is in bounds

       //QPointF newpoint=mapToParent(-(boundingRect().width()), -(boundingRect().width()+2));
       QPointF newpoint=CarroVolador->mapToParent(-150, -150+2);

       if(!scene->sceneRect().contains((newpoint))){
           //move it back in bounds
           newpoint=CarroVolador->mapToParent(0,0);
       }

       else
       {
           //set the new position
           CarroVolador->setPos(newpoint);
       }
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

void VentanaJuego::DoCollision()
{
    //set a new position
    //Cambiar anglecon a little randomness

    for(int i=0; i<5; i++){

    if(((qrand()%1))){
       // for(int i=0; i<2; i++){
       Enemy[i]->setRotation(Enemy[i]->rotation()+180+(qrand()%10));
        }

    else
    {        

       Enemy[i]->setRotation(Enemy[i]->rotation()+180+(qrand()%-10));
       }




    //see if the new position is in bounds

    //QPointF newpoint=mapToParent(-(boundingRect().width()), -(boundingRect().width()+2));

    QPointF newpoint=Enemy[i]->mapToParent(-150, -133+2);


    if(!scene->sceneRect().contains((newpoint))){
        //move it back in bounds
        newpoint=Enemy[i]->mapToParent(0,0);
    }

    else
    {
        //set the new position
        Enemy[i]->setPos(newpoint);
    }
}
}

void VentanaJuego::avanzar()
{
    //if(!phase) return;

    for(int i=0; i<5; i++){
         QPointF location=Enemy[i]->pos();
     // setPos(mapToParent(0,-(speed)));
  //if(personaje->collidesWithItem(tortuga.at(i))){
      // if(Enemigo->collidesWithItem(tortuga)){
          if(!(scene->collidingItems(Enemy[i]).isEmpty()))
        // if(!(Enemy[i]->collidesWithItem(Hermione))&&!(Enemy[i]->collidesWithItem(Malfoi))&&!(Enemy[i]->collidesWithItem(personaje)))

      {
    DoCollision();

     }


      QPointF newpoi=Enemy[i]->mapToParent(0, -(speed));
      Enemy[i]->setPos(newpoi);
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
