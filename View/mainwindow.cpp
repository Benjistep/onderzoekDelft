#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <string>
#include <vector>
#include <QTableView>
#include "../Model/mymodel.h"
#include "../Controller/csvparser.h"
#include <iostream>
#include "../Controller/csvwriter.h"
#include <fstream>
#include <QDateTime>
#include <QMessageBox>
#include "Controller/deviation.h"
#include "Controller/sum.h"
#include "Controller/variance.h"
#include "Controller/average.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    csvvector(0)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_File_triggered()
{
    //selecteer file
    QString filename = QFileDialog::getOpenFileName(this, tr("Select a .csv file"), "C://", ".csv files (*.csv))");
    //als er geen file gekozen is
    if(filename != "")
    {
        string file = filename.toStdString();
        string delim = ";";
        CSVVector* data = new CSVVector(file, delim);
        csvvector = data;
        MyModel* model = new MyModel(0, *data);

        ui->tableView->setStyleSheet("QHeaderView::section {background-color:lightgrey}");
        ui->tableView->setModel(model);

        //update spinbox
        ui->spinBox->setMinimum(1);
        ui->spinBox->setMaximum(csvvector->columns() - 1);


        map<int, bool> booleanColumns = csvvector->getBooleanColumns();
        map<int, bool>::const_iterator it = booleanColumns.begin();

        while(it != booleanColumns.end())
        {
            ui->comboBox->addItem(QString::number(it->first));
            it++;
        }

        //show messagebox
        string message = "";
        if(csvvector->parsedSuccessfully())
            message = "File added successfully!";
        else
            message = "File added with errors. File may be corrupted.";

        QMessageBox::information(this, tr("File add"), tr(message.c_str()));
    }

}

void MainWindow::on_actionTest_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionSafe_data_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save a .csv file"), "C://", ".csv files (*.csv))");
    if(filename != "")
    {
        string file = filename.toStdString();
        CSVWriter::write(*csvvector, file);
    }
}

//fill empty cells
void MainWindow::on_pushButton_clicked()
{
    if(csvvector){
        csvvector->fillEmptyCells();
        MyModel* model = new MyModel(0, *csvvector);
        ui->tableView->setModel(model);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(csvvector){
        csvvector->setBooleanColumn(ui->spinBox->value());
        ui->comboBox->addItem(QString::number(ui->spinBox->value()));
    }
}

//safe settings
void MainWindow::on_pushButton_3_clicked()
{
    if(csvvector){
        ofstream writer;
        writer.open("config.txt");

        map<int, bool> booleanColumns = csvvector->getBooleanColumns();
        map<int, bool>::const_iterator it = booleanColumns.begin();

        while(it != booleanColumns.end())
        {
            writer << it->first << endl;
            it++;
        }
    }
}

//remove
void MainWindow::on_pushButton_4_clicked()
{

    if(csvvector){
        int column = ui->spinBox->value();
        csvvector->removeBooleanColumn(column);
        for(int i = 0; i < ui->comboBox->count(); i++)
        {
            if(ui->comboBox->itemText(i) == QString::number(column))
                ui->comboBox->removeItem(i);
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    int startuur = ui->horizontalSlider->value();
    int stopuur = ui->horizontalSlider_2->value();

    if(csvvector){
        vector<QDateTime> rowHeaders = csvvector->getRowHeaders();
        for(int i = 0; i < csvvector->rows(); i++)
        {
            if(rowHeaders[i].toString("hh").toInt() < startuur)
            {
                ui->tableView->hideRow(i);
            }
            else if(rowHeaders[i].toString("hh").toInt() > stopuur)
            {
                ui->tableView->hideRow(i);
            }
            else if(ui->tableView->isRowHidden(i))
            {
                ui->tableView->showRow(i);
            }
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    cout << "Som" << Sum::calc(380, 392, 0, 0, *csvvector) << endl;
    cout << "Gemiddelde" << Average::calc(380, 392, 0, 0, *csvvector) << endl;
    cout << "Variantie" << Variance::calc(380, 392, 0, 0, *csvvector) << endl;
    cout << "Deviatie" << Deviation::calc(380, 392, 0, 0, *csvvector) << endl;
}
