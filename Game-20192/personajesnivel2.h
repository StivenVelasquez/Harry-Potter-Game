#ifndef PERSONAJESNIVEL2_H
#define PERSONAJESNIVEL2_H

#include <QGraphicsItem>
#include <QPixmap>

class PersonajesNivel2: public QGraphicsItem //Heredamos de esta clase
{
public:
    PersonajesNivel2(const QString &filename, QGraphicsItem *parent=nullptr);//Recibimos

    //Setters
    void set_x(int x)
    {
        mX=x;
    }

    void set_y(int y)
    {
        mY=y;
    }

    void set_vx(int vx)
    {
      mVx=vx;
    }

    void set_vy(int vy)
    {
        mVy=vy;
    }

    //getters
    int get_x() const
    {
        return mX;
    }

    int get_y() const
    {
        return mY;
    }

    int get_vx() const
    {
        return mVx;
    }

    int get_vy() const
    {
        return mVy;
    }

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
private:
    QPixmap mPixmap; //Imagen
    int mX,mY;
    int mVx,mVy;
};

#endif // PERSONAJESNIVEL2_H
