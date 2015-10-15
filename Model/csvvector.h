#ifndef CSVVECTOR_H
#define CSVVECTOR_H

#include <vector>
#include <string>
#include <QString>
#include <QDateTime>
#include "DataCell.h"

using namespace std;

class CSVVector {
private:
    vector<vector<DataCell> > data;
    vector<string> columnHeaders;
    vector<QDateTime> rowHeaders;

public:
    CSVVector(string file, string delimiter);
    float get(int row, int column);
    QString getString(int row, int column) const;
    QString getColumnHeader(int column) const;
    QString getRowHeader(int row) const;
    int size() const;
    int rows() const;
    int columns() const;
    bool isEmpty(int row, int column) const;
    //void fillEmptyCells();
};

#endif // CSVVECTOR_H
