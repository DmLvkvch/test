#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <windows.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "graph.h"
#include "vertex.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("ground");
    ui->comboBox->addItem("water");
    ui->comboBox->addItem("air");
    ui->comboBox_2->addItem("yes");
    ui->comboBox_2->addItem("no");
}

void MainWindow:: InitCity(){
    graph* g;
    Vertex v;
    v.addCity(ui->lineEdit->text(), ui->comboBox->currentText(), ui->comboBox_2->currentText());

}

MainWindow::~MainWindow()
{
    delete ui;
}

