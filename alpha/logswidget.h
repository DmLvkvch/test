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
    LogsWidget(QList<IFace*> & ifaces);
    void paintEvent(QPaintEvent * e);
    void init();
private:
    QList<IFace*> ifaces;
    QTableWidget* table;

};

#endif // LOGSWIDGET_H
