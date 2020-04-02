#include "settings.h"

Settings::Settings()
{
    this->ip = "255.255.255.255";
    this->port = 0;
}

QString Settings::getIp(){
    return this->ip;
}

int Settings::getPort(){
    return this->port;
}
