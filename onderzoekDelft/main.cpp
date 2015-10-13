#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "mymodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MyModel myModel(0);
    tableView.setModel(&myModel);
    tableView.show();
    MainWindow w;
    w.show();


    return a.exec();
}
