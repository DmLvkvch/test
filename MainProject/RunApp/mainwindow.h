#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindowSettings;
class PluginWidget;
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
    QSharedPointer<QGridLayout> widgetsLayout();
    QList<PluginWidget> pluginsList();
private:
    void setUpPlugins();
    void loadNewPlugin(QString path);
    QSharedPointer<QGridLayout> _widgetsLayout;
    QSharedPointer<QWidget> _widget;
    QSharedPointer<QMenuBar> _mnuBar;
    QSharedPointer<QMenu> _pmnu;
    QSharedPointer<MainWindowSettings> _settings;
    QList<PluginWidget> _pluginsList;
    Ui::MainWindow *ui;
private slots:
    void handleSettings(); ///<слот об открытии окна с настройками плагина
    void handleLoadNewPlugin(); ///<слот об открытии окна с дял загрузки нового плагина
};
#endif // MAINWINDOW_H
