#ifndef SPELL_H
#define SPELL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <iomanip>
#include <mortifago.h>

using namespace std;

class Spell:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spell();//Constructor
    void advance(int phase);
    int PuntajeJugadorActualNivel1;
    int PuntajeJugadorActualNivel2;
    string a;

public slots:

   //Para movimiento de la llama del hechizo
    void moveHechizo();

};

class SpellMortifago:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpellMortifago();//Constructor
    void advance(int phase);
    int PuntajeJugadorActual;

public slots:

   //Para movimiento de la llama del hechizo
    void moveHechizo();

};

#endif // SPELL_H
