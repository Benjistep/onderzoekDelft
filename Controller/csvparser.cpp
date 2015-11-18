#include <stdlib.h>
#include "CSVParser.h"
#include "StringSplitter.h"
#include "../Model/DataCell.h"
#include "datetimeparser.h"

void CSVParser::parseFile(ifstream* file, vector<vector<DataCell> >& data, vector<string>& columnHeaders, vector<QDateTime>& rowHeaders, string& delimiter)
{
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
        DateTimeParser::parseDateTime(tempVector[0], tempVector[1], dateTime);
        rowHeaders.push_back(dateTime);

        vector<DataCell> tempData;
        //adds other cells as data
        for(unsigned int i = 2; i < tempVector.size(); i++)
            tempData.push_back(DataCell(tempVector[i]));

        data.push_back(tempData);
    }
}
