#include "logswidget.h"

#include <QGridLayout>
#include <QPainter>
#include <QSizePolicy>
#include <QStyleOption>
#include <QHeaderView>

LogsWidget::LogsWidget(QList<Message> & listOfMessages)
{
    this->setWindowTitle("Logs");
    this->listOfMessages = listOfMessages;
    init();
}

void LogsWidget::init()
{
    QGridLayout *grid = new QGridLayout(this);
    setLayout(grid);
    this->table = new QTableWidget(this);
    this->table->setMinimumSize(this->width(), this->height());
    this->table->setColumnCount(7);
    this->table->setHorizontalHeaderLabels(QStringList()<<"N"<<"Time"<<"sender"<<"receiver"<<"status"<<"id"<<"data");
    grid->addWidget(this->table, 0, 0);
    QHeaderView* w = this->table->horizontalHeader();
    w->setSectionResizeMode(QHeaderView::Stretch);
}

void LogsWidget::paintEvent(QPaintEvent * e)
{
    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.drawRoundedRect(0,5,width()-5, height()-7,3,3);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
