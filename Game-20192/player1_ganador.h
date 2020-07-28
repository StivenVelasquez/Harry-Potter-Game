#ifndef PLAYER1_GANADOR_H
#define PLAYER1_GANADOR_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class Player1_Ganador;
}

class Player1_Ganador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Player1_Ganador(QWidget *parent = nullptr);
    ~Player1_Ganador();

private:
    Ui::Player1_Ganador *ui;
    QGraphicsScene *scene; //Se instancia un objeto tipo QGraphicsScene
};

#endif // PLAYER1_GANADOR_H
