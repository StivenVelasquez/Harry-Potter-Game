#include "duthread.h"

DuThread::DuThread(int miliseconds, QObject *parent) //Definicion del contructor de la clase
    :QThread(parent)
{
    mMiliseconds=miliseconds;
}

void DuThread::run()
{
    while(true){
        QThread::msleep(mMiliseconds);//Cada mMilisegundos se emite la señal timeOut()
        emit timeOut();
    }
}
