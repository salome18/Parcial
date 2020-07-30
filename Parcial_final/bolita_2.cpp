#include "bolita_2.h"

bolita_2::bolita_2(QObject *parent) : QObject(parent)
{
    ancho=30;
    alto=30;
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
