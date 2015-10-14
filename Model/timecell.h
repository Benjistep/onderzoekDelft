#ifndef TIMECELL_H
#define TIMECELL_H

#include "Cell.h"
#include "NameCell.h"

using namespace std;

class TimeCell : public NameCell {

private:
    int hours, minutes, seconds;
    void parse();

public:
    TimeCell(string& time);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    QString toString();
};

#endif // TIMECELL_H
