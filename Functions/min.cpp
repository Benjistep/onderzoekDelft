#include "min.h"

float Min::calc(std::vector<float>& data)
{
    float min = 0.0f;
    for(unsigned int row = 0; row < data.size(); row++)
    {
        float current = data[row];
        if(current < min)
        {
            min = current;
        }

    }

    return min;
}
