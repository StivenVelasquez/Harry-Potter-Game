#ifndef SPELL_H
#define SPELL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <mortifago.h>

class Spell:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spell();//Constructor
    void actualizar(); //Actualizar Posiciones

public slots:
   //Para movimiento de la llama del hechizo
    void moveHechizo();
};

class SpellMortifago:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpellMortifago();//Constructor   
    void actualizar(); //Actualizar posiciones

public slots:
   //Para movimiento de la llama del hechizo
    void moveHechizo();
};

#endif // SPELL_H
