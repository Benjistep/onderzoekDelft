#include "result.h"
#include "../Functions/average.h"
#include "../Functions/deviation.h"
#include "../Functions/count.h"
#include "../Functions/max.h"
#include "../Functions/min.h"
#include "../Functions/sum.h"
#include "../Functions/variance.h"

Result::Result(std::vector<float>& data, std::string name) :
    name(name)
{
    calc(data);
}

void Result::calc(std::vector<float>& data)
{
    average = Average::calc(data);
    deviation = Deviation::calc(data);
    max = Max::calc(data);
    min = Min::calc(data);
    sum = Sum::calc(data);
    variance = Variance::calc(data);
    count = Count::calc(data);
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


const std::string Result::toString()
{
    std::string result = "-----" + name + "-----\n";
    result += "Count: " + std::to_string(count) + '\n';
    result += "Min: " + std::to_string(min) + '\n';
    result += "Max: " + std::to_string(max) + '\n';
    result += "Sum: " + std::to_string(sum) + '\n';
    result += "Average: " + std::to_string(average) + '\n';
    result += "Deviation: " + std::to_string(deviation) + '\n';
    result += "Variance: " + std::to_string(variance) + '\n';

    return result;
}
