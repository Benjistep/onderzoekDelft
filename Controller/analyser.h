#ifndef ANALYSER_H
#define ANALYSER_H

#include <vector>
#include <QDateTime>
#include "../Model/csvvector.h"
#include <QModelIndexList>
#include "result.h"
#include "Situations/situation.h"

class Analyser
{
private:
    static map<int, vector<float>*>* selectData(CSVVector &data, QModelIndexList &indexList);
    static void calcResult(CSVVector &data, map<int, vector<float>*>* allData, vector<Result*>& resultList);
    static bool situationMatch(Situation& situation, CSVVector& data, map<int, vector<float>*>* allData);
public:
    static Situation* analyse(CSVVector& data, QModelIndexList& indexList, vector<Situation*>& situations);
};

#endif // ANALYSER_H
