#ifndef VERTEX_H
#define VERTEX_H
#include "edge.h"
#include <qvector.h>
#include <qstring.h>
#include <QString>
using namespace std;

class Vertex
{
private:
    QString name;
    vector<int> type;
    vector<bool> parking;
public:
    Vertex();
    void addCity(QString name, QString type, QString park);
};

#endif // VERTEX_H
