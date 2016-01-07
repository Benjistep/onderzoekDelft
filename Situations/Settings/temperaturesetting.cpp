#include "temperaturesetting.h"
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

bool TemperatureSetting::check(Result& data)
{

    float average = data.getAverage();
    float max = data.getMax();

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


