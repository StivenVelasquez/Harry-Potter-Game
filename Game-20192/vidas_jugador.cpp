#include "vidas_jugador.h"
#include <QFont>
#include<QMessageBox>
#include "ventanajuego.h"

extern VentanaJuego *game; //Se usan clases externas

Vidas_Jugador::Vidas_Jugador(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Inicializar las vidas en 3
    Vidas = 3;

    // Dibujar texto
    setPlainText(QString("Health: ") + QString::number(Vidas)); // Vidas: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Vidas_Jugador::decrecer(){
    Vidas--;
    setPlainText(QString("Health: ") + QString::number(Vidas)); // Vidas: 2

    if(getVidas_Jugador()==0 || getVidas_Jugador() < 0)
    {
        setPlainText("Game over"); // Vidas: 0
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",32));
        setPos(300,300);

       // game->gameOver();

    }
}

int Vidas_Jugador::getVidas_Jugador(){

    return Vidas;
}
