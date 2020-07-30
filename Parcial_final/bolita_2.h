#ifndef BOLITA_2_H
#define BOLITA_2_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>

class bolita_2 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bolita_2(QObject *parent = nullptr);

    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    float ancho,alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
public slots:
    void movimiento();
    void desaparecer();

};

#endif // BOLITA_2_H
