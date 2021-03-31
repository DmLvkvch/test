#ifndef LOGSWIDGET_H
#define LOGSWIDGET_H

#include "../../interfaces/connectioniface.h"
#include "../../interfaces/logs.h"
#include <QGridLayout>
#include <QTableWidget>
#include <QWidget>

/*!
 *  class-widget displaying list of messages
 */
class LogsWidget: public QWidget
{
    Q_OBJECT
public:
    LogsWidget(Logs* logs);
    void paintEvent(QPaintEvent * e);
    ~LogsWidget();
private slots:
    void handleSortColumn(int);
private:
    void init();
    void fillTable();
    QGridLayout*  grid;
   // QList<Message> listOfMessages;
    Logs* logs;
    QTableWidget* table;
};

#endif // LOGSWIDGET_H