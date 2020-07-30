#include "obstaculo.h"

obstaculo::obstaculo(QObject *parent) : QObject(parent)
{
    ancho=100;
    alto=25;
}

QRectF obstaculo::boundingRect() const
{
   return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
