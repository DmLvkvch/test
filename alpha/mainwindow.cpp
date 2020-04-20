#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pluginwidget.h"
#include "mainwindowsettings.h"
#include "settingsitem.h"

#include <QComboBox>
#include <QFileDialog>
#include <QLibrary>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _widget = QSharedPointer<QWidget>(new QWidget);
    _widgetsLayout = QSharedPointer<QGridLayout>(new QGridLayout);
    _widget->setLayout(_widgetsLayout.get());
    _mnuBar  = QSharedPointer<QMenuBar>(new QMenuBar);
    _pmnu = QSharedPointer<QMenu>(new QMenu());
    _pmnu->setTitle("Menu");
    _pmnu->setVisible(true);
    _pmnu->addSeparator();
    _pmnu->addAction("&Settings",this, SLOT(handleSettings()),Qt::CTRL + Qt::Key_Q);
    _pmnu->addSeparator();
    _pmnu->addAction("&Load new plugin", this, SLOT(handleLoadNewPlugin()));
    _mnuBar->addMenu(_pmnu.get());
    setMenuBar(_mnuBar.get());
    setCentralWidget(_widget.get());
    _settings = QSharedPointer<MainWindowSettings>(new MainWindowSettings(this));
    _widget->setLayout(_widgetsLayout.get());
}

void MainWindow::handleSettings()
{
    _settings->show();
}

void MainWindow::handleLoadNewPlugin()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("File manager"), QString(),
                    tr("Files (*.dll *.so)"));
    QLibrary lib;
    QString path = fileName;
    if(QLibrary::isLibrary(path)) {
        lib.setFileName(path);
        lib.load();
        if(lib.isLoaded())
            qDebug() << "Ok\n";
        else
            qDebug() << "Error " << lib.errorString() << "\n";
    } else
        qDebug() << "Not a library\n";

    qDebug()<<lib.fileName();
    typedef PluginIFace *(*createPlugin)();
    createPlugin cwf = (createPlugin)lib.resolve("create");
        if (cwf) {
            PluginIFace *plugin = cwf();
            if (plugin) {
               PluginWidget* pw = new PluginWidget(*plugin, QString("21312"), this);
               _widgetsLayout->addWidget(pw);
            }
        }
        else
        {
            qDebug() << "Could not show widget from the loaded library";
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

