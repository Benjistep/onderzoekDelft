#ifndef NAMECELL_H
#define NAMECELL_H

#include "Cell.h"
using namespace std;

class NameCell : public Cell {

private:
    string name;

public:
    NameCell(string& name);
    string getName() const;
    void setName(string& newName);
    QString toString();

};

#endif // NAMECELL_H
