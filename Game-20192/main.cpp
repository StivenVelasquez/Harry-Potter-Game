#include "inicio.h"
#include "nivel2.h"
#include <QApplication>



Inicio *inicio;
Nivel2 *nivel;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    inicio=new Inicio();
//    inicio->show();
      nivel=new Nivel2();
        nivel->show();
    return a.exec();
}
