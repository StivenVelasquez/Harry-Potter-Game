#include "nivel2.h"
#include "ui_nivel2.h"

Jugador *personajeNivel2; //Se crea el personaje principal

Nivel2::Nivel2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    //Se crea la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,905,510);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/background.jpg")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //Crear mortifagos
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(900);//Cada que pase este tiempo se crea

    //Se crea el jugador
    personajeNivel2= new Jugador();

    //Se agrega el personaje a la escena
    scene->addItem(personajeNivel2);

    //make rect focusable
    personajeNivel2->setFlag(QGraphicsItem::ItemIsFocusable);
    personajeNivel2->setFocus();
    personajeNivel2->setPos(100,100);

}

Nivel2::~Nivel2()
{
    delete ui;
}

void Nivel2::spawn()
{
    //create Bellatriz
    Mortifago * Snape = new Mortifago();
    scene->addItem(Snape);
}
