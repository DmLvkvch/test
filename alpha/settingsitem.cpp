#include "settingsitem.h"


SettingsItem::SettingsItem()
{

}

SettingsItem::SettingsItem(QString name,QVariant value,  Type type, double min, double max, double step):
    name(name),value(value), type(type), min(min), max(max), step(step)
{

}

