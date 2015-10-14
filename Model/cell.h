#ifndef CELL_H
#define CELL_H
#include <QString>

using namespace std;

class Cell
{
public:
    virtual ~Cell() = 0;
    virtual QString toString() = 0;
    bool isEmpty() const;
    void setEmpty(bool empty);

private:
    bool empty;
};

#endif // CELL_H
