#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H


class ConnectionIFace;
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
    /*!
      * \brief Конструктор объекта класса SettingsWidget
      * принимает на вход список интерфейсов
      */
    SettingsWidget(QList<QSharedPointer<ConnectionIFace>> & ifaces);
    void paintEvent(QPaintEvent * e);
    ~SettingsWidget();
private slots:
    void saveSettings();///<сохранение настроек
    void cancelSettings();///<отмена введенных настроек
private:
    void init();
    QSharedPointer<QVBoxLayout> _layout;
    QSharedPointer<QHBoxLayout> _buttonsLayout;
    QSharedPointer<QPushButton> _saveButton;
    QSharedPointer<QPushButton> _cancelButton;
    QList<QSharedPointer<ConnectionIFace>> _ifaces;
};

#endif // SETTINGSWIDGET_H
