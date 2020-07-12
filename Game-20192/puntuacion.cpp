#include "puntuacion.h"
#include <QFont>

Puntuacion::Puntuacion(QGraphicsItem *parent)
{
   puntaje=0;

   // draw the text
   setPlainText(QString("PUNTAJE: ") + QString::number(puntaje)); // Score: 0
   setDefaultTextColor(Qt::black);
   setFont(QFont("papirus",16));
}

void Puntuacion::incrementar()
{
   puntaje++;
   setPlainText(QString("PUNTAJE: ") + QString::number(puntaje)); // Score: 1
}

int Puntuacion::getPuntaje()
{
    return puntaje;
}

