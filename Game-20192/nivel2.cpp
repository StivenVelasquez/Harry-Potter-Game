#include "nivel2.h"
#include "ui_nivel2.h"

Nivel2::Nivel2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    mThread=new DuThread(10,this);

    //Para personajes
    QStringList enemigos;
}

Nivel2::~Nivel2()
{
    delete ui;
}
