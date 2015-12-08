#include "result.h"

Result::Result(const std::string &name, float average, float deviation, float max, float min, float sum, float variance):
    name(name),
    average(average),
    deviation(deviation),
    max(max),
    min(min),
    sum(sum),
    variance(variance)
{

}

float Result::getAverage()
{
    return average;
}

float Result::getDeviation()
{
    return deviation;
}

float Result::getMax()
{
    return max;
}

float Result::getMin()
{
    return min;
}

float Result::getSum()
{
    return sum;
}

float Result::getVariance()
{
    return variance;
}
