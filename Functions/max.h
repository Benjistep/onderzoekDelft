#ifndef MAX_H
#define MAX_H

#include "function.h"

class Max : public Function
{
public:
    static float calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector& data);
};

#endif // MAX_H
