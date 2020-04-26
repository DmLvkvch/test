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
      * \brief ����������� ������� ������ SettingsItem
      * �������������� ��� ����
      * ���������� ��-���������
      */
    SettingsItem();
    /*!
      * \brief ����������� ������� ������ SettingsItem
      * �������������� ��� �������� ����������� �����������
      */
    SettingsItem(QString name,QVariant value, Type type, double min, double max, double step, int precision);

    int precision;
    QVariantList listItems;
    QString     name;///<��� ���������
    QVariant    value;///<�������� ���������
    Type        type;///<��� ������ ���������
    double      min;///<����������� �������� ���������
    double      max;///<������������ �������� ���������
    double      step;///<���, � ������� ����� �������� ���������

};

#endif // SETTINGS_H
