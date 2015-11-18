#include "datetimeparser.h"
#include "stringsplitter.h"

void DateTimeParser::parseDateTime(string &date, string& time, QDateTime& output)
{
    int day, month, year, hours, minutes, seconds;
    parseHelper(date, day, month, year, "-");
    parseHelper(time, hours, minutes, seconds, ":");
    output = QDateTime(QDate(year, month, day), QTime(hours, minutes, seconds));
}

void DateTimeParser::parseHelper(string& input, int& arg1, int& arg2, int& arg3, string delimiter)
{
    vector<string> parsedData;
    if(input.size() <= 10) {
        StringSplitter::splitString(input, delimiter, parsedData);
        arg1 = atoi(parsedData[0].c_str());
        arg2 = atoi(parsedData[1].c_str());
        arg3 = atoi(parsedData[2].c_str());
    }
}
