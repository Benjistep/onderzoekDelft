#ifndef COUNT_H
#define COUNT_H

#include "function.h"
class Count : public Function
{
public:
    static int calc(std::vector<float>& data);
};

#endif // COUNT_H
