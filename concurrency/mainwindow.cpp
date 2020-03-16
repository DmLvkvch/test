#include "Factorial.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include "thread.h"
#include <QProgressBar>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        int y = 25;
    for(int i = 0;i<10;i++){
        QLabel* label = new QLabel(this);
        lables.push_back(label);
        QProgressBar* bar = new QProgressBar(this);
        processes.push_back(bar);
        Thread *thread = new Thread(bar, label);
        threads.push_back(thread);
        delete thread;
        delete label;
        QObject::connect(thread, SIGNAL(progress(QProgressBar*, int)), this, SLOT(onProgress(QProgressBar*, int)));
        QObject::connect(thread, SIGNAL(running(QLabel*)), this, SLOT(onRunning(QLabel*)));
        QObject::connect(thread, SIGNAL(finished(QLabel*)), this, SLOT(onFinish(QLabel*)));
        lables.at(i)->setText("Waiting");
        lables.at(i)->setGeometry(50, y, 50, 25);
        lables.at(i)->setVisible(true);
        processes.at(i)->setVisible(true);
        processes.at(i)->setGeometry(150, y, 100, 25);
        processes.at(i)->setMinimum(0);
        processes.at(i)->setMaximum(10000);
        y+=25;
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    for (int i = 0;i<10;i++) {
        threads.at(i)->start();
    }
}

void MainWindow::onRunning(QLabel * label){
    label->setText("processing");
}

void MainWindow::onFinish(QLabel * label){
    label->setText("Finished");
}

void MainWindow::onProgress(QProgressBar* process, int j )
{
     process->setValue(j);
}
