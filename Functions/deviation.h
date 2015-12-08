#ifndef DEVIATION_H
#define DEVIATION_H

#include "function.h"

class Deviation : public Function
{
public:
    static float calc(std::vector<float>& data);
};

#endif // DEVIATION_H
