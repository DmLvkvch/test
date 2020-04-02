#include "settingswidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QSpinBox>
#include <QStyleOption>
#include <QVBoxLayout>

SettingsWidget::SettingsWidget(QList<IFace*> & ifaces):QWidget(nullptr)
{
    this->setWindowTitle("Settings");
    this->ifaces = ifaces;
    init();
}

void SettingsWidget::init(){
    saveButton = new QPushButton(this);
    saveButton->setText("save");
    cancelButton = new QPushButton(this);
    cancelButton->setText("cancel");
    QVBoxLayout *layout = new QVBoxLayout();
    QVector<QLabel*> ifaceName;
    QVector<QLineEdit*> ip;
    QVector<QSpinBox*> port;
    QVBoxLayout *tmp = new QVBoxLayout();
    for (int i = 0;i<this->ifaces.size();i++) {
        QLabel* l = new QLabel;
        l->setText(ifaces[i]->getName());
        ifaceName.push_back(l);
        QLineEdit* le = new QLineEdit;
        le->setText(ifaces[i]->getSettings().getIp());
        ip.push_back(le);
        ip[i]->setInputMask("000.000.000.000");
        QSpinBox *spinBox = new QSpinBox();
        spinBox->setRange(0, 65535);
        spinBox->setValue(ifaces[i]->getSettings().getPort());
        port.push_back(spinBox);
        tmp->addWidget(ifaceName[i]);
        tmp->addWidget(ip[i]);
        tmp->addWidget(port[i]);
        layout->addLayout(tmp);
    }
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addWidget(cancelButton);
    layout->addLayout(buttonsLayout);
    setLayout(layout);
}

void SettingsWidget::paintEvent(QPaintEvent * e)
{
    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.drawRoundedRect(0,5,width()-5, height()-7,3,3);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void SettingsWidget::saveSettings(){

}


void SettingsWidget::cancelSettings(){

}
