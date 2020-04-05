#ifndef MESSAGE_H
#define MESSAGE_H

#include "iface.h"

#include <QString>
#include <QList>
#include <QDateTime>



namespace MessagePriority {
    enum Values
    {
        Unknown, Low, Medium, High
    };
}
namespace  MessageStatus {
    enum Values
    {
        Unknown, Recieved, Viewed
    };
}


class Message
{
public:
    Message();
private:
        unsigned long id;
        QString reciever;
        QString sender;
        MessageStatus::Values status;
        QDateTime timestamp;
        MessagePriority::Values priority;
        QString type;
        QString data;
};
#endif // MESSAGE_H
