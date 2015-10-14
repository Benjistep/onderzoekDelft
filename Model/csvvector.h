#ifndef CSVVECTOR_H
#define CSVVECTOR_H

#include <vector>
#include <string>
#include <QString>
#include "Cell.h"

using namespace std;

class CSVVector {
private:
    vector<vector<Cell*> > data;

public:
    CSVVector(string file, string delimiter);
    float get(int row, int column);
    vector<double> getRow(int row);
    vector<double> getColumn(int column);
    QString getString(int row, int column) const;
    int size() const;
    int rows() const;
    int columns() const;
    bool isEmpty(int row, int column) const;
};

#endif // CSVVECTOR_H
