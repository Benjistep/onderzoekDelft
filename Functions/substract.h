#ifndef SUBSTRACT_H
#define SUBSTRACT_H

#include "Function.h"

class Substract : public Function
{
public:
    static float calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector& data);
};

#endif // SUBSTRACT_H
