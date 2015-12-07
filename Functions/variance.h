#ifndef VARIANCE_H
#define VARIANCE_H

#include "function.h"

class Variance : public Function
{
public:
    static float calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector &data);
};

#endif // VARIANCE_H
