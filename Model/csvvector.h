#ifndef CSVVECTOR_H
#define CSVVECTOR_H

#include <vector>
#include <string>
#include <QString>
#include <QDateTime>
#include "DataCell.h"
#include <map>

using namespace std;

class CSVVector {
private:
    vector<vector<DataCell> > data;
    vector<string> columnHeaders;
    vector<QDateTime> rowHeaders;
    map<int, bool> booleanColumns;

    bool success;

    bool isBooleanColumn(int column);
    void fillBooleanColumn(int column);
    void fillColumn(int column);
    bool elementExists(int row, int column) const;

public:
    CSVVector(string file, string delimiter);
    float get(int row, int column);
    void set(int row, int column, float value);
    QString getString(int row, int column) const;
    QString getColumnHeader(int column) const;
    QString getRowHeader(int row) const;
    const map<int, bool>& getBooleanColumns() const;
    const vector<vector<DataCell> >& getData() const;
    const vector<string>& getColumnHeaders() const;
    const vector<QDateTime>& getRowHeaders() const;
    int size() const;
    int rows() const;
    int columns() const;
    bool isEmpty(int row, int column) const;
    void fillEmptyCells();
    void setBooleanColumn(int column);
    void removeBooleanColumn(int column);
    void removeRow(int row);
    bool parsedSuccessfully();
};

#endif // CSVVECTOR_H
