#include "mymodel.h"
#include <iostream>

MyModel::MyModel(QObject *parent, CSVVector& data) : QAbstractTableModel(parent), modelData(data)
{
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return modelData.size();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
        return modelData.size();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    if(role == Qt::DisplayRole && row != 0)
        return modelData.getString(row, column);

    return QVariant();
}
