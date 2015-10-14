#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "mymodel.h"
#include "csvparser.h"
#include <iostream>
#include <QFileDialog>
#include <string>
#include <vector>
#include "csvvector.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MainWindow w;
    //w.show();
    QString filetemp = w.fileName();

    CSVVector data(filetemp.toStdString().c_str(), ";");
    MyModel* myModel = new MyModel(0, data);
    tableView.setModel(myModel);
    tableView.show();

    return a.exec();
}
