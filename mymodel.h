#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <vector>
#include <QString>
#include "Cell.h"

using namespace std;

class MyModel : public QAbstractTableModel
{
public:
    MyModel(QObject *parent, vector<vector<Cell*> >& data);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
private:
    vector<vector<Cell*> > modelData;
};

#endif // MYMODEL_H
