#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <iomanip>
#include <QGraphicsScene>

#include "modojuego.h"

using namespace std;

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::Login *ui;
    QGraphicsScene *scene;

};

#endif // LOGIN_H
