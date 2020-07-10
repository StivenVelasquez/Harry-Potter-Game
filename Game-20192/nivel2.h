#ifndef NIVEL2_H
#define NIVEL2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QtGlobal>
#include <QTimer>

#include "duthread.h"
#include "personajesnivel2.h"

namespace Ui {
class Nivel2;
}

class Nivel2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = nullptr);
    ~Nivel2();
    int PosicionRandom(int iL, int sL);

private:
    Ui::Nivel2 *ui;
    DuThread *mThread; //temporizador
    QList<PersonajesNivel2 *> mpersonajes;//personajes
    QGraphicsScene *scene;
    QTimer *timer;//Para los enemigos

public slots:
     void avanzar();
};

#endif // NIVEL2_H
