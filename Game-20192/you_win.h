#ifndef YOU_WIN_H
#define YOU_WIN_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class You_Win;
}

class You_Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit You_Win(QWidget *parent = nullptr);
    ~You_Win();

private:
    Ui::You_Win *ui;
    QGraphicsScene *scene;//Para crear la escena
};

#endif // YOU_WIN_H
