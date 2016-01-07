#ifndef CO2SETTING_H
#define CO2SETTING_H

#include "setting.h"
#include "../../Controller/result.h"
#include <vector>

class CO2Setting : public Setting
{
private:
    int maxAcceptable;
    int deviation;
    bool maxViolated, deviationViolated, notNull, constantValue;
public:
    CO2Setting(int maxAcceptable, int deviation, bool maxViolated,
               bool deviationViolated, bool notNull, bool constantValue);
    bool check(Result& result);
    QString toString();

};

#endif // CO2SETTING_H
