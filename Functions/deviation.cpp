#include "deviation.h"
#include "variance.h"
#include "math.h"

float Deviation::calc(std::vector<float>& data)
{
    return sqrt(Variance::calc(data));
}
