#ifndef IFACE_H
#define IFACE_H

#include "settings.h"
#include <QIcon>
#include <QString>

class IFace
{
public:
    IFace();
    QString getName() const;
    void status();
    void event();
    void send();
    void receive();
    QList<Settings> getSettings();
    QList<Settings> setSettings();
    QIcon icon() const;
    QString version() const;
private:
    QString name;
    QList<Settings>* settings;
};

#endif // IFACE_H
