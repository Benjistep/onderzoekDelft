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
    return modelData.rows();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
        return modelData.columns();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    if (role == Qt::DisplayRole && !modelData.isEmpty(row,column))
        return modelData.getString(row, column);

    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    switch(role){
        case Qt::DisplayRole :
                if(orientation == Qt::Horizontal){
                    return modelData.getColumnHeader(section);
                }
                else if(orientation == Qt::Vertical){
                    QString temp = modelData.getRowHeader(section);
                    //cout << temp.toStdString();
                    return temp;
                }
            break;

        default:
            return QVariant();
    }

    return QVariant();

}
