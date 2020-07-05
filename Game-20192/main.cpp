#include "ventanajuego.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaJuego w;
    w.show();
    return a.exec();
}
