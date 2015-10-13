#ifndef DATACELL_H
#define DATACELL_H


#include <string>
#include "Cell.h"
using namespace std;

class DataCell : public Cell{
private:
    float data;

public:
    DataCell(string& data);
    float getData() const;
};


#endif // DATACELL_H
