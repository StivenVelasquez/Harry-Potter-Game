#ifndef HEDWIG_H
#define HEDWIG_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QDebug>
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
    // QPixmap mPixmap; //Imagen

public://Metodos
    Hedwig(float x, float y, float vx, float vy, float m, float r,QObject *parent = nullptr); //Constructor
    float CalcularAcelx(Hedwig *A);
    float CalcularAcely(Hedwig *A);
    float CalcularVelx();
    float CalcularVely();
    void ModValor();
    void  mover();
    //Metodos get
    float getposx() ;
    float getposy() ;
    float getvelx() ;
    float getvely() ;
    float getmasa() ;
    float getPosx();
    float getPosy();

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;
    float ancho;
    float alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   // QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void actualizacion();

    /*
public:
    explicit sprite(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;
    float ancho;
    float alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void actualizacion();
*/
};

#endif // HEDWIG_H
