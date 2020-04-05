#include "settingswidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QSpinBox>
#include <QStyleOption>
#include <QVBoxLayout>
#include <iostream>
SettingsWidget::SettingsWidget(QList<IFace*> & ifaces):QWidget(nullptr)
{
    this->setWindowTitle("Settings");
    this->ifaces = ifaces;
    init();
    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelSettings()));
}

void SettingsWidget::init(){
    saveButton = new QPushButton(this);
    saveButton->setText("save");
    cancelButton = new QPushButton(this);
    cancelButton->setText("cancel");
    QVBoxLayout *layout = new QVBoxLayout();
    QVBoxLayout *tmp = new QVBoxLayout();
    for (int i = 0;i<this->ifaces.size();i++) {
        QLabel* l = new QLabel;
        l->setText(ifaces[i]->getName());
        tmp->addWidget(l);
        QList<Settings> set = ifaces[i]->getSettings();
        for (int j = 0;j<set.size();j++) {
            QLabel* name = new QLabel;
            QLineEdit* le = new QLineEdit;
            name->setText(set[j].getName());
            le->setText(set[j].getValue().toString());
            tmp->addWidget(name);
            tmp->addWidget(le);
            layout->addLayout(tmp);
        }
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
    this->close();
}
