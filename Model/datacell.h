#ifndef DATACELL_H
#define DATACELL_H

using namespace std;

#include <QString>

class DataCell {
private:
    float data;
    bool empty;

public:
    DataCell(string& data);
    void setData(float data);
    float getData() const;
    QString toString() const;
    bool isEmpty() const;
    void setEmpty(bool empty);
};


#endif // DATACELL_H
