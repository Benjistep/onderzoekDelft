#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <QDateTime>
#include "../Model/datacell.h"
#include <map>

using namespace std;

class CSVParser {

public:
    static bool parseFile(ifstream* file, vector<vector<DataCell> >& data, vector<string>& columnHeaders, vector<QDateTime>& rowHeaders, string delimiter);
};

#endif // CSVPARSER_H
