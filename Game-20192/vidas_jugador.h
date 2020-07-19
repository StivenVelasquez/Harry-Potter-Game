#ifndef VIDAS_JUGADOR_H
#define VIDAS_JUGADOR_H

#include <QGraphicsTextItem>

class Vidas_Jugador: public QGraphicsTextItem{
public:
    Vidas_Jugador(QGraphicsItem * parent=0);
    void decrecer();
    int getVidas_Jugador();

private:

    int Vidas;
};

#endif // VIDAS_JUGADOR_H
