#ifndef BOLITA_2_H
#define BOLITA_2_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include "obstaculo.h"

class bolita_2 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bolita_2(QObject *parent = nullptr);

    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    float ancho=30,alto=30;
    int ejecucionesrebote=0;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
public slots:
    void movimiento();
    void desaparecer();
    void colisionobstaculo();
    void disminuirtam();
    void rebote();

};

#endif // BOLITA_2_H
