#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "iface.h"
#include "pluginwidget.h"

#include <QWidget>



class SettingsWidget: public QWidget
{
    Q_OBJECT
public:
    SettingsWidget(QList<IFace*> & ifaces);
    void paintEvent(QPaintEvent * e);
private:
    void init();
    QList<IFace*> ifaces;
    PluginWidget* plugin;
};

#endif // SETTINGSWIDGET_H
