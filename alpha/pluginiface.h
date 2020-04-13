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
      * \brief  онструктор объекта класса PluginIFace
      * инициализирует все настройки плагина
      */
    PluginIFace();
    QString name() const;///<Ќазвание плагина
    QList<QSharedPointer<ConnectionIFace>> & connectedIFaces() ;///<список подклченных интерфейсов
    QString version() const;///<верси€ плагина
    QList<Message> & messageList();///<список сообщений
    QList<SettingsItem> & settings() const;///<список настроек
    void setSettings(const QList<SettingsItem> & settings);///<установить новый список настроек
    QString id();///<id плагина
    virtual void start() = 0;///<запуск плагина
    virtual QIcon icon() = 0;///<икнока плагина
    virtual ~PluginIFace();
    void addConnectionIFace(ConnectionIFace & iface);
protected:
    QString _name;
    QList<QSharedPointer<ConnectionIFace>> _connectedIFaces;
    QList<Message> _messages;
    QList<SettingsItem> _settings;
signals:
    void connectedIFace(QSharedPointer<ConnectionIFace> iface); ///<уведомление о подключении нового интерфейса
    void disconnectedIFace(QSharedPointer<ConnectionIFace> iface); ///<уведомление об отключении интерфейса
    void recieved(Message message);///<уведомление о получении сообщени€
    void sended(Message message);///<уведомление об отправке сообщени€
};

#endif // PLUGINIFACE_H
