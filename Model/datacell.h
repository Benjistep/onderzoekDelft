#ifndef DATACELL_H
#define DATACELL_H

#include "Cell.h"
using namespace std;

class DataCell : public Cell{
private:
    float data;

public:
    DataCell(string& data);
    float getData() const;
    QString toString();
};


#endif // DATACELL_H
