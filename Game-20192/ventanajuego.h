#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class VentanaJuego; }
QT_END_NAMESPACE

class VentanaJuego : public QMainWindow
{
    Q_OBJECT

public:
    VentanaJuego(QWidget *parent = nullptr);
    ~VentanaJuego();

private:
    Ui::VentanaJuego *ui;
};
#endif // VENTANAJUEGO_H
