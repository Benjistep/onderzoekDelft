#ifndef ANALYSER_H
#define ANALYSER_H

#include <vector>
#include <QDateTime>
#include "../Model/csvvector.h"
#include <QModelIndexList>
#include "result.h"

class Analyser
{
private:

public:
    static void analyse(CSVVector& data, QModelIndexList& indexList, vector<Result*>& resultList);
};

#endif // ANALYSER_H
