#include "filter.h"

CSVVector& Filter::run(CSVVector &data)
{
    CSVVector* copyVector = new CSVVector(data);

    return *copyVector;
}
