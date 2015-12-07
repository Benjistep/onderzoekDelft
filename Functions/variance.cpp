#include "variance.h"
#include "average.h"

float Variance::calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector &data)
{
    float sumVariance = 0.0f;
    float average = Average::calc(rowStart, rowEnd, columnStart, columnEnd, data);
    float amount = ((rowEnd - rowStart) + 1) * ((columnEnd - columnStart) + 1);

    for(int row = rowStart; row <= rowEnd; row++)
    {
        for(int column = columnStart; column <= columnEnd; column++)
        {
            float deviation = data.get(row, column) - average;
            deviation *= deviation;
            sumVariance += deviation;
        }
    }

    sumVariance /= amount;


    return sumVariance;
}
