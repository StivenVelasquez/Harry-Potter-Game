#ifndef NIVEL2_H
#define NIVEL2_H

#include <QMainWindow>

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

private:
    Ui::Nivel2 *ui;
    DuThread *mThread; //temporizador
    QList<PersonajesNivel2 *> mpersonajes;//personajes
};

#endif // NIVEL2_H
