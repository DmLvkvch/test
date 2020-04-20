#ifndef PluginWidget_H
#define PluginWidget_H

class PluginIFace;
class SettingsWidget;
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

/*!
 *  class-widget displaying plugin
 */
class PluginWidget : public QWidget
{
    Q_OBJECT

public:
    PluginWidget(PluginIFace & plugin, QString name, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);///<метод для отображения виджета
    virtual  ~PluginWidget();
private slots:
    void handleOpenLogs();
    void handleOpenSettings();
private:
    QSharedPointer<QGridLayout> _grid;
    PluginIFace & _plugin;
    QString _widgetName;
    QSharedPointer<QWidget> _parentCustomWidget;
    QSharedPointer<QPushButton> _openLogsButton;
    QSharedPointer<QPushButton> _openSettingsButton;
    QSharedPointer<SettingsWidget> _settings;
    void initIFaces();

};

#endif // PluginWidget_H
