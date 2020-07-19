#include "nivel2.h"
#include "ui_nivel2.h"

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

    //Crear Snape
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(900);//Cada que pase este tiempo se crea

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
