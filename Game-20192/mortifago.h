#ifndef MORTIFAGO_H
#define MORTIFAGO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Mortifago:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Mortifago(QObject *parent = nullptr);
    QTimer *timerImagenes;
    QPixmap *pixmap;

    float filas,columnas;
    float ancho;
    float alto;

    int random_Mortifago = rand() % 5;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void move();
    void actualizar();

};

#endif // MORTIFAGO_H
/*
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class sprite : public QObject,public QGraphicsItem
{
    Q_OBJECT
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

};

*/
