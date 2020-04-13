#include "plrealize.h"
#include "pluginiface.h"

PluginIFace::PluginIFace()
{
this->_messages.push_back(Message());
}

QList<Message> & PluginIFace::messageList()
{
    return this->_messages;
}

QString PluginIFace::name() const
{

}

QList<QSharedPointer<ConnectionIFace>> & PluginIFace::connectedIFaces()
{
    return this->_connectedIFaces;
}

QString PluginIFace::version() const
{

}

QList<SettingsItem> & PluginIFace::settings() const
{

}

void PluginIFace::setSettings(const QList<SettingsItem> & settings)
{

}

QString PluginIFace::id()
{

}

PluginIFace::~PluginIFace()
{

}


void PluginIFace::addConnectionIFace(ConnectionIFace & iface)
{
    this->_connectedIFaces.push_back(QSharedPointer<ConnectionIFace>(&iface));
}
