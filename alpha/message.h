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
    unsigned long getId() const;
    QString getStatus() const;
    QString getPriority() const;
    QByteArray getData() const;
    QDateTime getDate() const;
    Format getFormat() const;
private:
    QString caption, description;
    unsigned long id;
    QString reciever;
    QString sender;
    MessageStatus::Values status;
    QDateTime timestamp;
    MessagePriority::Values priority;
    QString type;
    QByteArray data;
    Format format;
};
#endif // MESSAGE_H
