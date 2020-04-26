
#include "settingswidget.h"
#include "../../interfaces/settingsitem.h"
#include "../../interfaces/connectioniface.h"
#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QSpinBox>
#include <QStyleOption>
#include <QVBoxLayout>
#include <iostream>


SettingsWidget::SettingsWidget(QList<QSharedPointer<ConnectionIFace>> & ifaces): QWidget(nullptr)
{
    this->_ifaces = ifaces;
    this->setWindowTitle("Settings");
    _saveButton = QSharedPointer<QPushButton>( new QPushButton());
    _saveButton->setText("save");
    _cancelButton = QSharedPointer<QPushButton>(new QPushButton());
    _cancelButton->setText("cancel");
    _layout = QSharedPointer<QVBoxLayout>(new QVBoxLayout());
    _buttonsLayout = QSharedPointer<QHBoxLayout>(new QHBoxLayout());
    setLayout(_layout.get());
    _buttonsLayout->addWidget(_saveButton.get());
    _buttonsLayout->addWidget(_cancelButton.get());
    init();
    _layout->addLayout(_buttonsLayout.get());
    QObject::connect(_cancelButton.get(), SIGNAL(clicked()), this, SLOT(cancelSettings()));

}

SettingsWidget::~SettingsWidget()
{

}

void SettingsWidget::init()
{
    foreach (auto &iface, _ifaces)
    {
        QVBoxLayout* vbl = new QVBoxLayout;
        QLabel* name = new QLabel;
        name->setText(iface->name());
        vbl->addWidget(name);
        foreach (auto& setting, iface->settings())
        {
            QLabel* lb = new QLabel;
            lb->setText(setting.name);
            vbl->addWidget(lb);
            QLineEdit* le = new QLineEdit;
            if(setting.type==SettingsItem::Type::Ip)
            le->setText(setting.value.toString());
            vbl->addWidget(le);
        }
         _layout->addLayout(vbl);
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
