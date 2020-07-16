#include "inicio.h"
#include <QApplication>



Inicio *inicio;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    inicio=new Inicio();
    inicio->show();
    return a.exec();
}
