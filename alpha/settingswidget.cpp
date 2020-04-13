#include "settingswidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QSpinBox>
#include <QStyleOption>
#include <QVBoxLayout>
#include <iostream>

SettingsWidget::SettingsWidget(){

}

SettingsWidget::SettingsWidget(QList<QSharedPointer<ConnectionIFace>> ifaces): QWidget(nullptr)
{
    this->ifaces = ifaces;
    this->setWindowTitle("Settings");
    saveButton = QSharedPointer<QPushButton>( new QPushButton());
    saveButton->setText("save");
    cancelButton = QSharedPointer<QPushButton>(new QPushButton());
    cancelButton->setText("cancel");
    layout = QSharedPointer<QVBoxLayout>(new QVBoxLayout);
    buttonsLayout = QSharedPointer<QHBoxLayout>(new QHBoxLayout);
    buttonsLayout->addWidget(saveButton.get());
    buttonsLayout->addWidget(cancelButton.get());
    layout->addLayout(buttonsLayout.get());
    setLayout(layout.get());
    QObject::connect(cancelButton.get(), SIGNAL(clicked()), this, SLOT(cancelSettings()));

    init();
}

SettingsWidget::~SettingsWidget()
{

}

void SettingsWidget::init()
{
    foreach (auto &iface, ifaces) {
        foreach (auto& setting, iface->settings()) {
            std::cout<<setting.name.toStdString();
        }
    }
}

void SettingsWidget::paintEvent(QPaintEvent* e)
{
    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.drawRoundedRect(0,5,width()-5, height()-7,3,3);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void SettingsWidget::saveSettings()
{

}


void SettingsWidget::cancelSettings()
{
    this->close();
}
