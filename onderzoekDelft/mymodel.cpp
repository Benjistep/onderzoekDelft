#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QAbstractTableModel(parent)
{
    QVector<QString> test;
    test.push_back("rij1henk");
    test.push_back("rij1gerrit");

    QVector<QString> test2;
    test2.push_back("rij2piet");
    test2.push_back("rij2henk");

    modelData.push_back(test);
    modelData.push_back(test2);


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

    if(role == Qt::DisplayRole)
        return modelData[row][column];

       // return modelData[row][column];
        //return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column() + 1);

    return QVariant();
}
