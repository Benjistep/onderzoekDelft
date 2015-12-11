#ifndef RESULT_H
#define RESULT_H

#include <string>

class Result
{
private:
    std::string name;
    float average;
    float deviation;
    float max;
    float min;
    float sum;
    float variance;
    int count;


public:
    Result(const std::string& name, float average, float deviation, float max, float min, float sum, float variance, int count);
    float getAverage();
    float getDeviation();
    float getMax();
    float getMin();
    float getSum();
    float getVariance();
    int getCount();
    std::string getName();
    const std::string toString();
};

#endif // RESULT_H
