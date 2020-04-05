#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pluginwidget.h"
#include "mainwindowsettings.h"

#include <QComboBox>
#include <QFileDialog>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget * widget = new QWidget;
    gridViewByRow = new QComboBox();
    gridViewByColumn = new QComboBox();
    widgetsLayout = new QGridLayout();
    listOfPlugins = new QList<PluginWidget*>();
    listOfPlugins->push_back(new PluginWidget(new PluginIFace,"SCIF DIAG1",this));
    listOfPlugins->push_back(new PluginWidget(new PluginIFace,"SCIF DIAG2",this));
    listOfPlugins->push_back(new PluginWidget(new PluginIFace,"SCIF DIAG3",this));
    listOfPlugins->push_back(new PluginWidget(new PluginIFace,"SCIF DIAG4",this));
    listOfPlugins->push_back(new PluginWidget(new PluginIFace,"SCIF DIAG5",this));
    listOfPlugins->push_back(new PluginWidget(new PluginIFace,"SCIF DIAG6",this));
    int k = 0;
    for(int i = 0;i<2;i++){
        for(int j = 0;j<3;j++){
            widgetsLayout->addWidget(listOfPlugins->at(k), i, j);
            k++;
        }
    }
    gridViewByColumn->addItem(QString::number(listOfPlugins->size()));
    widget->setLayout(widgetsLayout);
    QMenuBar* mnuBar = new QMenuBar;
        QMenu*   pmnu   = new QMenu("&Menu");
        pmnu->addSeparator();
        pmnu->addAction("&Settings",
                            this,
                            SLOT(settings()),
                            Qt::CTRL + Qt::Key_Q
                           );

    pmnu->addSeparator();
    pmnu->addAction("&Load new plugin", this, SLOT(load_new_plugin()));
    mnuBar->addMenu(pmnu);
    setMenuBar(mnuBar);
    setCentralWidget(widget);
}

int MainWindow::getNumOfAvailableRows(){

}

int MainWindow::getNumOfAvailableColumns(){

}

void MainWindow::settings(){
    MainWindowSettings* settings = new MainWindowSettings();
    settings->show();
}

void MainWindow::load_new_plugin(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("File manager"), QString(),
                    tr("Text Files (*.txt)"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

