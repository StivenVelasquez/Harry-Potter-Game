#ifndef VIDAS_JUGADOR_H
#define VIDAS_JUGADOR_H

#include <QGraphicsTextItem>

class Vidas_Jugador: public QGraphicsTextItem{
public:
    Vidas_Jugador(int x); //constructor
    int decrecer();
    int getVidas_Jugador(); //Se obtienen las vidas del jugador

private:
    int Vidas;
};

#endif // VIDAS_JUGADOR_H
