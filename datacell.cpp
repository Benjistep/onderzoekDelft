#include <stdlib.h>
#include <iostream>
#include "DataCell.h"

DataCell::DataCell(string &dataInput) : data(0)
{
    data = atof(dataInput.c_str());
}

float DataCell::getData() const
{
    return data;
}

QString DataCell::toString()
{
    return QString::number(data);
}
