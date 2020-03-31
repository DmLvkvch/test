#include "logswidget.h"
#include "pluginwidget.h"
#include "settingswidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <iostream>
PluginWidget::PluginWidget(QString name, QWidget* parent):QWidget(parent)
{
    this->widgetName = name;
    this->setWindowTitle(this->widgetName);
    this->parentWidget = parent;
    QGridLayout *grid = new QGridLayout();
    setLayout(grid);
    this->getConnectedIFaces().push_back(new IFace());
    this->getConnectedIFaces().push_back(new IFace());
    this->getConnectedIFaces().push_back(new IFace());
    this->getConnectedIFaces().push_back(new IFace());
    this->getConnectedIFaces().push_back(new IFace());
    openLogsButton = new QPushButton(this);
    openLogsButton->setText("Logs");
    openSettingsButton = new QPushButton(this);
    openSettingsButton->setIcon(QIcon("D:/Proxy/alpha/icons/gears-42.jpg"));
    openSettingsButton->setMaximumSize(50, 50);
    QPushButton* new_window = new QPushButton();
    new_window->setText("open in new window");
    grid->addWidget(openLogsButton, 0, 0);
    grid->addWidget(openSettingsButton, 1, 0);
    grid->addWidget(new_window, 2, 0);
    QObject::connect(new_window, SIGNAL(clicked()), this, SLOT(open_in_new_window()));
    QObject::connect(openSettingsButton, SIGNAL(clicked()), this, SLOT(openSettingsButton_clicked()));
    QObject::connect(openLogsButton, SIGNAL(clicked()), this, SLOT(openLogsButton_clicked()));
}

PluginWidget::~PluginWidget(){

}

QList<IFace*>& PluginWidget::getConnectedIFaces(){
    return this->connectedIFaces;
}

void PluginWidget::open_in_new_window(){
    setParent(nullptr);
    this->show();
}

void PluginWidget::openLogsButton_clicked(){
    LogsWidget *logs = new LogsWidget(this->getConnectedIFaces());
    logs->show();
}

void PluginWidget::openSettingsButton_clicked(){
    SettingsWidget *settings = new SettingsWidget(this->getConnectedIFaces());
    settings->show();
}

void PluginWidget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.drawRoundedRect(0,5,width()-5, height()-7,3,3);

    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
