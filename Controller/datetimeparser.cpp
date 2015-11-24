#include "datetimeparser.h"
#include "stringsplitter.h"
#include <map>

static map<string, int> months = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},  {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};

int getMonthToInt(string& month)
{
    return months[month];
}

bool DateTimeParser::parseDateTime(string &date, string& time, QDateTime& output)
{
    int day, month, year, hours, minutes, seconds;
    bool parseSuccessfull = false;
    parseSuccessfull = parseHelper(date, day, month, year, "-");
    parseSuccessfull = parseHelper(time, hours, minutes, seconds, ":");
    output = QDateTime(QDate(year, month, day), QTime(hours, minutes, seconds));

    return parseSuccessfull;
}

bool DateTimeParser::parseHelper(string& input, int& arg1, int& arg2, int& arg3, string delimiter)
{
    bool success = true;
    vector<string> parsedData;
    if(input.size() <= 10)
    {
        StringSplitter::splitString(input, delimiter, parsedData);
        if(parsedData.size() > 2){
            arg1 = atoi(parsedData[0].c_str());
            if(parsedData[1].c_str()[0] > 58)
            {
                arg2 = getMonthToInt(parsedData[1]);
            }
            else
            {
                arg2 = atoi(parsedData[1].c_str());
            }
            arg3 = atoi(parsedData[2].c_str());

        }
        else
        {
            arg1 = 0;
            arg2 = 0;
            arg3 = 0;
            success = false;
        }
    }

    return success;
}
