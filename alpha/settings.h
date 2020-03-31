#ifndef SETTINGS_H
#define SETTINGS_H

#include "EnumType.h"

#include <QString>
class Settings
{
public:
    Settings();
    QString getIp();
    QString getPort();
    //QString getName();
private:
    QString ip;
    QString port;
    QString name;
};

#endif // SETTINGS_H
