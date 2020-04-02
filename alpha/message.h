#ifndef MESSAGE_H
#define MESSAGE_H

#include "iface.h"
#include "enumtype.h"


class Message
{
public:
    Message();
private:
    IFace *receiver;
    IFace* sender;
    MsgStatus status;
    long id;
    long priority;
    QString data = "21312312";
};

#endif // MESSAGE_H
