#include "pluginiface.h"

PluginIFace::PluginIFace()
{

}

QList<IFace*> & PluginIFace::getConnectedIFaces(){
    QList<IFace*>* tmp = new QList<IFace*>();
    tmp->push_back(new IFace());
    tmp->push_back(new IFace());
    return *tmp;
}


QList<Message> & PluginIFace::getMessageList(){
    QList<Message>* l = new QList<Message>();
    l->push_back(Message());
    return *l;
}
