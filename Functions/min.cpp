#include "min.h"

float Min::calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector &data)
{
    float min = 0.0f;
    for(int row = rowStart; row <= rowEnd; row++)
    {
        for(int column = columnStart; column <= columnEnd; column++)
        {
            float current = data.get(row, column);
            if(current < min)
            {
                min = current;
            }
        }
    }

    return min;
}
