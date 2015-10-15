#ifndef DATETIMEPARSER_H
#define DATETIMEPARSER_H

#include <QDateTime>
#include <string>
#include <vector>
using namespace std;

class DateTimeParser
{
public:
    static void parseDateTime(string& date, string& time, QDateTime& output);
};

#endif // DATETIMEPARSER_H
