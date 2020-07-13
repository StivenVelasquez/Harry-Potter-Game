#ifndef SPELL_H
#define SPELL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Spell:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spell();
    void advance(int phase);

public slots:

   //Para movimiento de la llama del hechizo
    void move();

private:
    int PuntajeJugadorActual;
};

#endif // SPELL_H
