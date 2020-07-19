#ifndef NIVEL2_H
#define NIVEL2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "mortifago.h"

namespace Ui {
class Nivel2;
}

class Nivel2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = nullptr);
    ~Nivel2();
public slots:
    void spawn();

private:
    Ui::Nivel2 *ui;
     QGraphicsScene *scene;//Para crear la escena

     QTimer *timer;//Crea el tiempo para los enemigos

};

#endif // NIVEL2_H
