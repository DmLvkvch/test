#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QList>
#include <QDateTime>



namespace MessagePriority {
    enum class Values
    {
        Unknown, Low, Medium, High
    };
}
namespace  MessageStatus {
    enum class Values
    {
        Unknown, Recieved, Viewed
    };
}

/*!
 *  class defining message structure
 */
class Message
{
public:
    enum class Format{
        Unknown, Bin, Txt, Json, Xml, Rar, Zip
    };
    Message();
    ~Message();
    unsigned long id() const;///<получить id сообщения
    QString status() const;///<получить статус сообщения
    QString priority() const;///<получить приоритет сообщения
    QByteArray data() const;///<получить время сообщения
    QDateTime date() const;///<получить данных из сообщения
    Format format() const;///<получить формат сообщения
    QString caption() const;///<получить заголовок сообщения
    QString description() const;///<получить описание сообщения
    QString reciever() const;///<получить получателя сообщения
    QString sender() const;///<получить отправителя сообщения
private:
    QString _caption, _description;
    unsigned long _id;
    QString _reciever;
    QString _sender;
    MessageStatus::Values _status;
    QDateTime _timestamp;
    MessagePriority::Values _priority;
    QString _type;
    QByteArray _data;
    Format _format;
};
#endif // MESSAGE_H
