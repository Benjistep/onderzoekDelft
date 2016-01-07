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
    static map<int, vector<float>*> selectData(CSVVector &data, QModelIndexList &indexList);
    static map<int, Result*> calcResults(map<int, vector<float>*>& data, CSVVector& CSVdata);
    static bool situationMatch(Situation& situation, CSVVector& data, map<int, Result*>& results);

public:
    static Situation* analyse(CSVVector& data, QModelIndexList& indexList, vector<Situation*>& situations, map<int, Result*>& results);
};

#endif // ANALYSER_H
