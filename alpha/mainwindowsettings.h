#ifndef MAINWINDOWSETTINGS_H
#define MAINWINDOWSETTINGS_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>

/*!
 *  class-qdialog displaying settings of app
 */
class MainWindowSettings: public QDialog
{
    Q_OBJECT
public:
    MainWindowSettings(QWidget* parent = nullptr);
    ~MainWindowSettings();
private:
    QSharedPointer<QTabWidget> tabWidget;
    QSharedPointer<QDialogButtonBox> buttonBox;
    QSharedPointer<QVBoxLayout> mainLayout;
};

#endif // MAINWINDOWSETTINGS_H
