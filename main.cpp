#include "View/mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDateTime>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
