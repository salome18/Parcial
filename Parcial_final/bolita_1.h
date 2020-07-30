#ifndef BOLITA_1_H
#define BOLITA_1_H

#include <QObject>
#include <QPainter>
#include <QRectF>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <math.h>


#define dt 0.1

class bolita_1 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bolita_1(QObject *parent = nullptr);

    QTimer *timer;
    double angulos[3]={40,90,210};
    int pos = rand() % 3;
    double v=64,vx,vy,x=100,y=-250,a=9.8,yd,angulo=angulos[pos];

    float ancho,alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:
public slots:
    void movimiento();

};

#endif // BOLITA_1_H
