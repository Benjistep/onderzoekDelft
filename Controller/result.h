#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <vector>

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
    int   count;
    void  calc(std::vector<float>& data);

public:
    Result(std::vector<float>& data, std::string name);
    float getAverage();
    float getDeviation();
    float getMax();
    float getMin();
    float getSum();
    float getVariance();
    int   getCount();
    const std::string toString();
};

#endif // RESULT_H
