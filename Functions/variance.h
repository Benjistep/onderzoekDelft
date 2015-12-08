#ifndef VARIANCE_H
#define VARIANCE_H

#include "function.h"

class Variance : public Function
{
public:
    static float calc(std::vector<float>& data);
};

#endif // VARIANCE_H
