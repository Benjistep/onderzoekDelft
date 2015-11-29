#ifndef MIN_H
#define MIN_H

#include "function.h"

class Min : public Function
{
public:
    static float calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector &data);
};

#endif // MIN_H
