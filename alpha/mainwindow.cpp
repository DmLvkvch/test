#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pluginwidget.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget * widget = new QWidget;
    QVBoxLayout * layout = new QVBoxLayout;
    PluginWidget * w = new PluginWidget("SCIF DIAG1",this);
    PluginWidget * w1 = new PluginWidget("SCIF DIAG2",this);
    PluginWidget * w2 = new PluginWidget("SCIF DIAG3",this);
    PluginWidget * w3 = new PluginWidget("SCIF DIAG4",this);
    PluginWidget * w4 = new PluginWidget("SCIF DIAG5",this);
    PluginWidget * w5 = new PluginWidget("SCIF DIAG6",this);
    layout->addWidget(w);
    layout->addWidget(w1);
    layout->addWidget(w2);
    layout->addWidget(w3);
    layout->addWidget(w4);
    layout->addWidget(w5);
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

