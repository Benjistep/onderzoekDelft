#include "lightsetting.h"

LightSetting::LightSetting(bool lightsOn): _lightsOn(lightsOn)
{

}

QString LightSetting::toString()
{
    return QString("Lights: Functioning: ") + QString::number(_lightsOn);
}

bool LightSetting::check(Result& data)
{
    float average = data.getAverage();

    if(average >= 0.75 && !_lightsOn)
    {
        return false;
    }
    else if(average < 0.75 && _lightsOn)
    {
        return false;
    }

    return true;
}
