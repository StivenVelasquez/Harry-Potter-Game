#ifndef HEDWIG_H
#define HEDWIG_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QPixmap>

#define G 1
#define dtt  1
#define es 0.05

class Hedwig : public QObject,public QGraphicsItem
{
    Q_OBJECT
private: //Atributos
    float Pposx,Pposy,Pvelx,Pvely,Pmasa,Pradio,Acelx,Acely;
    float Posx,Posy,Velx,Vely;

public://Metodos
    Hedwig(float x, float y, float vx, float vy, float m, float r,QObject *parent = nullptr); //Constructor

    void ModValor();
    void  mover(Hedwig *A);

    //Para el sprite
    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas; //Filas y columnas de la imagen original
    float ancho;//Ancho de cada imagen
    float alto;//Alto de cada imagen
    QRectF boundingRect() const;//Limites del rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//para pintarlo

public slots:
    void actualizacion();//Actualizar de imagenes

};

#endif // HEDWIG_H
