#include "variance.h"
#include "average.h"

float Variance::calc(std::vector<float>& data)
{
    float sumVariance = 0.0f;
    float average = Average::calc(data);
    float amount = data.size();

    for(int row = 0; row < amount; row++)
    {
        float deviation = data[row] - average;
        deviation *= deviation;
        sumVariance += deviation;
    }

    sumVariance /= amount;

    return sumVariance;
}
