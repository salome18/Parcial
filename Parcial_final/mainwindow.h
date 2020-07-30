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
    QTimer *timer2= new QTimer;

    bolita_1 *bolita1=new bolita_1;
    obstaculo *_obstaculo=new obstaculo;

    void keyPressEvent(QKeyEvent *evento);

private slots:
  void generarobstaculos();
  void generarbolitas1();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
