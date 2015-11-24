#include <QDateTime>
#include <vector>
#include "../Model/datacell.h"
#include "csvwriter.h"
#include <fstream>
#include <iostream>

void CSVWriter::write(CSVVector &csvvector, string outputFileName)
{
    ofstream writer;
    writer.open(outputFileName);

    const vector<vector<DataCell> > data = csvvector.getData();
    const vector<string> columnHeaders = csvvector.getColumnHeaders();
    const vector<QDateTime> rowHeaders = csvvector.getRowHeaders();

    for(int row = 0; row < csvvector.rows() + 1; row++)
    {
        for(int column = 0; column < csvvector.columns() + 1; column++)
        {
            if(row == 0)
            {
                writer << columnHeaders[column] << ";";
            }
            else
            {
                if(column == 0)
                {
                    writer << rowHeaders[row - 1].toString("dd-M-yy;hh:mm:ss;").toStdString();
                }
                else if(column > 1)
                {
                    writer << data[row - 1][column - 2].getData() << ";";
                }
            }
        }
        writer << endl;
    }
}
