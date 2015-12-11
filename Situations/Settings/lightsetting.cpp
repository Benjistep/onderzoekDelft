#include "lightsetting.h"
#include "../../Functions/average.h"

LightSetting::LightSetting(bool lightsOn): _lightsOn(lightsOn)
{

}

QString LightSetting::toString()
{
    return QString("Lights: Functioning: ") + QString::number(_lightsOn);
}

bool LightSetting::check(std::vector<float>& data)
{
    float average = Average::calc(data);

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
