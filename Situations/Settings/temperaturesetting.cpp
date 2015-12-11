#include "temperaturesetting.h"
#include "../../Functions/average.h"
#include "../../Functions/max.h"
#include <iostream>

TemperatureSetting::TemperatureSetting(int maxTemp, bool maxTempV, bool tempNotNull):
    _maxTemp(maxTemp),
    _maxTempV(maxTempV),
    _tempNotNull(tempNotNull)
{
}

QString TemperatureSetting::toString()
{
    return QString("Temperature: maxTemperature: ") + QString::number(_maxTemp) +
            QString(", maxTemperatureViolated: ") + QString::number(_maxTempV) +
            QString(", Functioning: ") + QString::number(_tempNotNull);
}

bool TemperatureSetting::check(std::vector<float>& data)
{

    float average = Average::calc(data);
    float max = Max::calc(data);

    if(max > _maxTemp && !_maxTempV)
    {
        std::cout << "Temperature 1" << std::endl;

        return false;
    }
    else if(max <= _maxTemp && _maxTempV)
    {
        std::cout << "Temperature 2" << std::endl;
        return false;
    }

    if(average > 0.0 && !_tempNotNull)
    {
        std::cout << "Temperature 3" << std::endl;
        return false;
    }
    else if(average == 0.0 && _tempNotNull)
    {
        std::cout << "Temperature 4" << std::endl;
        return false;
    }

    return true;
}


