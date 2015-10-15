#include "datetimeparser.h"
#include "stringsplitter.h"


void DateTimeParser::parseDateTime(string &date, string& time, QDateTime& output)
{

    int day, month, year, hours, minutes, seconds;
    vector<string> parsedDate;
    if(date.size() <= 10) {
        StringSplitter::splitString(date, "-", parsedDate);
        day = atoi(parsedDate[0].c_str());
        month = atoi(parsedDate[1].c_str());
        year = atoi(parsedDate[2].c_str());
    }

    vector<string> parsedTime;
    if(time.size() == 8) {
        StringSplitter::splitString(time, ":", parsedTime);
        hours = atoi(parsedTime[0].c_str());
        minutes = atoi(parsedTime[1].c_str());
        seconds = atoi(parsedTime[2].c_str());
    }

    output = QDateTime(QDate(year, month, day), QTime(hours, minutes, seconds));
}
