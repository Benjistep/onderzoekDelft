#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QString>
#include "../Model/csvvector.h"
#include "../Situations/situation.h"
#include <vector>

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

    void on_actionAnalyse_selected_cells_triggered();

    void on_ClearButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_dialPPM_valueChanged(int value);

    void on_dial_2_valueChanged(int value);

    //void on_dial_5_valueChanged(int value);

    void on_dial_3_valueChanged(int value);

    void on_buttonAddSituation_clicked();

    void on_dialTemp_valueChanged(int value);

    void on_actionHide_Selected_Cells_triggered();

    void on_actionHide_Selected_Rows_triggered();

    void on_actionShow_All_Hidden_Cells_triggered();

private:
    Ui::MainWindow *ui;
    CSVVector* csvvector;
    std::vector<Situation*>* situations;

    void refreshTableModel();
    void setColumnName(const string& newname, bool boolcol);
};

#endif // MAINWINDOW_H
