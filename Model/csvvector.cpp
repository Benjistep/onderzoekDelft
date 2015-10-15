#include <iostream>
#include "CSVVector.h"
#include "../Controller/CSVParser.h"
#include "DataCell.h"

CSVVector::CSVVector(string file, string delimiter)
{
    CSVParser::parseFile(new ifstream(file.c_str()), data, columnHeaders, rowHeaders, delimiter);
}

float CSVVector::get(int row, int column)
{
    return data[row][column].getData();
}

int CSVVector::rows() const
{
    return data.size();
}

int CSVVector::columns() const
{
    if(rows() >= 1)
        return data[0].size();
    else
        return 0;
}

int CSVVector::size() const
{
     return rows() * columns();
}

bool CSVVector::isEmpty(int row, int column) const
{
    return data[row][column].isEmpty();
}

QString CSVVector::getString(int row, int column) const
{
    return data[row][column].toString();
}

QString CSVVector::getColumnHeader(int column) const
{
    return QString::fromStdString(columnHeaders[column+2]);
}

QString CSVVector::getRowHeader(int row) const
{
    return rowHeaders[row].toString("ddd d MMMM yyyy - hh:mm");
}

/*
void CSVVector::fillEmptyCells()
{
    cout << "empty: " << isEmpty(376, 3) << endl;
    cout << "empty: " << isEmpty(377, 3) << endl;
    cout << "empty: " << isEmpty(378, 3) << endl;
    //vul bij alle kolommen behalve de eerste twee alle lege velden
    for(int column = 2; column < columns(); column++)
    {
        //controleer eerst of er alleen 0 of 1 (PIR) waardes ingevuld moeten worden of verschillende waardes C02
      bool booleanCell = true;
      //loop de volledige kolom door van boven naar beneden
      for(int row = 1; row < rows(); row++)
      {
          float tempData = ((DataCell*)data[row][column])->getData();
          //if(column == 3 && (tempData == 1.0 || tempData == 0.0))
             // cout << row << endl;

          if(!(tempData == 0.0 || tempData == 1.0) && column == 3){
              booleanCell = false;
              cout << column << " r " << row << endl;
          }
      }

      //vul de lege cellen met een 1 of een nul
      if(booleanCell){
          cout << "hoi" << column << endl;
          for(int row = 1; row < rows(); row++)
          {
              if(isEmpty(row, column))
              {
                  if(column == 3 && row <= 500)
                  cout << "row " << row << " column " << column << endl;
                  if(row == 1)
                  {
                       // cout << "hoi" << column << " r: " << row<<  endl;
                      ((DataCell*)data[row][column])->setData(0.0);
                       data[row][column]->setEmpty(false);
                  }
                  else
                  {
                      ((DataCell*)data[row][column])->setData(((DataCell*)data[row-1][column])->getData());
                      data[row][column]->setEmpty(false);
                  }
              }

          }
      }

    }
}
*/
