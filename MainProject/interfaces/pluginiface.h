#ifndef PLUGINIFACE_H
#define PLUGINIFACE_H



class ConnectionIFace;
class Message;
#include <QIcon>
#include <QList>
#include <QString>
/*!
 *  class describing plugin
 */
class PluginIFace
{
public:
    /*!
      * \brief Конструктор объекта класса PluginIFace
      * инициализирует все настройки плагина
      */
    PluginIFace(QString _name, QString _version, QIcon _icon);
    QString name() const;///<Название плагина
    QList<QSharedPointer<ConnectionIFace>> & connectedIFaces();///<список подключенных интерфейсов
    QString version() const;///<версия плагина
    QList<Message> & messageList();///<список сообщений
    QString id();///<id плагина
    virtual void start() = 0;///<запуск плагина
    QIcon icon();///<икнока плагина
    virtual ~PluginIFace();
protected:
    void addConnectionIFace(ConnectionIFace & iface);///<добавить новый интерфейс
    QList<QSharedPointer<ConnectionIFace>> _connectedIFaces;
    QList<Message> _messages;
signals:
    void connectedIFace(QSharedPointer<ConnectionIFace> iface); ///<уведомление о подключении нового интерфейса
    void disconnectedIFace(QSharedPointer<ConnectionIFace> iface); ///<уведомление об отключении интерфейса
    void recieved(Message message);///<уведомление о получении сообщения
    void sended(Message message);///<уведомление об отправке сообщения
private:
    QString _name;
    QString _version;
    QIcon _icon;
};

#endif // PLUGINIFACE_H
