#include "bolita_1.h"

bolita_1::bolita_1(QObject *parent) : QObject(parent)
{
   ancho=30;
   alto=30;

   setPos(100,posy);
   timer=new QTimer;
   timer2=new QTimer;
   timer3= new QTimer;
   connect(timer,&QTimer::timeout,this,&bolita_1::movimiento);
   timer->start(30);
   connect(timer2,&QTimer::timeout,this,&bolita_1::colisionobstaculo);
   timer2->start(30);
   connect(timer3,&QTimer::timeout,this,&bolita_1::colisionbordes);
   timer3->start(30);
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

void bolita_1::colisionobstaculo()
{
    QList<QGraphicsItem *>col=collidingItems();
    for (int i=0,n=col.size();i<n;i++){
           if(typeid (*col[i])==typeid(obstaculo)){
           v=-v;
           angulo=angulos[pos];
          }
    }
}

void bolita_1::colisionbordes()
{
    if((x>670)||(x<10)){
        v=-v;
        angulo=angulos[pos];
    }
    if(y<-555){
        delete  this;
    }
    if(y>-10){
        v=-v;
        angulo=angulos[pos];
    }
}
