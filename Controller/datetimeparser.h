#ifndef DATETIMEPARSER_H
#define DATETIMEPARSER_H

#include <QDateTime>
#include <string>
#include <vector>
using namespace std;

class DateTimeParser
{
public:
    static bool parseDateTime(string& date, string& time, QDateTime& output);
private:
    static bool parseHelper(string& input, int& arg1, int& arg2, int& arg3, string delimiter);
};

#endif // DATETIMEPARSER_H
