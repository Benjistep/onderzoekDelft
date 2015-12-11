#ifndef LIGHTSETTING_H
#define LIGHTSETTING_H

#include "setting.h"

class LightSetting : public Setting
{
private:
    bool _lightsOn;

public:
    LightSetting(bool lightsOn);
    QString toString();
    bool check(std::vector<float>& data);
};

#endif // LIGHTSETTING_H
