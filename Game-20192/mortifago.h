#ifndef MORTIFAGO_H
#define MORTIFAGO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <spell.h>

class Mortifago:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Mortifago(QObject *parent = nullptr);//Constructor
    QRectF boundingRect() const; //Limites del rectangulo donde esta el sprite
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //Para pintar la imagen

public slots:
    void move(); //Mover el mortifago
    void actualizar(); //Actualizar imagenes
    void crearHechizos(); //Crear hechizos

private:
    QTimer *timerImagenes;  //Timer para actualizar imagenes
    QPixmap *pixmap; //Para el sprite
    float filas,columnas; //Filas y columnas en la imagen principal
    float ancho;//ancho del sprite
    float alto;//Alto del sprite
    int random_Mortifago = rand() % 5; //Para que sean 5 mortifagos diferentes
};

#endif // MORTIFAGO_H
