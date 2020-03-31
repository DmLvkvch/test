#include "settingswidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QStyleOption>
#include <QVBoxLayout>

SettingsWidget::SettingsWidget(QList<IFace*> & ifaces):QWidget(nullptr)
{
    this->setWindowTitle("Settings");
    this->ifaces = ifaces;
    init();
}

void SettingsWidget::init(){
    QVBoxLayout *layout = new QVBoxLayout();
    QVector<QLabel*> ifaceName;
    QVector<QLineEdit*> ip;
    QVector<QLineEdit*> port;
    QVBoxLayout *tmp = new QVBoxLayout();
    for (int i = 0;i<this->ifaces.size();i++) {
        QLabel* l = new QLabel;
        l->setText(ifaces[i]->getName());
        ifaceName.push_back(l);
        QLineEdit* le = new QLineEdit;
        le->setText(ifaces[i]->getSettings().getIp());
        ip.push_back(le);
        le = new QLineEdit;
        le->setText(ifaces[i]->getSettings().getPort());
        port.push_back(le);
        tmp->addWidget(ifaceName[i]);
        tmp->addWidget(ip[i]);
        tmp->addWidget(port[i]);
        layout->addLayout(tmp);
    }
    setLayout(layout);
}

void SettingsWidget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.drawRoundedRect(0,5,width()-5, height()-7,3,3);

    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
