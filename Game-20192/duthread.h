#ifndef DUTHREAD_H
#define DUTHREAD_H

#include <QThread>

class DuThread: public QThread
{
    Q_OBJECT
public:
    DuThread(int milisegundos, QObject *parent=nullptr);
signals:
    void tiempofuera();
protected:
    void run() override;
private:
    int mMilisegundos;
};

#endif // DUTHREAD_H
