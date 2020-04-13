#include "message.h"
#include <string>
Message::Message()
{
    this->id = rand()%10;

    this->status = MessageStatus::Values::Recieved;
    this->priority = MessagePriority::Values::High;
    this->timestamp = QDateTime::currentDateTime();
}

unsigned long Message::getId() const{
    return id;
}
QString Message::getStatus() const{
    switch (this->status) {
    case MessageStatus::Values::Recieved:
        return "received";
    case MessageStatus::Values::Viewed:
        return "viewed";
    default:
        return "unknown";
    }
    return "";
}
QString Message::getPriority() const{
    switch (this->priority) {
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

QDateTime Message::getDate() const{
    return this->timestamp;
}

Message::~Message()
{

}
