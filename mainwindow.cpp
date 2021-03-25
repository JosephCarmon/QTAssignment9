#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->centralwidget->setStyleSheet("Background-color: rgb(255,0,0);");
    ui->statusbar->setStyleSheet("background-color: rgb(25, 255, 155);");
    ui->statusbar->showMessage("Hello",10000);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),this, SLOT(MyTimerSlot()));

    timer->start(1000);
    ui->lcdNumber->setPalette(QColor(0,0,255));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MyTimerSlot()
{

    int iValue = ui->lcdNumber->intValue();
    iValue++;
    ui->lcdNumber->display(iValue);

}

