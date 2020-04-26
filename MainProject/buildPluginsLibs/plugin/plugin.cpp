#include "plugin.h"
#include "pluginlib.h"

PluginIFace *create(){
    PluginIFace* dllPlugin = new Pluginlib("pluginlib", "alpha", QIcon());
    qDebug()<<"creating plugin";
    return dllPlugin;
}
