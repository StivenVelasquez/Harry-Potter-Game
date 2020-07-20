#include "vidas_jugador.h"
#include <QFont>
#include "ventanajuego.h"

//extern VentanaJuego *game; //Se usan clases externas

Vidas_Jugador::Vidas_Jugador(int x){//Constructor
    // Inicializar las vidas en 3
    Vidas = x;

    // Dibujar texto
    setPlainText(QString("VIDAS: ") + QString::number(Vidas)); // Vidas: 3
    setDefaultTextColor(Qt::yellow); //Color de letra
    setFont(QFont("papirus",16)); //Tipo de letra
}

int Vidas_Jugador::decrecer(){
    Vidas--;
    setPlainText(QString("VIDAS: ") + QString::number(Vidas)); // Vidas: 2
    return Vidas;
}

//    if(getVidas_Jugador()==0 || getVidas_Jugador() < 0)
//    {
//        setPlainText("Game over"); // Vidas: 0
//        setDefaultTextColor(Qt::red);
//        setFont(QFont("times",32));
//        setPos(300,300);

//       // game->gameOver();

//    }
//}

int Vidas_Jugador::getVidas_Jugador(){

    return Vidas;
}
