#include "CSVParser.h"
#include "StringSplitter.h"
#include "NameCell.h"
#include "DateCell.h"
#include "TimeCell.h"
#include "DataCell.h"

void CSVParser::parseFile(ifstream* file, vector<vector<Cell*> >& data, const string& delimiter)
{
    string line;
    //get all column names;
    getline((*file), line, '\n');
    vector<string> tempVector;
    StringSplitter::splitString(line, delimiter, tempVector);
    vector<Cell*> columnNames;
    for(unsigned int i = 0; i < tempVector.size(); i++)
    {
        columnNames.push_back(new NameCell(tempVector[i]));
    }

    //adds columnNames to dataVector
    data.push_back(columnNames);


    //gets rest of file
    while(getline((*file), line, '\n'))
    {
        vector<string> tempVector;
        //splits line into multiple strings puts in to tempVector
        StringSplitter::splitString(line, delimiter, tempVector);

        //temp cellVector (1 row)
        vector<Cell*> cellVector;
        //adds datecell and timecell to row
        cellVector.push_back(new DateCell(tempVector[0]));
        cellVector.push_back(new TimeCell(tempVector[1]));

        ////adds other cells as data
        for(unsigned int i = 2; i < tempVector.size(); i++)
        {
            cellVector.push_back(new DataCell(tempVector[i]));
        }

        //adds row to datavector
        data.push_back(cellVector);
    }

}
