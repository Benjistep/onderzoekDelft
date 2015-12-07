#ifndef DEVIATION_H
#define DEVIATION_H

#include "function.h"

class Deviation : public Function
{
public:
    static float calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector& data);
};

#endif // DEVIATION_H
