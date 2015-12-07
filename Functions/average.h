#ifndef AVERAGE_H
#define AVERAGE_H

#include "function.h"

class Average : public Function
{
public:
    static float calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector& data);
};

#endif // AVERAGE_H
