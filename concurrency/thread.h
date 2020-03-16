#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <Factorial.h>
#include <QProgressBar>
#include <iostream>
#include <vector>
#include <QLabel>
class Thread : public QThread
{
    Q_OBJECT
public:
    QProgressBar* process;
    QLabel* label;
    std::vector<long> result;
    Thread(QProgressBar* bar, QLabel *label){
        process = bar;
        this->label = label;
    }
signals:
    void progress(QProgressBar* bar,  int value );
    void running(QLabel* label);
    void finished(QLabel* label);

private:
    void run()
    {
        result.clear();
        emit running(label);
        for(long i = 0; i <= 10000; i++ )
        {   result.push_back(Factorial::factorial(i));
            emit progress(process, result.size());
        }
        emit finished(label);
    }
};
#endif // THREAD_H
