#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <string>
#include <vector>
#include <QTableView>
#include "../Model/mymodel.h"
#include "../Controller/csvparser.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_File_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select a .csv file"), "C://", ".csv files (*.csv))");
    CSVVector data(filename.toStdString().c_str(), ";");
    //data.fillEmptyCells();
    MyModel* model = new MyModel(0, data);

    ui->tableView->setStyleSheet("QHeaderView::section {background-color:lightgrey}");
    ui->tableView->setModel(model);
}

void MainWindow::on_actionTest_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
