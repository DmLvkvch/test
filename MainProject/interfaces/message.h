#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QList>
#include <QDateTime>



namespace MessagePriority {
    enum class Values
    {
        Unknown, Low, Medium, High
    };
}
namespace  MessageStatus {
    enum class Values
    {
        Unknown, Recieved, Viewed
    };
}

/*!
 *  class defining message structure
 */
class Message
{
public:
    enum class Format{
        Unknown, Bin, Txt, Json, Xml, Rar, Zip
    };
    Message();
    ~Message();
    unsigned long id() const;///<�������� id ���������
    QString status() const;///<�������� ������ ���������
    QString priority() const;///<�������� ��������� ���������
    QByteArray data() const;///<�������� ����� ���������
    QDateTime date() const;///<�������� ������ �� ���������
    Format format() const;///<�������� ������ ���������
    QString caption() const;///<�������� ��������� ���������
    QString description() const;///<�������� �������� ���������
    QString reciever() const;///<�������� ���������� ���������
    QString sender() const;///<�������� ����������� ���������
private:
    QString _caption, _description;
    unsigned long _id;
    QString _reciever;
    QString _sender;
    MessageStatus::Values _status;
    QDateTime _timestamp;
    MessagePriority::Values _priority;
    QString _type;
    QByteArray _data;
    Format _format;
};
#endif // MESSAGE_H
