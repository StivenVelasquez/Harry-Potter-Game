#include "puntuacion.h"
#include <QFont>

//Puntuacion::Puntuacion(QGraphicsItem *parent, int x)
Puntuacion::Puntuacion(int x)
{
   puntaje=x; //Se iniciliza el puntaje en cero

   // Se dibuja el texto
   setPlainText(QString("PUNTAJE: ") + QString::number(puntaje)); // Puntaje: 0
   setDefaultTextColor(Qt::white); //Color de letra
   setFont(QFont("papirus",16)); //Tipo de letra
}

int Puntuacion::incrementar()
{
   puntaje++;//Se incrementa
   setPlainText(QString("PUNTAJE: ") + QString::number(puntaje)); // Puntaje: 1
   return puntaje;
}

int Puntuacion::getPuntaje()
{
    return puntaje;
}

