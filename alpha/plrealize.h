#ifndef PLREALIZE_H
#define PLREALIZE_H

#include "pluginiface.h"



class plrealize: public PluginIFace
{
public:
    plrealize();

    // PluginIFace interface
public:
    void start();
    QIcon icon();
};

#endif // PLREALIZE_H
