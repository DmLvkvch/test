#include "connectioniface.h"

ConnectionIFace::ConnectionIFace()
{

}

ConnectionIFace::ConnectionIFace(QString name)
{

}

ConnectionIFace::~ConnectionIFace()
{

}

QString ConnectionIFace::name() const
{

}

ConnectionIFace::Status ConnectionIFace::status() const
{

}

void ConnectionIFace::setSettings(const QList<SettingsItem> & settings)
{

}

QList<SettingsItem> & ConnectionIFace::settings(){
    return this->_settings;
}
