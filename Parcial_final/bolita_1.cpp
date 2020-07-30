#include "bolita_1.h"

bolita_1::bolita_1(QObject *parent) : QObject(parent)
{
   ancho=30;
   alto=30;

   timer=new QTimer;
   connect(timer,&QTimer::timeout,this,&bolita_1::movimiento);
   timer->start(50);
}

QRectF bolita_1::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void bolita_1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->setBrush(Qt::green);
   painter->drawEllipse(boundingRect());

}

void bolita_1::movimiento()
{
    setPos(x,-y);
    vx=v*cos(angulo);
    vy=v*sin(angulo)-a*dt;
    angulo=atan2(vy,vx);
    v= sqrt(vx*vx+ vy*vy);
    x-=vx*dt;
    y+=vy*dt-(a/2)*dt*dt;
}
