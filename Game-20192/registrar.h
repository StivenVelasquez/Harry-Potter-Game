#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QMainWindow>
#include <QDebug>
#include <fstream>
#include <QMessageBox>
#include <iomanip>
#include <QGraphicsScene>

using namespace std;

namespace Ui {
class Registrar;
}

class Registrar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registrar(QWidget *parent = nullptr); //Constructor
    ~Registrar();//Destructor

private slots:
    void on_pushButton_clicked(); //Para ingresr datos a fichero

private:
    Ui::Registrar *ui;
    QGraphicsScene *scene; //Se instancia clase
};

#endif // REGISTRAR_H
