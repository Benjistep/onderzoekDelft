#ifndef SUM_H
#define SUM_H

#include "function.h"

class Sum : public Function
{
public:
    static float calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector& data);
};

#endif // SUM_H
