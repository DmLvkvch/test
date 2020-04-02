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
