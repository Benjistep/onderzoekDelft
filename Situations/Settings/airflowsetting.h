#ifndef AIRFLOWSETTING_H
#define AIRFLOWSETTING_H

#include "setting.h"

class AirflowSetting : public Setting
{
private:
    int _maxAirflow;
    bool _maxAirflowV;
    bool _notNull;

public:
    AirflowSetting(int maxAirflow, bool maxV, bool notNull);
    QString toString();
    bool check(Result& result);
};

#endif // AIRFLOWSETTING_H
