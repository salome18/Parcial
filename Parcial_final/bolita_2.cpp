#include "bolita_2.h"

bolita_2::bolita_2(QObject *parent) : QObject(parent)
{
    ancho=30;
    alto=30;
    timer=new QTimer;
    timer2=new QTimer;
    connect(timer,&QTimer::timeout,this,&bolita_2::movimiento);
    connect(timer2,&QTimer::timeout,this,&bolita_2::desaparecer);
    timer->start(100);
    timer2->start(500);
}

QRectF bolita_2::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void bolita_2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void bolita_2::movimiento()
{
    setPos(x(),y()+10);
}

void bolita_2::desaparecer()
{
   if (this->y()>=530) delete this;
}
