#include "inicio.h"
#include <QApplication>

Inicio *inicio; //Se instancia un objeto tipo Inicio

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Se crea una Ventana Inicio
    inicio=new Inicio();
    inicio->show();//Se muestra

    return a.exec();
}
