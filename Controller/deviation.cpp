#include "deviation.h"
#include "variance.h"
#include "math.h"

float Deviation::calc(int rowStart, int rowEnd, int columnStart, int columnEnd, CSVVector& data)
{
    return sqrt(Variance::calc(rowStart, rowEnd, columnStart, columnEnd, data));
}
