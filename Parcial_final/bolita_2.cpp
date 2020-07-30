#include "bolita_2.h"

bolita_2::bolita_2(QObject *parent) : QObject(parent)
{
    timer=new QTimer;
    timer2=new QTimer;
    timer3=new QTimer;
    timer4= new QTimer;
    timer5=new QTimer;
    connect(timer,&QTimer::timeout,this,&bolita_2::movimiento);
    connect(timer2,&QTimer::timeout,this,&bolita_2::desaparecer);
    connect(timer3,&QTimer::timeout,this,&bolita_2::colisionobstaculo);
    connect(timer4,&QTimer::timeout,this,&bolita_2::disminuirtam);
    connect(timer5,&QTimer::timeout,this,&bolita_2::rebote);
    timer->start(100);
    timer2->start(100);
    timer3->start(100);
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

void bolita_2::colisionobstaculo()
{
    QList<QGraphicsItem *>col=collidingItems();
    for (int i=0,n=col.size();i<n;i++){
           if(typeid (*col[i])==typeid(obstaculo)){
            timer->stop();
            timer5->start(100);
            timer4->start(100);
          }
    }

}

void bolita_2::disminuirtam()
{
    ancho=ancho-5;
    alto=alto-5;
    timer4->stop();
}

void bolita_2::rebote()
{
    ejecucionesrebote++;
    setPos(x(),y()-10);
    if(ejecucionesrebote==15){
        timer5->stop();
        timer->start(100);
        ejecucionesrebote=0;
    }


}
