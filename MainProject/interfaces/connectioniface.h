#ifndef IFACE_H
#define IFACE_H

class Message;
class SettingsItem;
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
    /*!
      * \brief ����������� ������� ������ ConnectionIFace
      * �������������� ��� ��������� ������������� ����������
      */
    ConnectionIFace(QString _name, QList<SettingsItem> _settings);
    QString name() const;///<��� ����������
    Status status() const;///<������ ����������
    void setSettings(const QList<SettingsItem> & settings);///<���������� ��������� ���������
    QList<SettingsItem> & settings();///<�������� ���������
    virtual void send(const Message & message) = 0;///<��������� ���������
    virtual void receive(const Message & message) = 0;///<��������� ���������
    virtual ~ConnectionIFace();
private:
    QString _name;
    Status _status;
    QList<SettingsItem> _settings;
};

#endif // IFACE_H
