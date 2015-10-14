#include "View/mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "Model/mymodel.h"
#include "Controller/csvparser.h"
#include <iostream>
#include <QFileDialog>
#include <string>
#include <vector>
#include "Model/csvvector.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTableView tableView;
    MainWindow w;
    w.show();
    //QString filetemp = w.fileName();

    //CSVVector data(filetemp.toStdString().c_str(), ";");
    //MyModel* myModel = new MyModel(0, data);
    //tableView.setModel(myModel);
    //tableView.setStyleSheet("QHeaderView::section {background-color:lightgrey}");
    //tableView.adjustSize();
    //tableView.show();

    return a.exec();
}
