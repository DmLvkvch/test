#ifndef LOGS_H
#define LOGS_H
#include <QList>
#include "message.h"
/*!
 *  class describing the list of messages
 */
class Logs
{
public:
    Logs(QList<Message> & logs);
    Message getMessage(int i);
    ~Logs();
    void sortByN();
    void sortById();
    void sortByDate();
    void sort(int i);
    int size();
private:
    static bool srt(const Message & a, const Message & b);
    QList<Message> & logs;
};

#endif // LOGS_H
