#include "ventanajuego.h"
#include <QApplication>
#include <ctime>
//#include <QDebug>
//#include <nivel2.h>

Nivel2 *U;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(time(nullptr));
    //qDebug()<<U->PosicionRandom(1,5);
    //return 0;
    VentanaJuego w;
    w.show();
    return a.exec();
}
