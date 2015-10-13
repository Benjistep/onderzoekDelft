#include "mymodel.h"
#include <iostream>

MyModel::MyModel(QObject *parent, vector<vector<Cell*> >& data) : QAbstractTableModel(parent), modelData(data)
{
    std::cout<<"my model aangemaakt";
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    //return dataModel.
    return modelData.size();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    if (modelData.size() >= 1)
        return modelData[0].size();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    if(role == Qt::DisplayRole && row != 0)
        return modelData[row][column]->toString();


    return QVariant();
}
