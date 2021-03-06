#include "logswidget.h"
#include "pluginwidget.h"
#include "settingswidget.h"
#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "../../interfaces/pluginiface.h"
PluginWidget::PluginWidget(PluginIFace & plugin, QString name, QWidget* parent): _plugin(plugin), QWidget(parent)
{
    _grid = QSharedPointer<QGridLayout>(new QGridLayout);
    this->_widgetName = name;
    this->setWindowTitle(this->_widgetName);
    setLayout(_grid.get());
    _openLogsButton = QSharedPointer<QPushButton>(new QPushButton());
    _openLogsButton->setText("Logs");
    _openSettingsButton = QSharedPointer<QPushButton>(new QPushButton());
    _openSettingsButton->setText("Settings");
    _grid->addWidget(_openLogsButton.get(), 1, 0);
    _grid->addWidget(_openSettingsButton.get(), 1, 1);
    this->_settings = QSharedPointer<SettingsWidget>(new SettingsWidget(this->_plugin.connectedIFaces()));
    QObject::connect(_openSettingsButton.get(), SIGNAL(clicked()), this, SLOT(handleOpenSettings()));
    QObject::connect(_openLogsButton.get(), SIGNAL(clicked()), this, SLOT(handleOpenLogs()));
}

PluginWidget::~PluginWidget()
{

}

void PluginWidget::handleOpenLogs()
{
    LogsWidget *logs = new LogsWidget(new Logs(this->_plugin.messageList()));
    logs->show();
}

void PluginWidget::handleOpenSettings()
{
    this->_settings->show();

}

void PluginWidget::initIFaces()
{
    foreach(auto &iface, this->_plugin.connectedIFaces())
    {

    }
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
