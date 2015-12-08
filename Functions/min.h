#ifndef MIN_H
#define MIN_H

#include "function.h"

class Min : public Function
{
public:
    static float calc(std::vector<float>& data);
};

#endif // MIN_H
