#include "result.h"

Result::Result(const std::string &name, float average, float deviation, float max, float min, float sum, float variance, int count):
    name(name),
    average(average),
    deviation(deviation),
    max(max),
    min(min),
    sum(sum),
    variance(variance),
    count(count)
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

int Result::getCount()
{
    return count;
}

std::string Result::getName()
{
    return name;
}

const std::string Result::toString()
{
    std::string result = "-----------------------------------------------------------------------------------------------------------------------\n"
            + name + '\n';
    result += "Count: " + std::to_string(count) + '\n';
    result += "Min: " + std::to_string(min) + '\n';
    result += "Max: " + std::to_string(max) + '\n';
    result += "Sum: " + std::to_string(sum) + '\n';
    result += "Average: " + std::to_string(average) + '\n';
    result += "Deviation: " + std::to_string(deviation) + '\n';
    result += "Variance: " + std::to_string(variance) + '\n';

    return result;
}
