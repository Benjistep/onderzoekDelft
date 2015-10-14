#include <stdlib.h>
#include "DateCell.h"
#include "StringSplitter.h"

DateCell::DateCell(string &date) : NameCell(date), day(0), month(0), year(0)
{
    parse();
}

void DateCell::parse()
{
    string date = getName();

    vector<string> parsedStrings;

    if(date.size() == 8) {
        StringSplitter::splitString(date, "-", parsedStrings);
        day = atoi(parsedStrings[0].c_str());
        month = atoi(parsedStrings[1].c_str());
        year = atoi(parsedStrings[2].c_str());
    }
}

int DateCell::getDay() const
{
    return day;
}

int DateCell::getMonth() const
{
    return month;
}

int DateCell::getYear() const
{
    return year;
}

QString DateCell::toString()
{
    QString temp = QString::number(day) + "-" + QString::number(month) + "-" + QString::number(year);
    return temp;
}

