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
#include "Controller/analyser.h"
#include "../Situations/Settings/co2setting.h"
#include "../Situations/Settings/airflowsetting.h"
#include "../Situations/Settings/lightsetting.h"
#include "../Situations/Settings/pirsetting.h"
#include "../Situations/Settings/temperaturesetting.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    csvvector(0),
    situations()
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
    if(csvvector)
    {
        QString filename = QFileDialog::getSaveFileName(this, tr("Save a .csv file"), "C://", ".csv files (*.csv))");
        if(filename != "")
        {
            string file = filename.toStdString();
            CSVWriter::write(*csvvector, file);
        }
        QMessageBox::information(this, tr("Save"), tr("Saved successfully!"));
    }
    else
    {
        QMessageBox::information(this, tr("Save"), tr("Nothing to save."));
    }
}

//fill empty cells
void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{
    int startuur = ui->horizontalSlider->value();
    int stopuur = ui->horizontalSlider_2->value()-1;

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
    setColumnName("CO2Sensor", false);
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

void MainWindow::on_actionAnalyse_selected_cells_triggered()
{
    if(csvvector)
    {
        csvvector->fillEmptyCells();
        refreshTableModel();

        QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();
        Situation* situation = Analyser::analyse(*csvvector, indexList, situations);

        if(situation)
        {
            QString str("Situation match!\n");
            ui->textEdit->setText(str);
            ui->textEdit->append(situation->toString());
        }
        else
        {
            QString str("UNKNOWN SITUATION!!\n");
            ui->textEdit->setText(str);
        }

    }
}

void MainWindow::on_ClearButton_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QString number = QString("%1").arg(value, 2, 10, QChar('0'));
    QString temp = QString("%1: %2:00").arg("StartTime", number);
    ui->label_2->setText(temp);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    QString number = QString("%1").arg(value, 2, 10, QChar('0'));
    QString temp = QString("%1: %2:00").arg("EndTime", number);
    ui->label_3->setText(temp);
}

void MainWindow::on_dialPPM_valueChanged(int value)
{
    ui->lcdNumberPPM->display(value);
}

void MainWindow::on_dial_2_valueChanged(int value)
{
    ui->lcdNumberPPM_2->display(value);
}

void MainWindow::on_dialTemp_valueChanged(int value)
{
    ui->lcdNumberTemperature->display(value);
}

void MainWindow::on_dial_3_valueChanged(int value)
{
    ui->lcdNumberAirflow->display(value);
}

void MainWindow::on_buttonAddSituation_clicked()
{
    //Situation name
    QString name = ui->textEditSituationName->toPlainText();
    Situation* sit = new Situation(name);

    //Co2 values --------------------------------------------------------
    int maxAcceptableC02 = (int) ui->lcdNumberPPM->value();
    int deviationC02 = (int) ui->lcdNumberPPM_2->value();
    bool C02maxAcceptViolated = ui->checkC02MaxV->isChecked();
    bool C02devViolated = ui->checkC02DevV->isChecked();
    bool C02notNull = ui->checkC02NotNull->isChecked();
    bool C02const = ui->checkC02Const->isChecked();
    CO2Setting* co2Setting = new CO2Setting(maxAcceptableC02, deviationC02, C02maxAcceptViolated, C02devViolated, C02notNull, C02const);
    QString settingName("CO2Sensor");
    sit->addSetting(co2Setting, settingName);

    //temperature values
    int maxTemperature = (int) ui->lcdNumberTemperature->value();
    bool maxTempViolated = ui->checkMaxTempV->isChecked();
    bool tempNotNull = ui->checkTempNotNull->isChecked();
    TemperatureSetting* temperatureSetting = new TemperatureSetting(maxTemperature, maxTempViolated, tempNotNull);
    settingName = "Temperature";
    sit->addSetting(temperatureSetting, settingName);

    //airflow values
    int maxAirflowDev = (int) ui->lcdNumberAirflow->value();
    bool maxAirflowDevV = ui->checkMaxAirflowV->isChecked();
    bool airflowNotNull = ui->checkAirflowNotNull->isChecked();
    AirflowSetting* airflowSetting = new AirflowSetting(maxAirflowDev, maxAirflowDevV, airflowNotNull);
    settingName = "Airflow";
    sit->addSetting(airflowSetting, settingName);

    //light values
    bool lightsOn = ui->checkLightsOn->isChecked();
    LightSetting* lightSetting = new LightSetting(lightsOn);
    settingName = "Lightstate";
    sit->addSetting(lightSetting, settingName);

    //pir values
    bool pirOn = ui->checkPirOn->isChecked();
    PIRSetting* pirSetting = new PIRSetting(pirOn);
    settingName = "PIRSensor";
    sit->addSetting(pirSetting, settingName);

    //add to situations list
    situations.push_back(sit);

    ui->textEditSituations->append(sit->toString());
}


