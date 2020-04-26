#ifndef PLUGINIFACE_H
#define PLUGINIFACE_H



class ConnectionIFace;
class Message;
#include <QIcon>
#include <QList>
#include <QString>
/*!
 *  class describing plugin
 */
class PluginIFace
{
public:
    /*!
      * \brief ����������� ������� ������ PluginIFace
      * �������������� ��� ��������� �������
      */
    PluginIFace(QString _name, QString _version, QIcon _icon);
    QString name() const;///<�������� �������
    QList<QSharedPointer<ConnectionIFace>> & connectedIFaces();///<������ ������������ �����������
    QString version() const;///<������ �������
    QList<Message> & messageList();///<������ ���������
    QString id();///<id �������
    virtual void start() = 0;///<������ �������
    QIcon icon();///<������ �������
    virtual ~PluginIFace();
protected:
    void addConnectionIFace(ConnectionIFace & iface);///<�������� ����� ���������
    QList<QSharedPointer<ConnectionIFace>> _connectedIFaces;
    QList<Message> _messages;
signals:
    void connectedIFace(QSharedPointer<ConnectionIFace> iface); ///<����������� � ����������� ������ ����������
    void disconnectedIFace(QSharedPointer<ConnectionIFace> iface); ///<����������� �� ���������� ����������
    void recieved(Message message);///<����������� � ��������� ���������
    void sended(Message message);///<����������� �� �������� ���������
private:
    QString _name;
    QString _version;
    QIcon _icon;
};

#endif // PLUGINIFACE_H
