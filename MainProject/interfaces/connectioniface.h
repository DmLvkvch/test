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
      * \brief Конструктор объекта класса ConnectionIFace
      * инициализирует все настройки подключенного интерфейса
      */
    ConnectionIFace(QString _name, QList<SettingsItem> _settings);
    QString name() const;///<имя интерфейса
    Status status() const;///<статус интерфейса
    void setSettings(const QList<SettingsItem> & settings);///<установить настройки интерфеса
    QList<SettingsItem> & settings();///<получить настройки
    virtual void send(const Message & message) = 0;///<отправить сообщение
    virtual void receive(const Message & message) = 0;///<получение сообщения
    virtual ~ConnectionIFace();
private:
    QString _name;
    Status _status;
    QList<SettingsItem> _settings;
};

#endif // IFACE_H
