#ifndef MALFOI_H
#define MALFOI_H

#include <hermione.h>


class malfoi:public Hermione
{
public:
    malfoi();
    float getpos_x();
    float getpos_y();
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//Para pinta el pixmap
private:
    QPixmap m_P2;
    float posx;
    float posy;
};

#endif // MALFOI_H
