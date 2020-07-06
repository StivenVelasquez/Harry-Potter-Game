#include "duthread.h"

DuThread::DuThread(int milisegundos, QObject *parent) //Definicion del contructor de la clase
    :QThread(parent)
{
    mMilisegundos=milisegundos;
}

void DuThread::run()
{
    while(true){
        QThread::msleep(mMilisegundos);//Cada mMilisegundos se emite la señal tiempofuera()
        emit tiempofuera();
    }
}
