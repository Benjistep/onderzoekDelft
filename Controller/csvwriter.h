#ifndef CSVWRITER
#define CSVWRITER

#include "../Model/csvvector.h"

class CSVWriter {
public:
    static void write(CSVVector& csvvector, string outputFileName);
};

#endif // CSVWRITER

