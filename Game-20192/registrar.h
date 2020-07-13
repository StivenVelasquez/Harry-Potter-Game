#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QMainWindow>
#include <QDebug>
#include <fstream>
#include <iostream>
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
    explicit Registrar(QWidget *parent = nullptr);
    ~Registrar();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::Registrar *ui;
    QGraphicsScene *scene;
};

#endif // REGISTRAR_H
