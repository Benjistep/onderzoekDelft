#include "airflowsetting.h"
#include "../../Functions/average.h"
#include "../../Functions/deviation.h"
#include <iostream>


AirflowSetting::AirflowSetting(int maxAirflow, bool maxV, bool notNull):
    _maxAirflow(maxAirflow),
    _maxAirflowV(maxV),
    _notNull(notNull)
{

}

QString AirflowSetting::toString()
{
    return QString("Airflow: maxDeviation: ") + QString::number(_maxAirflow) +
            QString(", deviationViolated: ") + QString::number(_maxAirflowV) +
            QString(", Functioning: ") + QString::number(_notNull);
}

bool AirflowSetting::check(std::vector<float>& data)
{
    float average = Average::calc(data);
    float max = Deviation::calc(data);

    if(max > _maxAirflow && !_maxAirflowV)
    {
        std::cout << "Airflow 1" << std::endl;

        return false;
    }
    else if(max <= _maxAirflow && _maxAirflowV)
    {
        std::cout << "Airflow 2" << std::endl;
        return false;
    }

    if(average > 0.0 && !_notNull)
    {
        std::cout << "Airflow 3" << std::endl;
        return false;
    }
    else if(average == 0.0 && _notNull)
    {
        std::cout << "Airflow 4" << std::endl;
        return false;
    }

    return true;
}
