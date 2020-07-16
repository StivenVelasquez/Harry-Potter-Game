#ifndef SPELL_H
#define SPELL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <iomanip>

using namespace std;

class Spell:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spell();//Constructor
    void advance(int phase);
    int PuntajeJugadorActual;

public slots:

   //Para movimiento de la llama del hechizo
    void move();

};

#endif // SPELL_H
