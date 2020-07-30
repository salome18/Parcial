#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

#include "bolita_1.h"
#include "bolita_2.h"
#include "obstaculo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *escena;
    QTimer *timer= new QTimer;

    bolita_1 *bolita1=new bolita_1;
    //bolita_2 *bolita2= new bolita_2;
    obstaculo *_obstaculo=new obstaculo;

    void keyPressEvent(QKeyEvent *evento);

private slots:
  void generarobstaculos();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
