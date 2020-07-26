#ifndef SPELL_H
#define SPELL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <mortifago.h>

using namespace std;

class Spell:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spell();//Constructor
    void actualizar(); //Posiciones

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
