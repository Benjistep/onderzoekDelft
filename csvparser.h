#ifndef CSVPARSER_H
#define CSVPARSER_H


#include <vector>
#include <string>
#include <fstream>
#include "Cell.h"

using namespace std;

class CSVParser {

public:
    static vector<vector<Cell*> >* parseFile(ifstream* file, const string& delimiter);
};

#endif // CSVPARSER_H
