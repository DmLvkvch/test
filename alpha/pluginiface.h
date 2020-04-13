#ifndef PLUGINIFACE_H
#define PLUGINIFACE_H

#include "connectioniface.h"
#include "settingsitem.h"

#include <QList>
#include <QString>
#include "message.h"

/*!
 *  class describing plugin
 */
class PluginIFace
{
public:
    /*!
      * \brief ����������� ������� ������ PluginIFace
      * �������������� ��� ��������� �������
      */
    PluginIFace();
    QString name() const;///<�������� �������
    QList<QSharedPointer<ConnectionIFace>> & connectedIFaces() ;///<������ ����������� �����������
    QString version() const;///<������ �������
    QList<Message> & messageList();///<������ ���������
    QList<SettingsItem> & settings() const;///<������ ��������
    void setSettings(const QList<SettingsItem> & settings);///<���������� ����� ������ ��������
    QString id();///<id �������
    virtual void start() = 0;///<������ �������
    virtual QIcon icon() = 0;///<������ �������
    virtual ~PluginIFace();
    void addConnectionIFace(ConnectionIFace & iface);
protected:
    QString _name;
    QList<QSharedPointer<ConnectionIFace>> _connectedIFaces;
    QList<Message> _messages;
    QList<SettingsItem> _settings;
signals:
    void connectedIFace(QSharedPointer<ConnectionIFace> iface); ///<����������� � ����������� ������ ����������
    void disconnectedIFace(QSharedPointer<ConnectionIFace> iface); ///<����������� �� ���������� ����������
    void recieved(Message message);///<����������� � ��������� ���������
    void sended(Message message);///<����������� �� �������� ���������
};

#endif // PLUGINIFACE_H
