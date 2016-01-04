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
    int size = indexList.size();

    if(size == 0)
        return NULL;

    //selects all data from given indexes
    map<int, vector<float>*>* allData = selectData(data, indexList);

    //declare iterator of allData
    map<int, vector<float>*>::const_iterator mapIt = allData->begin();

    Situation* tempSit = NULL;
    Situation* checkSit = NULL;

    //loop trough all situations
    for (unsigned int index = 0; index < situations.size(); index++)
    {
        checkSit = situations[index];

        if(situationMatch(*checkSit, data, allData))
        {
            tempSit = checkSit;
            break;
        }
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
    std::cout << "Check situation" << std::endl;
    //loop trough map
    while (mapIt != allData->end())
    {
        std::cout << "hier" << std::endl;
        QString columnName = data.getColumnHeader(mapIt->first);
        Setting* tempsetting = situation.getSetting(columnName);

        if(tempsetting)
        {
            match = tempsetting->check(*(mapIt->second));
            std::cout << "setting name: " << tempsetting->toString().toStdString() << std::endl;
            std::cout << "match setting: " << match << std::endl;

        }
        else
        {
            match = false;
        }

        //increment alldata iterator
        mapIt++;

        if(!match)
            break;
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
