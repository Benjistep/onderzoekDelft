#include "average.h"
#include "sum.h"

float Average::calc(std::vector<float>& data)
{
    float sum = Sum::calc(data);
    float amount = data.size();
    float average = sum / amount;
    return average;
}
