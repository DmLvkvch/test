#include "logswidget.h"
#include "pluginwidget.h"
#include "settingswidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <iostream>

PluginWidget::PluginWidget(PluginIFace* plugin,QString name, QWidget* parent):QWidget(parent)
{

    this->plugin = plugin;
    this->widgetName = name;
    this->setWindowTitle(this->widgetName);
    grid = new QGridLayout();
    initIFaces();
    setLayout(grid);
    openLogsButton = new QPushButton(this);
    openLogsButton->setText("Logs");
    openSettingsButton = new QPushButton(this);
    openSettingsButton->setIcon(QIcon("D:/Proxy/alpha/icons/gears-42.jpg"));
    openSettingsButton->setMaximumSize(50, 50);
    grid->addWidget(openLogsButton, 1, 0);
    grid->addWidget(openSettingsButton, 1, 1);
    QObject::connect(openSettingsButton, SIGNAL(clicked()), this, SLOT(openSettingsButton_clicked()));
    QObject::connect(openLogsButton, SIGNAL(clicked()), this, SLOT(openLogsButton_clicked()));
}

PluginWidget::~PluginWidget()
{

}

void PluginWidget::openLogsButton_clicked()
{
    LogsWidget *logs = new LogsWidget(this->plugin->getMessageList());
    logs->show();
}

void PluginWidget::openSettingsButton_clicked()
{
    SettingsWidget *settings = new SettingsWidget(this->plugin->getConnectedIFaces());
    settings->show();
}

void PluginWidget::initIFaces()
{
    QLabel *l;
    QVBoxLayout *indicators = new QVBoxLayout;
    for(int i = 0;i<this->plugin->getConnectedIFaces().size();i++){
        QHBoxLayout *tmp = new QHBoxLayout;
        l = new QLabel;
        l->setFixedSize(10, 10);
        l->setStyleSheet( "border-radius: 5px; background-color: red;" );
        tmp->addWidget(l);
        tmp->addWidget(new QLabel(this->plugin->getConnectedIFaces().at(i)->getName()));
        indicators->addLayout(tmp);
        QLabel *msgIn = new QLabel;
        msgIn->setNum(0);
        QLabel *msgOut = new QLabel;
        msgOut->setNum(0);
        tmp->addWidget(msgIn);
        tmp->addWidget(msgOut);
    }
    grid->addLayout(indicators, 0, 0);
}

void PluginWidget::paintEvent(QPaintEvent * e)
{
    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
     p.drawRoundedRect(0,5,width()-5, height()-7,3,3);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
