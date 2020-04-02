#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pluginwidget.h"

#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGridLayout* widgetsLayout;
private:
    QList<PluginWidget*>* listOfPlugins;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
