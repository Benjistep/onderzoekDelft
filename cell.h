#ifndef CELL_H
#define CELL_H
#include <QString>

using namespace std;

class Cell
{
public:
    virtual ~Cell() = 0;
    virtual QString toString() = 0;
};

#endif // CELL_H
