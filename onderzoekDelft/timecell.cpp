#include "timecell.h"

#include <stdlib.h>
#include "TimeCell.h"
#include "StringSplitter.h"

TimeCell::TimeCell(string& time): NameCell(time), hours(0), minutes(0), seconds(0)
{
    parse();
}

void TimeCell::parse()
 {
     string name = getName();

     vector<string> parsedStrings;

     if(name.size() == 7) {
         StringSplitter::splitString(name, ":", parsedStrings);
         hours = atoi(parsedStrings[0].c_str());
         minutes = atoi(parsedStrings[1].c_str());
         seconds = atoi(parsedStrings[2].c_str());
     }
 }

int TimeCell::getHours() const
{
    return hours;
}

int TimeCell::getMinutes() const
{
    return minutes;
}

int TimeCell::getSeconds() const
{
    return seconds;
}

