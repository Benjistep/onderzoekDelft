#include "co2setting.h"
#include <iostream>

CO2Setting::CO2Setting(int maxAcceptable, int deviation, bool maxViolated, bool deviationViolated, bool notNull, bool constantValue):
    maxAcceptable(maxAcceptable),
    deviation(deviation),
    maxViolated(maxViolated),
    deviationViolated(deviationViolated),
    notNull(notNull),
    constantValue(constantValue)
{

}

QString CO2Setting::toString()
{
    return QString("CO2: maxAcceptable: ") + QString::number(maxAcceptable) +
            QString(", maxDeviation: ") + QString::number(deviation) +
            QString(", maxViolated: ") + QString::number(maxViolated) +
            QString(", deviationViolated: ") + QString::number(deviationViolated) +
            QString(", Functioning: ") + QString::number(notNull) +
            QString(", constantValue: ") + QString::number(constantValue);
}


bool CO2Setting::check(Result& data)
{
    float average = data.getAverage();
    float dev = data.getDeviation();
    float max = data.getMax();
    int count = data.getCount();

    //max co2
    if(max > maxAcceptable && !maxViolated)
    {
        std::cout << "CO2 1" << std::endl;

        return false;
    }
    else if(max <=  maxAcceptable && maxViolated)
    {
        std::cout << "CO2 2" << std::endl;
        return false;
    }

    //deviation
    if(dev > deviation && !deviationViolated)
    {
        std::cout << "CO2 3" << std::endl;

        return false;
    }
    else if(dev <= deviation &&  deviationViolated)
    {
        std::cout << "CO2 4" << std::endl;
        return false;
    }


    //not functioning
    if(average > 0.0 && !notNull)
    {
        std::cout << "CO2nn1" << std::endl;
        return false;
    }
    else if(average == 0.0 && notNull)
    {
        std::cout << "CO2nn2" << std::endl;
        return false;
    }

    //if more than 1 item
    if(count > 1)
    {
        //constant value check
        if(dev == 0.0 && !constantValue)
        {
            return false;
        }
        else if(dev != 0.0 && constantValue)
        {
            return false;
        }
    }
    return true;
}


