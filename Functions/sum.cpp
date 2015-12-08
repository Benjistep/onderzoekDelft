#include "sum.h"
#include <iostream>

//no error check, sorry
float Sum::calc(std::vector<float>& data)
{
    float result = 0.0f;

    for(unsigned int row = 0; row < data.size(); row++)
    {
        result += data[row];
    }

    return result;
}

