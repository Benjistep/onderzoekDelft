#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "mymodel.h"
#include "csvparser.h"
#include <iostream>
#include <QFileDialog>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MainWindow w;
    //w.show();
    QString filetemp = w.fileName();



    vector<vector<Cell*> >* data = CSVParser::parseFile(new ifstream((filetemp.toStdString()).c_str()), ";");
    QString temp = QString::number(data->size());
    MyModel* myModel = new MyModel(0, *data);
    tableView.setModel(myModel);
    tableView.show();

    //vector<vector<Cell*> >* data = CSVParser::parseFile(new ifstream("D:\\Benjamin\\Desktop\\test.csv"), ";");
    //MyModel myModel(0, *data);
    //tableView.setModel(&myModel);
    //tableView.show();



    return a.exec();
}
