#include "settings.h"

Settings::Settings()
{

}

QString Settings::getIp(){
    return this->ip;
}

QString Settings::getPort(){
    return this->port;
}
