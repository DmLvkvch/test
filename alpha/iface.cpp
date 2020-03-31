#include "iface.h"

IFace::IFace()
{

}

QString IFace::getName(){
  return "name";
}

Settings IFace::getSettings(){
    return settings;
}

void IFace::status(){}
void IFace::event(){}
void IFace::send(){}
void IFace::receive(){}
