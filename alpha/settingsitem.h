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
    QString     name;///<��� ���������
    QVariant    value;///<�������� ���������
    Type        type;///<��� ������ ���������
    double      min;///<����������� �������� ���������
    double      max;///<������������ �������� ���������
    double      step;///<���, � ������� ����� �������� ���������

};

#endif // SETTINGS_H
