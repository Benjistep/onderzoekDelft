#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <string>
#include <vector>
#include <QTableView>
#include "mymodel.h"
#include "csvparser.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    filename = QFileDialog::getOpenFileName(this, tr("Select a .csv file"), "C://", ".csv files (*.csv))");

}

MainWindow::~MainWindow()
{
    delete ui;
    //HALLLLLLLLLLLLOOOOOOOOOOOoo

}

QString MainWindow::fileName()
{
    return filename;
}

void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::on_pushButton_2_clicked()
{
}

