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
    static bool parseFile(ifstream* file, string configFileName, vector<vector<DataCell> >& data, vector<string>& columnHeaders, vector<QDateTime>& rowHeaders, string delimiter, map<int,bool>& booleanColumns);
    static void parseConfigFile(string configFileName);
};

#endif // CSVPARSER_H
