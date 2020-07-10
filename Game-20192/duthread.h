#ifndef DUTHREAD_H
#define DUTHREAD_H

#include <QThread>

class DuThread: public QThread
{
    Q_OBJECT
public:
    DuThread(int miliseconds, QObject *parent=nullptr);
signals:
    void timeOut();
protected:
    void run() override;
private:
    int mMiliseconds;

};

#endif // DUTHREAD_H
