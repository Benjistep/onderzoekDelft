#include "analyser.h"
#include "../Functions/deviation.h"
#include "../Functions/average.h"
#include "../Functions/max.h"
#include "../Functions/min.h"
#include "../Functions/sum.h"
#include "../Functions/variance.h"
#include "../Functions/count.h"
#include "result.h"
#include <iostream>
#include "../Situations/Settings/setting.h"

Situation* Analyser::analyse(CSVVector& data, QModelIndexList& indexList, vector<Situation*>& situations)
{
    //selects all data from given indexes
    map<int, vector<float>*>* allData = selectData(data, indexList);

    //declare iterator of allData
    map<int, vector<float>*>::const_iterator mapIt = allData->begin();

    Situation* tempSit = NULL;

    //loop trough all situations
    for (unsigned int index = 0; index < situations.size(); index++)
    {
        tempSit = situations[index];

        if(situationMatch(*tempSit, data, allData))
            break;
    }

    //cleanup
    //remove all vectors
    mapIt = allData->begin();
    while(mapIt != allData->end())
    {
        delete(mapIt->second);
        mapIt++;
    }

    delete allData;

    return tempSit;

}

bool Analyser::situationMatch(Situation& situation, CSVVector &data, map<int, vector<float>* >* allData)
{
    //declare iterator of allData
    map<int, vector<float>*>::const_iterator mapIt = allData->begin();

    bool match = true;

    //loop trough map
    while (mapIt != allData->end())
    {
        QString columnName = data.getColumnHeader(mapIt->first);
        Setting* tempsetting = situation.getSetting(columnName);

        if(tempsetting)
        {
            match = tempsetting->check(*(mapIt->second));
        }
        else
        {
            match = false;
        }

        //increment alldata iterator
        mapIt++;
    }

    return match;
}

//selects all data given certain indexes
map<int, vector<float>*>* Analyser::selectData(CSVVector &data, QModelIndexList &indexList)
{
     map<int, vector<float>*>* allData = new map<int, vector<float>*>;

     QModelIndexList::const_iterator it = indexList.begin();

     while(it != indexList.end())
     {
         int column = it->column();

         if(allData->find(column) != allData->end())
         {
           int row = it->row();
           (*allData)[column]->push_back(data.get(row, column));
           it++;
         }
         else
         {
             (*allData)[column] = new vector<float>;
         }
     }

     return allData;
}

/*
 //does calculations on selected data
void Analyser::calcResult(CSVVector &data, map<int, vector<float>*>* allData, vector<Result*>& resultList)
{
    map<int, vector<float>*>::const_iterator mapIt = allData->begin();
    while(mapIt != allData->end())
    {
        string name = data.getColumnHeader(mapIt->first).toStdString();
        float average = Average::calc(*mapIt->second);
        float deviation = Deviation::calc(*mapIt->second);
        float max = Max::calc(*mapIt->second);
        float min = Min::calc(*mapIt->second);
        float sum = Sum::calc(*mapIt->second);
        float variance = Variance::calc(*mapIt->second);
        int count = Count::calc(*mapIt->second);

        Result* tempResult = new Result(name, average, deviation, max, min, sum, variance, count);
        resultList.push_back(tempResult);

        mapIt++;
    }
}
*/
