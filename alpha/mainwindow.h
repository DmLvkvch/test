#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pluginwidget.h"

#include <QComboBox>
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
    int getNumOfAvailableColumns();
    int getNumOfAvailableRows();
    QComboBox *gridViewByRow;
    QComboBox *gridViewByColumn;
    QList<PluginWidget*>* listOfPlugins;
    Ui::MainWindow *ui;
private slots:
    void settings();
    void load_new_plugin();
};
#endif // MAINWINDOW_H
