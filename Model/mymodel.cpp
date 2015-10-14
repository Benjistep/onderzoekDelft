#include "mymodel.h"
#include <iostream>
#include <QBrush>
#include <QColor>
#include <QFont>

MyModel::MyModel(QObject *parent, CSVVector& data) : QAbstractTableModel(parent), modelData(data)
{

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return modelData.rows()-1;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
        return modelData.columns()-2;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row() + 1;
    int column = index.column() + 2;

    if (role == Qt::DisplayRole && !modelData.isEmpty(row,column))
        return modelData.getString(row, column);

    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    switch(role){
        case Qt::DisplayRole :
                if(orientation == Qt::Horizontal){
                    return modelData.getString(0, section+2);
                }
                else if(orientation == Qt::Vertical){
                    QString temp = modelData.getString(section + 1, 0) + " - " + modelData.getString(section + 1, 1);
                    return temp;
                }
            break;

        default:
            return QVariant();
    }

    //return QVariant();

}
