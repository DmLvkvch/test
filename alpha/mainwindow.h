#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindowsettings.h"
#include "pluginwidget.h"

#include <QComboBox>
#include <QMainWindow>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*!
 *  class-widget displaying the main window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSharedPointer<QGridLayout> _widgetsLayout;
    QSharedPointer<QWidget> _widget;
    QSharedPointer<QMenuBar> _mnuBar;
    QSharedPointer<QMenu> _pmnu;
    QSharedPointer<MainWindowSettings> _settings;
    QList<PluginWidget> _pluginsList;
    Ui::MainWindow *ui;
private slots:
    void handleSettings();
    void handleLoadNewPlugin();
};
#endif // MAINWINDOW_H
