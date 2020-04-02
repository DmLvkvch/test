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
    widgetsLayout = new QGridLayout();
    listOfPlugins = new QList<PluginWidget*>();
    listOfPlugins->push_back(new PluginWidget("SCIF DIAG1",this));
    listOfPlugins->push_back(new PluginWidget("SCIF DIAG2",this));
    listOfPlugins->push_back(new PluginWidget("SCIF DIAG3",this));
    listOfPlugins->push_back(new PluginWidget("SCIF DIAG4",this));
    listOfPlugins->push_back(new PluginWidget("SCIF DIAG5",this));
    listOfPlugins->push_back(new PluginWidget("SCIF DIAG6",this));
    int k = 0;
    for(int i = 0;i<2;i++){
        for(int j = 0;j<3;j++){
            widgetsLayout->addWidget(listOfPlugins->at(k), i, j);
            k++;
        }
    }
    widget->setLayout(widgetsLayout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

