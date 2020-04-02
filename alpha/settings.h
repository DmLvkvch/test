#ifndef SETTINGS_H
#define SETTINGS_H

#include "EnumType.h"

#include <QString>
class Settings
{
public:
    Settings();
    QString getIp();
    int getPort();
    //QString getName();
private:
    QString ip;
    int port;
    QString name;
};

#endif // SETTINGS_H
