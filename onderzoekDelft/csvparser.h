#ifndef CSVPARSER_H
#define CSVPARSER_H


#include <vector>
#include <string>
#include <fstream>
#include "Cell.h"

using namespace std;

class CSVParser {

public:
    static void parseFile(ifstream* file, vector<vector<Cell*> >& data, const string& delimiter);
};

#endif // CSVPARSER_H
