#include "message.h"
#include <string>
Message::Message()
{
    this->_id = rand()%10;

    this->_status = MessageStatus::Values::Recieved;
    this->_priority = MessagePriority::Values::High;
    this->_timestamp = QDateTime::currentDateTime();
}

unsigned long Message::id() const{
    return _id;
}
QString Message::status() const{
    switch (this->_status) {
    case MessageStatus::Values::Recieved:
        return "received";
    case MessageStatus::Values::Viewed:
        return "viewed";
    default:
        return "unknown";
    }
    return "";
}
QString Message::priority() const{
    switch (this->_priority) {
    case MessagePriority::Values::High:
        return "high";
    case MessagePriority::Values::Medium:
        return "medium";
    case MessagePriority::Values::Low:
        return "low";
    default:
        return "unknown";
    }
    return "";
}

QDateTime Message::date() const{
    return this->_timestamp;
}

Message::~Message()
{

}
