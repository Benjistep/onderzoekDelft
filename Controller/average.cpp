#include "average.h"
#include "sum.h"

float Average::calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector &data)
{
    float sum = Sum::calc(rowStart, rowEnd, columnStart, columnEnd, data);
    float amount = ((rowEnd - rowStart) + 1) * ((columnEnd - columnStart) + 1 );
    float average = sum / amount;

    return average;
}
