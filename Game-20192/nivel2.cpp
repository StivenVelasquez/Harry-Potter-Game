#include "nivel2.h"
#include "ui_nivel2.h"

Nivel2::Nivel2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    //mThread=new DuThread(20,this);

    //Se crea la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,720,400);

    QPixmap background(":/Imagenes/fondoNivel2.gif");
    background=background.scaled(720,400);
    scene->addPixmap(background);
   // ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/fondoNivel2.gif")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

   setMinimumSize(720,400);
   setMaximumSize(720,400);

    //Para personajes
    QStringList enemigos={":/Imagenes/bellatrix.png",":/Imagenes/dolores.png",":/Imagenes/peter.png"};

    for(const auto &iEnemy : enemigos)
    {
        int x,y, vx,vy;
        x=PosicionRandom(0,720);
        y=PosicionRandom(0,400);
        vx=PosicionRandom(3,5);
        vy=PosicionRandom(3,5);
        auto enemigo=new PersonajesNivel2(iEnemy, x, y, vx, vy);
        scene->addItem(enemigo);//Agregamos el personaje
        mpersonajes.append(enemigo); //se agrega a la lista de personajes del nivel
    }

   // mThread->start();

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(avanzar()));
    timer->start(100);
    //connect(mThread, &DuThread::timeOut, [&](){ //Para el movimimiento en el escenario
//        for(const auto &iEnemy: mpersonajes)
//        {
//            int x;
//            int y;

//            x=iEnemy->get_x();
//            y=iEnemy->get_y();

//            //Controlar limites de la pantalla

//            if(x<=0 ||x>=720){

//                iEnemy->set_vx(-iEnemy->get_vx());

//            }

//            if(y<=0 ||y>=400){

//                iEnemy->set_vy(-iEnemy->get_vy());

//            }

//            x+= iEnemy->get_vx();
//            y+= iEnemy->get_vy();


//            iEnemy->set_x(x);
//            iEnemy->set_y(y);
//        }

          // update();
   // });

   // mThread->start();

}

Nivel2::~Nivel2()
{
    delete ui;
}

int Nivel2::PosicionRandom(int iL, int sL)
{

        return qrand()% sL+iL;

}

void Nivel2::avanzar()
{
    for(const auto &iEnemy: mpersonajes)
        {
            int x;
            int y;

            x=iEnemy->get_x();
            y=iEnemy->get_y();

            //Controlar limites de la pantalla

            if(x<=0 ||x>=720){

                iEnemy->set_vx(-iEnemy->get_vx());

            }

            if(y<=0 ||y>=400){

                iEnemy->set_vy(-iEnemy->get_vy());

            }

            x+= iEnemy->get_vx();
            y+= iEnemy->get_vy();


            iEnemy->set_x(x);
            iEnemy->set_y(y);
        }

}
