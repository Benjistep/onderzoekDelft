#include "pirsetting.h"
#include "../../Functions/average.h"

PIRSetting::PIRSetting(bool functioning): _functioning(functioning)
{
}

QString PIRSetting::toString()
{
    return QString("PIR: Functioning: ") + QString::number(_functioning);
}

bool PIRSetting::check(std::vector<float>& data)
{
    float average = Average::calc(data);

    if(average >= 0.75 && !_functioning)
    {
        return false;
    }
    else if(average < 0.75 && _functioning)
    {
        return false;
    }

    return true;
}
