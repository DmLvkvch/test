#include "message.h"
#include "pluginiface.h"

PluginIFace::PluginIFace(QString _name, QString _version, QIcon _icon)
{
    this->_version = _version;
    this->_icon = _icon;
    this->_messages.push_back(Message());
    this->_name = _name;
}

QList<Message> & PluginIFace::messageList()
{
    return this->_messages;
}

QString PluginIFace::name() const
{
    return this->_name;
}

QList<QSharedPointer<ConnectionIFace>> & PluginIFace::connectedIFaces()
{
    return this->_connectedIFaces;
}

QString PluginIFace::version() const
{
    return _version;
}

QString PluginIFace::id()
{

}

PluginIFace::~PluginIFace()
{

}

QIcon PluginIFace::icon(){
    return _icon;
}

void PluginIFace::addConnectionIFace(ConnectionIFace & iface)
{
    this->_connectedIFaces.push_back(QSharedPointer<ConnectionIFace>(&iface));
}
