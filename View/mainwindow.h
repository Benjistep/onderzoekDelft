#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QString>
#include "../Model/csvvector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionAdd_File_triggered();

    void on_actionTest_triggered();

    void on_actionExit_triggered();

    void on_actionSafe_data_triggered();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_actionCO2_Sensor_triggered();

    void on_actionPIR_Sensor_triggered();

    void on_actionAirflow_triggered();

    void on_actionLightstate_triggered();

    void on_actionTemperature_triggered();

    void on_actionFill_Empty_Cells_triggered();

private:
    Ui::MainWindow *ui;
    CSVVector* csvvector;
    void refreshTableModel();
    void setColumnName(const string& newname, bool boolcol);
};

#endif // MAINWINDOW_H
