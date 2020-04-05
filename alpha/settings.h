#ifndef SETTINGS_H
#define SETTINGS_H

#include <QVariant>
#include <QString>
class Settings
{
private:
    QString     name;
    QVariant    value;
    double      min;
    double      max;
    double      step;

public:
    Settings(){
        name = "";
        value = "";
        min = max = step = 0.0;
    }
    Settings(QString name, QVariant value, double min, double max, double step)
            :name(name), value(value), min(min), max(max), step(step){}
   QVariant getValue();
   QVariant getType();
   QString getName();
};

#endif // SETTINGS_H
