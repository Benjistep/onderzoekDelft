#ifndef PIRSETTING_H
#define PIRSETTING_H

#include "setting.h"

class PIRSetting : public Setting
{
private:
    bool _functioning;
public:
    PIRSetting(bool functioning);
    QString toString();
    bool check(std::vector<float>& data);
};

#endif // PIRSETTING_H
