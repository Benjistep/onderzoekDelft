#include "analyser.h"
#include "../Functions/deviation.h"
#include "../Functions/average.h"
#include "../Functions/max.h"
#include "../Functions/min.h"
#include "../Functions/sum.h"
#include "../Functions/variance.h"
#include "result.h"
#include <iostream>

void Analyser::analyse(CSVVector &data, QModelIndexList &indexList, vector<Result*>& resultList)
{

    map<int, vector<float>*> allData;
    QModelIndexList::const_iterator it = indexList.begin();

    while(it != indexList.end())
    {
        int column = it->column();

        if(allData.find(column) != allData.end())
        {
          int row = it->row();
          allData[column]->push_back(data.get(row, column));
          it++;
        }
        else
        {
            allData[column] = new vector<float>;
        }
    }

    map<int, vector<float>*>::const_iterator mapIt = allData.begin();
    while(mapIt != allData.end())
    {
        string name = data.getColumnHeader(mapIt->first).toStdString();
        float average = Average::calc(*mapIt->second);
        float deviation = Deviation::calc(*mapIt->second);
        float max = Max::calc(*mapIt->second);
        float min = Min::calc(*mapIt->second);
        float sum = Sum::calc(*mapIt->second);
        float variance = Variance::calc(*mapIt->second);

        Result* tempResult = new Result(name, average, deviation, max, min, sum, variance);
        resultList.push_back(tempResult);

        mapIt++;
    }

    //remove all vectors
    mapIt = allData.begin();
    while(mapIt != allData.end())
    {
        delete(mapIt->second);
        mapIt++;
    }

}
