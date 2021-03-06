#include <stdlib.h>
#include "CSVParser.h"
#include "StringSplitter.h"
#include "../Model/DataCell.h"
#include "datetimeparser.h"
#include <iostream>


void CSVParser::parseConfigFile(string file)
{
    /*if(!ifstream(file.c_str()))
    {
        cout << "new config file created!";
        ofstream newFile;
        newFile.open(file.c_str());
    }

    string line;
    ifstream configFile(file.c_str());
    while(getline(configFile, line, '\n'))
    {
        int temp = atoi(line.c_str());
        booleanColumns[temp] = true;
    }*/
}

bool CSVParser::parseFile(ifstream* file, string configFileName, vector<vector<DataCell> >& data, vector<string>& columnHeaders, vector<QDateTime>& rowHeaders, string delimiter, map<int,bool>& booleanColumns)
{
    bool success = true;
    parseConfigFile(configFileName);

    string line;
    //get all column names;
    getline((*file), line, '\n');
    StringSplitter::splitString(line, delimiter, columnHeaders);

    //gets rest of file
    while(getline((*file), line, '\n'))
    {
        vector<string> tempVector;
        //splits line into multiple strings puts in to tempVector
        StringSplitter::splitString(line, delimiter, tempVector);

        //adds datecell and timecell to rowHeaders
        QDateTime dateTime;
        success = DateTimeParser::parseDateTime(tempVector[0], tempVector[1], dateTime);
        rowHeaders.push_back(dateTime);

        vector<DataCell> tempData;
        //adds other cells as data
        for(unsigned int i = 2; i < tempVector.size(); i++)
            tempData.push_back(DataCell(tempVector[i]));

        data.push_back(tempData);
    }

    return success;
}


