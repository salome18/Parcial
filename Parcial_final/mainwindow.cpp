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
    //bolita1->setPos(100,100);
    escena->addItem(bolita1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

