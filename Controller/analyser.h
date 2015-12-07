#ifndef ANALYSER_H
#define ANALYSER_H

#include <vector>
#include <QDateTime>
#include "../Model/csvvector.h"

class Analyser
{
private:

public:
    Analyser();
    void analyse(CSVVector& data);
};

#endif // ANALYSER_H
