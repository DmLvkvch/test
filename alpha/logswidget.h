#ifndef LOGSWIDGET_H
#define LOGSWIDGET_H

#include "iface.h"
#include "pluginwidget.h"
#include <QTableWidget>
#include <QWidget>

class LogsWidget: public QWidget
{
    Q_OBJECT
public:
    LogsWidget(QList<Message> & listOfMessages);
    void paintEvent(QPaintEvent * e);
    void init();
private:
    QList<Message> listOfMessages;
    QTableWidget* table;
};

#endif // LOGSWIDGET_H
