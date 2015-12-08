#ifndef AVERAGE_H
#define AVERAGE_H

#include "function.h"

class Average : public Function
{
public:
    static float calc(std::vector<float>& data);
};

#endif // AVERAGE_H
