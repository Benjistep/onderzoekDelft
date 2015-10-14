#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include "csvvector.h"

using namespace std;

class MyModel : public QAbstractTableModel
{
public:
    MyModel(QObject *parent, CSVVector& modelData);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
private:
    CSVVector modelData;
};

#endif // MYMODEL_H
