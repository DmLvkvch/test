#include "iface.h"

IFace::IFace()
{
    this->settings = new QList<Settings>();
    this->settings->push_back(Settings("IP", "255.255.255.255", 0, 0, 0));
    this->settings->push_back(Settings("Port", "8080", 0, 0, 0));
}

QString IFace::getName() const{
  return "FORTIS";
}

QList<Settings> IFace::getSettings(){
    return *settings;
}

void IFace::status(){}
void IFace::event(){}
void IFace::send(){}
void IFace::receive(){}
