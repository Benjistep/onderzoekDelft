#include "max.h"

float Max::calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector &data)
{
    float max = 0.0f;
    for(int row = rowStart; row <= rowEnd; row++)
    {
        for(int column = columnStart; column <= columnEnd; column++)
        {
            float current = data.get(row, column);
            if(current > max)
            {
                max = current;
            }
        }
    }

    return max;
}

