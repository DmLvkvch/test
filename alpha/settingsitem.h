#ifndef SETTINGS_H
#define SETTINGS_H

#include <QVariant>
#include <QString>

/*!
 *  class defining settings structure
 */
struct SettingsItem
{
    enum class Type
    {
        Unknown, Int, Double, Float, String, Ip, List, Bool
    };

    SettingsItem();
    SettingsItem(QString name,QVariant value, Type type, double min, double max, double step);

    int _precision;
    QVariantList listItems;
    QString     name;///<имя настройки
    QVariant    value;///<значение настройки
    Type        type;///<тип данных настройки
    double      min;///<минимальное значение настройки
    double      max;///<максимальное значение настройки
    double      step;///<шаг, с которым можно изменять настройку

};

#endif // SETTINGS_H
