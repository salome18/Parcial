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
    //bolita2->setPos(100,100);
    //escena->addItem(_obstaculo);

    connect(timer,&QTimer::timeout,this,&MainWindow::generarobstaculos);
    timer->start(3000);
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
    int posy=rand()% 600;
    QList<QGraphicsItem*>obst;
    obst.push_back(_obstaculo);
    obst.last()->setPos(posx,posy);
    escena->addItem(obst.last());
}

