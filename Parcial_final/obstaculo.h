#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QPainter>
#include <QRectF>
#include <QGraphicsItem>

class obstaculo : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit obstaculo(QObject *parent = nullptr);

    float ancho,alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:

};

#endif // OBSTACULO_H
