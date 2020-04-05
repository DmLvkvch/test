#include "settings.h"

QVariant Settings::getValue(){
    return value;
}

QString Settings::getName(){
    return this->name;
}
