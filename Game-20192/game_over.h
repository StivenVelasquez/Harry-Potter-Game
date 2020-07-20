#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class Game_Over;
}

class Game_Over : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game_Over(QWidget *parent = nullptr);
    ~Game_Over();

private:
    Ui::Game_Over *ui;
    QGraphicsScene *scene;//Para crear la escena

};

#endif // GAME_OVER_H
