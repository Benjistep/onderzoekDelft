#ifndef SETTING_H
#define SETTING_H

#include <QString>
#include "../../Controller/result.h"

class Setting
{
public:
    Setting();
    virtual ~Setting();
    virtual QString toString() = 0;
    virtual bool check(Result& data) = 0;
};

#endif // SETTING_H
