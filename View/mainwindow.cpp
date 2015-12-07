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
#include "Functions/deviation.h"
#include "Functions/sum.h"
#include "Functions/variance.h"
#include "Functions/average.h"

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

}

void MainWindow::on_pushButton_5_clicked()
{
    int startuur = ui->horizontalSlider->value();
    int stopuur = ui->horizontalSlider_2->value();

    bool noweekends = ui->checkBox->isChecked();

    if(csvvector){
        vector<QDateTime> rowHeaders = csvvector->getRowHeaders();
        for(int i = 0; i < csvvector->rows(); i++)
        {
            int hour = rowHeaders[i].time().hour();
            int weekendDay = (rowHeaders[i].date().dayOfWeek() >= 6);
            bool rowHidden = ui->tableView->isRowHidden(i);
            bool smallerThanStart = hour < startuur;
            bool biggerThanStop = hour > stopuur;

            if(smallerThanStart)
            {
                ui->tableView->hideRow(i);
            }
            else if(biggerThanStop)
            {
                ui->tableView->hideRow(i);
            }
            else if(rowHidden)
            {
                ui->tableView->showRow(i);
            }

            if(noweekends)
            {
                if(weekendDay)
                {
                    ui->tableView->hideRow(i);
                }
            }
            else if(!noweekends && rowHidden && weekendDay &&
                    !smallerThanStart && !biggerThanStop)
            {
                ui->tableView->showRow(i);
            }
        }
    }

}

void MainWindow::on_pushButton_6_clicked()
{
}

void MainWindow::on_actionCO2_Sensor_triggered()
{
    setColumnName("C02Sensor", false);
}

void MainWindow::on_actionPIR_Sensor_triggered()
{
    setColumnName("PIRSensor", true);
}

void MainWindow::on_actionAirflow_triggered()
{
    setColumnName("Airflow", false);
}

void MainWindow::on_actionLightstate_triggered()
{
    setColumnName("Lightstate", true);
}

void MainWindow::on_actionTemperature_triggered()
{
    setColumnName("Temperature", false);
}

void MainWindow::refreshTableModel()
{
    MyModel* model = new MyModel(0, *csvvector);
    ui->tableView->setModel(model);
}

void MainWindow::setColumnName(const string &newname, bool boolcol)
{
    if (csvvector){
        QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();

        int column = indexList.begin()->column();

        csvvector->setColumnHeader(column, newname);

        refreshTableModel();

        if(boolcol)
            csvvector->setBooleanColumn(column);
        else
            csvvector->removeBooleanColumn(column);
    }
}

void MainWindow::on_actionFill_Empty_Cells_triggered()
{
    if(csvvector){
        csvvector->fillEmptyCells();
        refreshTableModel();
    }
}
