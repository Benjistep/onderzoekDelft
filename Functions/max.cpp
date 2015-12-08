#include "max.h"

float Max::calc(std::vector<float>& data)
{
    float max = 0.0f;
    for(unsigned int row = 0; row < data.size(); row++)
    {
       float current = data[row];
       if(current > max)
       {
           max = current;
       }
    }

    return max;
}

