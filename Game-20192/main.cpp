#include "ventanajuego.h"
#include <QApplication>

VentanaJuego * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new VentanaJuego();
    game->show();
//    VentanaJuego w;
//    w.show();
    return a.exec();
}
