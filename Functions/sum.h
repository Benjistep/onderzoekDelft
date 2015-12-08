#ifndef SUM_H
#define SUM_H

#include "function.h"

class Sum : public Function
{
public:
    static float calc(std::vector<float>& data);
};

#endif // SUM_H
