#ifndef MAX_H
#define MAX_H

#include "function.h"

class Max : public Function
{
public:
    static float calc(std::vector<float>& data);
};

#endif // MAX_H
