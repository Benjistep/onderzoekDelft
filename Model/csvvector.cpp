#include <iostream>
#include "CSVVector.h"
#include "../Controller/CSVParser.h"
#include "DataCell.h"

CSVVector::CSVVector(string file, string delimiter)
{
    CSVParser::parseFile(new ifstream(file.c_str()),data, delimiter);
}

float CSVVector::get(int row, int column)
{

    //return data[row][column]->;
    return 0;
}

vector<double> CSVVector::getRow(int row)
{
    vector<double> rij;

    for(unsigned int column = 2; column < data[row+1].size(); column++) {
        rij.push_back(((DataCell *) data[row + 1][column])->getData());
    }

    return rij;
}

vector<double> CSVVector::getColumn(int column)
{
    vector<double> columnData;

    for(unsigned int i = 1; i < data.size(); i++)
        columnData.push_back(((DataCell*)data[i][column+2])->getData());

    return columnData;
}

int CSVVector::size() const
{
    int sum = 0;
    for(unsigned int i = 0; i < data.size(); i++)
        sum += data[i].size();

    return sum;
}

int CSVVector::rows() const
{
    return data.size();
}

int CSVVector::columns() const
{
    return data[0].size();
}

bool CSVVector::isEmpty(int row, int column) const
{
    return data[row][column]->isEmpty();
}

QString CSVVector::getString(int row, int column) const
{
    return data[row][column]->toString();
}
