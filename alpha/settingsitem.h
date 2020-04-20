#ifndef SETTINGS_H
#define SETTINGS_H

#include <QVariant>
#include <QString>

/*!
 *  class defining settings structure
 */
class SettingsItem
{
public:
    enum class Type
    {
        Unknown, Int, Double, Float, String, Ip, List, Bool
    };
    /*!
      * \brief Конструктор объекта класса SettingsItem
      * инициализирует все поля
      * значениями по-умолчанию
      */
    SettingsItem();
    /*!
      * \brief Конструктор объекта класса SettingsItem
      * инициализирует все значения переданными параметрами
      */
    SettingsItem(QString name,QVariant value, Type type, double min, double max, double step, int precision);

    int precision;
    QVariantList listItems;
    QString     name;///<имя настройки
    QVariant    value;///<значение настройки
    Type        type;///<тип данных настройки
    double      min;///<минимальное значение настройки
    double      max;///<максимальное значение настройки
    double      step;///<шаг, с которым можно изменять настройку

};

#endif // SETTINGS_H
