#ifndef PLAYER2_GANADOR_H
#define PLAYER2_GANADOR_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class Player2_Ganador;
}

class Player2_Ganador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Player2_Ganador(QWidget *parent = nullptr);
    ~Player2_Ganador();

private:
    Ui::Player2_Ganador *ui;
    QGraphicsScene *scene; //Se instancia un objeto tipo QGraphicsScene
};

#endif // PLAYER2_GANADOR_H
