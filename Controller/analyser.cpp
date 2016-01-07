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

Situation* Analyser::analyse(CSVVector& data, QModelIndexList& indexList, vector<Situation*>& situations, map<int, Result*>& results)
{
    int size = indexList.size();

    if(size == 0)
        return NULL;

    //selects all data from given indexes
    map<int, vector<float>*> allData = selectData(data, indexList);

    //performs multiple calculations per column, per column 1 Result
    results = calcResults(allData, data);

    Situation* tempSit = NULL;
    Situation* checkSit = NULL;

    //loop trough all situations
    for (unsigned int index = 0; index < situations.size(); index++)
    {
        checkSit = situations[index];

        if(situationMatch(*checkSit, data, results))
        {
            tempSit = checkSit;
            break;
        }
    }


    return tempSit;
}

//checks if preprogrammed situation is similar to current situation
bool Analyser::situationMatch(Situation& situation, CSVVector &data, map<int, Result*>& results)
{
    //declare iterator of allData
    map<int, Result*>::iterator mapIt = results.begin();

    bool match = true;
    std::cout << "Check situation" << std::endl;
    //loop trough map
    while (mapIt != results.end())
    {
        QString columnName = data.getColumnHeader(mapIt->first);
        Setting* tempsetting = situation.getSetting(columnName);

        if(tempsetting)
            match = tempsetting->check(*(mapIt->second));
        else
            match = false;

        //increment alldata iterator
        mapIt++;

        if(!match)
            break;
    }

    return match;
}

//calculates for every column some functions. 1 result per column
map<int, Result*> Analyser::calcResults(map<int, vector<float>*>& data, CSVVector &CSVdata)
{
    map<int, Result*> results;

    map<int, vector<float>*>::iterator dataIt = data.begin();

    int i = 0;
    while(dataIt != data.end())
    {
        vector<float>* tempData = dataIt->second;
        std::string name = CSVdata.getColumnHeader(i).toStdString();
        results[i] = new Result(*tempData, name);
        i++;
        dataIt++;
    }

    return results;
}

//selects all data given certain indexes
map<int, vector<float>*> Analyser::selectData(CSVVector &data, QModelIndexList &indexList)
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

     return allData;
}

