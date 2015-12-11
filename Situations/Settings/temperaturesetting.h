#ifndef TEMPERATURESETTING_H
#define TEMPERATURESETTING_H

#include "setting.h"

class TemperatureSetting : public Setting
{
private:
    int _maxTemp;
    bool _maxTempV;
    bool _tempNotNull;

public:
    TemperatureSetting(int maxTemp, bool maxTempV, bool tempNotNull);
    QString toString();
    bool check(std::vector<float>& data);
};

#endif // TEMPERATURESETTING_H
