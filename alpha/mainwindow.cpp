#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pluginwidget.h"
#include "mainwindowsettings.h"
#include "plrealize.h"
#include "ifacerealize.h"

#include <QComboBox>
#include <QFileDialog>
#include <QVBoxLayout>

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
    _settings = QSharedPointer<MainWindowSettings>(new MainWindowSettings);

    PluginIFace* pl = new plrealize();

    QList<SettingsItem> sets;
    SettingsItem s;
    sets.push_back(s);
    sets.push_back(s);
    sets.push_back(s);
    sets.push_back(s);
    ConnectionIFace *c = new ifacerealize;
    c->setSettings(sets);
    pl->addConnectionIFace(*c);
    PluginWidget* pw = new PluginWidget(*pl, QString("21312"), this);
    _widget->setLayout(_widgetsLayout.get());
    _widgetsLayout->addWidget(pw, 0, 0);
    _widgetsLayout->addWidget(new PluginWidget(*pl, "2131244444", this), 0, 1);
}

void MainWindow::handleSettings()
{
    _settings->show();
}

void MainWindow::handleLoadNewPlugin()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("File manager"), QString(),
                    tr("Text Files (*.txt)"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

