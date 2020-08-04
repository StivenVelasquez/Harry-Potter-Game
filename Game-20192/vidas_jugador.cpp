#include "vidas_jugador.h"
#include <QFont>
#include "ventanajuego.h"

Vidas_Jugador::Vidas_Jugador(int x){//Constructor
    // Inicializar las vidas
    Vidas = x;

    // Dibujar texto
    setPlainText(QString("VIDAS: ") + QString::number(Vidas)); // Vidas: 3
    setDefaultTextColor(Qt::yellow); //Color de letra
    setFont(QFont("papirus",16)); //Tipo de letra
}

int Vidas_Jugador::decrecer(){
    Vidas--;//Se resta a las vidas
    setPlainText(QString("VIDAS: ") + QString::number(Vidas)); //Dibujar texto
    return Vidas;
}

int Vidas_Jugador::getVidas_Jugador(){

    return Vidas;
}
