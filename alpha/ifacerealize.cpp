#include "ifacerealize.h"

ifacerealize::ifacerealize()
{
    SettingsItem s;
    this->_settings.push_back(s);
    this->_settings.push_back(s);
    this->_settings.push_back(s);
    this->_settings.push_back(s);
}

void ifacerealize::send(const Message &message){

}

void ifacerealize::receive(const Message &message){

}
