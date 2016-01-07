#include <iostream>
#include "CSVVector.h"
#include "../Controller/CSVParser.h"
#include "DataCell.h"

CSVVector::CSVVector(): data(), columnHeaders(), rowHeaders(), booleanColumns(), success(true) {}

CSVVector::CSVVector(string file, string delimiter)
{
    success = CSVParser::parseFile(new ifstream(file.c_str()), data, columnHeaders, rowHeaders, delimiter);
}

float CSVVector::get(int row, int column)
{
    if(elementExists(row, column))
        return data[row][column].getData();
    else
        return numeric_limits<double>::quiet_NaN();
}

void CSVVector::set(int row, int column, float value)
{
    if(elementExists(row, column))
    {
        data[row][column].setData(value);
        data[row][column].setEmpty(false);
    }
}

int CSVVector::rows() const
{
    return data.size();
}

int CSVVector::columns() const
{
    if(rows() >= 1)
        return data[0].size();
    else
        return 0;
}

int CSVVector::size() const
{
     return rows() * columns();
}

bool CSVVector::isEmpty(int row, int column) const
{
    if(elementExists(row, column))
        return data[row][column].isEmpty();
    else
        return false;
}

QString CSVVector::getString(int row, int column) const
{
    if(elementExists(row, column))
        return data[row][column].toString();
    else
        return QString("Not available");
}

QString CSVVector::getColumnHeader(int column) const
{
    if((unsigned int)column >= columnHeaders.size() || (unsigned int)column + 2 >= columnHeaders.size())
        return QString("Not available");
    else
        return QString::fromStdString(columnHeaders[column+2]);
}

void CSVVector::setColumnHeader(int column, const string& newname)
{
    if(columnHeaders.size() > 2)
        columnHeaders[column+2] = newname;
}

QString CSVVector::getRowHeader(int row) const
{
    if((unsigned int)row >= rowHeaders.size())
        return QString("Not available");
    else
        return rowHeaders[row].toString("ddd d MMMM yy - hh:mm");
}

const vector<vector<DataCell> >& CSVVector::getData() const
{
    return data;
}

const vector<string>& CSVVector::getColumnHeaders() const
{
    return columnHeaders;
}

const vector<QDateTime>& CSVVector::getRowHeaders() const
{
    return rowHeaders;
}

void CSVVector::fillEmptyCells()
{
    //vul bij alle kolommen behalve de eerste twee alle lege velden
    for(int column = 0; column < columns(); column++)
    {
        if(isBooleanColumn(column))
            fillBooleanColumn(column);
        else
            fillColumn(column);
    }
}

bool CSVVector::isBooleanColumn(int column)
{
    if((unsigned int)column >= booleanColumns.size())
        return false;
    else
        return booleanColumns[column];
}

void CSVVector::setBooleanColumn(int column)
{
    booleanColumns[column] = true;
}

void CSVVector::removeBooleanColumn(int column)
{
    map<int, bool>::iterator it = booleanColumns.find(column);

    if(it != booleanColumns.end())
        booleanColumns.erase(it);
}

const map<int, bool>& CSVVector::getBooleanColumns() const
{
    return booleanColumns;
}

void CSVVector::fillBooleanColumn(int column)
{
    for(int row = 0; row < rows(); row++)
    {
        float opvulWaarde = 0.0;
        if(isEmpty(row, column))
        {

            if(row == 0)
            {
              set(row, column, opvulWaarde);
            }
            else if(row > 0)
            {
                opvulWaarde = get(row - 1, column);
                set(row, column, opvulWaarde);
            }
        }
        else if(get(row, column) > 0.0)
        {
            opvulWaarde = 1.0;
            set(row, column, opvulWaarde);
        }
    }
}

void CSVVector::fillColumn(int column)
{
    for(int row = 0; row < rows(); row++)
    {
        float opvulWaarde = 0.0;
        if(isEmpty(row, column))
        {
            if(row == 0)
            {
                set(row, column, opvulWaarde);
            }
            else if (row < (rows() - 1) && !isEmpty(row + 1, column))
            {
                //opvulwaarde wordt gemiddelde van waarde van de rij erboven en de eerst volgende gevulde rij eronder
                opvulWaarde = (get(row - 1, column) + get(row + 1, column)) / 2;
                set(row, column, opvulWaarde);
            }
            //laatste element van de rij
            else if (row == (rows() - 1) || (row < (rows() - 1) && isEmpty(row + 1, column)))
            {
                opvulWaarde = get(row - 1, column);
                set(row, column, opvulWaarde);
            }
        }
    }
}

void CSVVector::removeRow(int row)
{

    if((unsigned int)row >= data.size())
    {
        data.erase(data.begin() + row);
    }
}

bool CSVVector::elementExists(int row, int column) const
{
    bool exists = true;
    if((unsigned int)row >= data.size())
        exists = false;
    else if((unsigned int)column >= data[row].size())
        exists = false;

    return exists;
}

bool CSVVector::parsedSuccessfully()
{
    return success;
}
