#include <stdlib.h>
#include <iostream>
#include "DataCell.h"
#include <algorithm>

DataCell::DataCell(string &dataInput) : data(0), empty(true)
{
    if(dataInput.size() != 0)
        setEmpty(false);

    replace(dataInput.begin(), dataInput.end(), ',', '.');

    data = atof(dataInput.c_str());
}

float DataCell::getData() const
{
    return data;
}

void DataCell::setData(float data)
{
    this->data = data;
}

QString DataCell::toString() const
{
    return QString::number(data);
}

bool DataCell::isEmpty() const
{
    return empty;
}


void DataCell::setEmpty(bool empty){
    this->empty = empty;
}
