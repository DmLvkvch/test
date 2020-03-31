#ifndef PluginWidget_H
#define PluginWidget_H

#include "iface.h"
#include "pluginiface.h"

#include <QPushButton>
#include <QWidget>


class PluginWidget : public QWidget
{
    Q_OBJECT

public:
    PluginWidget(QString name, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    virtual  ~PluginWidget();
    QList<IFace*>& getConnectedIFaces();
private slots:
    void open_in_new_window();
    void openLogsButton_clicked();
    void openSettingsButton_clicked();
private:
    PluginIFace plugin;
    QString widgetName;
    QWidget* parentWidget;
    QPushButton* openLogsButton;
    QPushButton* openSettingsButton;
    QList<IFace*> connectedIFaces;
};
#endif // PluginWidget_H
