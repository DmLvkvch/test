#ifndef IFACE_H
#define IFACE_H

#include "message.h"
#include "settingsitem.h"
#include <QIcon>
#include <QString>

/*!
 *  class describing the connected interface
 */
class ConnectionIFace
{
public:
    enum class Status{ ///status of connection
        Unknown, Connected, Disconnected
    };
    ConnectionIFace();
    ConnectionIFace(QString name);
    QString name() const;///<��� ����������
    Status status() const;///<������ ����������
    void setSettings(const QList<SettingsItem> & settings);///<���������� ��������� ���������
    QList<SettingsItem> & settings();
    virtual void send(const Message & message) = 0;///<��������� ���������
    virtual void receive(const Message & message) = 0;///<��������� ���������
    virtual ~ConnectionIFace();
protected:
    QString _name;
    Status _status;
    QList<SettingsItem> _settings;
};

#endif // IFACE_H
