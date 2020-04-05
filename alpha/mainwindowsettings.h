#ifndef MAINWINDOWSETTINGS_H
#define MAINWINDOWSETTINGS_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QWidget>



class MainWindowSettings: public QDialog
{
    Q_OBJECT
public:
    MainWindowSettings(QWidget* parent = nullptr);
private:
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

#endif // MAINWINDOWSETTINGS_H
