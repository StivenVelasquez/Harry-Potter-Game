#include "inicio.h"
#include "nivel2.h"
#include "ventanajuego.h"
#include <QApplication>
#include <modojuego.h>
#include <game_over.h>

Inicio *inicio;
//Nivel2 *nivel;
//ModoJuego *Jugador;
//VentanaJuego *game;
//Game_Over *Final;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Final=new Game_Over();
    //Final->show();

    //game=new VentanaJuego();
   // game->show();


     //   Jugador=new ModoJuego();
     //   Jugador->show();
   inicio=new Inicio();
   inicio->show();
 //
//    nivel=new Nivel2();
//     nivel->show();
    return a.exec();
}
