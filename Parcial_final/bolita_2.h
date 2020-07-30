#ifndef BOLITA_2_H
#define BOLITA_2_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class bolita_2 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bolita_2(QObject *parent = nullptr);


    float ancho,alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

};

#endif // BOLITA_2_H
