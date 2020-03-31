#include "logswidget.h"

#include <QGridLayout>
#include <QPainter>
#include <QSizePolicy>
#include <QStyleOption>
#include <QHeaderView>
LogsWidget::LogsWidget(QList<IFace*> & ifaces)
{
    this->setWindowTitle("Logs");
    this->ifaces = ifaces;
    init();
}

void LogsWidget::init(){
    QGridLayout *grid = new QGridLayout(this);
    setLayout(grid);
    this->table = new QTableWidget(this);
    this->table->setMinimumSize(this->width(), this->height());
    this->table->setColumnCount(6);
    this->table->setHorizontalHeaderLabels(QStringList()<<"N"<<"Time"<<"sender"<<"receiver"<<"status"<<"id");
    grid->addWidget(this->table, 0, 0);
    QHeaderView* w = this->table->horizontalHeader();
    w->setSectionResizeMode(QHeaderView::Stretch);
}

void LogsWidget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.drawRoundedRect(0,5,width()-5, height()-7,3,3);

    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
