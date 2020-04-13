#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "connectioniface.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

/*!
 *  class-widget displaying settings
 */
class SettingsWidget: public QWidget
{
    Q_OBJECT
public:
    SettingsWidget(QList<QSharedPointer<ConnectionIFace>> ifaces);
    void paintEvent(QPaintEvent * e);
    ~SettingsWidget();
    SettingsWidget();
private slots:
    void saveSettings();
    void cancelSettings();
private:
    void init();
    QSharedPointer<QVBoxLayout>layout;
    QSharedPointer<QHBoxLayout> buttonsLayout;
    QSharedPointer<QPushButton> saveButton;
    QSharedPointer<QPushButton> cancelButton;
    QList<QSharedPointer<ConnectionIFace>> ifaces;
};

#endif // SETTINGSWIDGET_H
