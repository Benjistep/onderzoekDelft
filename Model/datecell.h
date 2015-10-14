#ifndef DATECELL_H
#define DATECELL_H

#include "Cell.h"
#include "NameCell.h"

using namespace std;

class DateCell : public NameCell {

private:
    int day, month, year;
    void parse();

public:
    DateCell(string& date);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    QString toString();

};

#endif // DATECELL_H
