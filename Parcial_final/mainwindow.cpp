#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena= new QGraphicsScene;
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,600,600);
    escena->setBackgroundBrush(Qt::black);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(timer,&QTimer::timeout,this,&MainWindow::generarobstaculos);
    timer->start(4500);
    connect(timer2,&QTimer::timeout,this,&MainWindow::generarbolitas1);
    timer2->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_Space){
        bolita_2 *bolita2= new bolita_2;
        int posx = rand() % 600;
        int posy=rand()% 400;
        bolita2->setPos(posx,posy);
        escena->addItem(bolita2);
    }
}

void MainWindow::generarobstaculos()
{
    int posx = rand() % 600;
    int posy=rand()% 580;
    QList<QGraphicsItem*>obst;
    obst.push_back(_obstaculo);
    obst.last()->setPos(posx,posy);
    escena->addItem(obst.last());
}

void MainWindow::generarbolitas1()
{
    bolita_1 *bala= new bolita_1;
    QList<QGraphicsItem*>bolas;
    bolas.push_back(bala);
    escena->addItem(bolas.last());
}

