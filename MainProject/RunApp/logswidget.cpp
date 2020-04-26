#include "logswidget.h"

#include <QGridLayout>
#include <QPainter>
#include <QSizePolicy>
#include <QStyleOption>
#include <QHeaderView>
#include <iostream>
LogsWidget::LogsWidget(Logs* logs)
{
    this->setWindowTitle("Logs");
    this->logs = logs;
    init();
}
LogsWidget::~LogsWidget()
{
    delete grid;
}
void LogsWidget::init()
{
    grid = new QGridLayout(this);
    setLayout(grid);
    QHeaderView* header;
    this->table = new QTableWidget(this);
    this->table->setMinimumSize(this->width(), this->height());
    this->table->setColumnCount(8);
    this->table->setHorizontalHeaderLabels(QStringList()<<"N"<<"Time"<<"sender"<<"receiver"<<"status"<<"priority"<<"id"<<"data");
    grid->addWidget(this->table, 0, 0);
    header = this->table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    this->table->setRowCount(logs->size());
    fillTable();
    QObject::connect(this->table->horizontalHeader(), SIGNAL(sectionClicked( int )), this, SLOT(handleSortColumn(int)));

}

void LogsWidget::fillTable(){
    for (int i = 0;i<logs->size();i++)
    {
        this->table->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
        this->table->setItem(i, 1, new QTableWidgetItem(logs->message(i).date().toString()));
        this->table->setItem(i, 4, new QTableWidgetItem(logs->message(i).status()));
        this->table->setItem(i, 5, new QTableWidgetItem(logs->message(i).priority()));
        this->table->setItem(i, 6, new QTableWidgetItem(QString::number(logs->message(i).id())));
    }
}

void LogsWidget::handleSortColumn(int i){
    logs->sort(i);
    fillTable();
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
