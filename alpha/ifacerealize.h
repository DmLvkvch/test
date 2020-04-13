#ifndef IFACEREALIZE_H
#define IFACEREALIZE_H

#include "connectioniface.h"



class ifacerealize:public ConnectionIFace
{
public:
    ifacerealize();

    // ConnectionIFace interface
public:
    void send(const Message &message);
    void receive(const Message &message);
};

#endif // IFACEREALIZE_H
