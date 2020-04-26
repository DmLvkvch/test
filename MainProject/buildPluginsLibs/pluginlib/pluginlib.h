#ifndef PLUGINLIB_H
#define PLUGINLIB_H

#include "../../interfaces/pluginiface.h"
#include <QDebug>
#include <QIcon>
class Pluginlib: public PluginIFace
{
public:
    Pluginlib(QString _name, QString _version, QIcon _icon);
    void test();
    // PluginIFace interface
public:
    void start();
};
#endif // PLUGINLIB_H
