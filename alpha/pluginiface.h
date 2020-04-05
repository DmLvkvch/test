#ifndef PLUGINIFACE_H
#define PLUGINIFACE_H

#include "iface.h"
#include "settings.h"

#include <QList>
#include <QString>
#include "message.h"


class PluginIFace
{
public:
    PluginIFace();
    QString name;
    QList<IFace*> & getConnectedIFaces();
    QString getVersion();
    void reset();
    QList<Message> & getMessageList();
    QList<Settings> & getSettings() const;
    void setSettings(QList<Settings> & settings);
};

#endif // PLUGINIFACE_H
