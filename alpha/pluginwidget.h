#ifndef PluginWidget_H
#define PluginWidget_H

#include "iface.h"
#include "pluginiface.h"

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>


class PluginWidget : public QWidget
{
    Q_OBJECT

public:
    PluginWidget(QString name, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    virtual  ~PluginWidget();
private slots:
    void openLogsButton_clicked();
    void openSettingsButton_clicked();
private:
    QGridLayout *grid;
    PluginIFace* plugin;
    QString widgetName;
    QWidget* parentCustomWidget;
    QPushButton* openLogsButton;
    QPushButton* openSettingsButton;
    QList<IFace*> connectedIFaces;
    void initIFaces();

};

#endif // PluginWidget_H
