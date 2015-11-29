#include "sum.h"
#include <iostream>

//no error check, sorry
float Sum::calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector &data)
{
    float result = 0.0f;

    for(int row = rowStart; row <= rowEnd; row++)
    {
        for(int column = columnStart; column <= columnEnd; column++)
        {
            result += data.get(row, column);
        }
    }

    return result;
}

