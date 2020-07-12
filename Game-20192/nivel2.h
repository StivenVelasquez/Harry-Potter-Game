#ifndef NIVEL2_H
#define NIVEL2_H

#include <QMainWindow>

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
};

#endif // NIVEL2_H
