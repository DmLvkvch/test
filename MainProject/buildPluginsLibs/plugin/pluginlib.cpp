#include "pluginlib.h"
#include <iostream>

Pluginlib::Pluginlib(QString _name, QString _version, QIcon _icon):PluginIFace(_name, _version, _icon)
{

}

void Pluginlib::test()
{
    std::cout<<"Hello!";
    qDebug()<<"Hello from lib";
}

void Pluginlib::start()
{
    std::cout<<"start!";
    qDebug()<<"start from lib";
}


