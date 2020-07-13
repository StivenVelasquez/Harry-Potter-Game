//#include "ventanajuego.h"
#include "inicio.h"
#include <QApplication>

//VentanaJuego * game;

Inicio *inicio;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    inicio=new Inicio();
    inicio->show();

   // game = new VentanaJuego();
   // game->show();
//    VentanaJuego w;
//    w.show();
    return a.exec();
}
