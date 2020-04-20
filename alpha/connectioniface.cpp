#include "connectioniface.h"
#include "message.h"
#include "settingsitem.h"

ConnectionIFace::ConnectionIFace(QString _name, QList<SettingsItem> _settings)
{
    this->_name = _name;
    this->_settings = _settings;
    this->_status = ConnectionIFace::Status::Connected;
}

ConnectionIFace::~ConnectionIFace()
{

}

QString ConnectionIFace::name() const
{
    return this->_name;
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
