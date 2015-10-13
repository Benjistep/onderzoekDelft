#ifndef NAMECELL_H
#define NAMECELL_H


#include <string>
#include "Cell.h"
using namespace std;

class NameCell : public Cell {

private:
    string name;

public:
    NameCell(string& name);
    string getName() const;
    void setName(string& newName);
};

#endif // NAMECELL_H
