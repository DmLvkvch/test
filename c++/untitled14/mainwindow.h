#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void InitCity();
    ~MainWindow();

private slots:
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
