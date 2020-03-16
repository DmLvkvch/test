#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>
#include "thread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVector<QLabel*> lables;
    QVector <QProgressBar*> processes;
    QVector<Thread*> threads;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onProgress(QProgressBar* process,  int i );
    void onFinish(QLabel *label);
    void onRunning(QLabel* label);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
