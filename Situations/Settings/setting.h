#ifndef SETTING_H
#define SETTING_H

#include <QString>

class Setting
{
public:
    Setting();
    virtual ~Setting();
    virtual QString toString() = 0;
    virtual bool check(std::vector<float>& data) = 0;
};

#endif // SETTING_H
