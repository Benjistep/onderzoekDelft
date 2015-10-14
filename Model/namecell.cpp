#include "namecell.h"

#include "NameCell.h"

NameCell::NameCell(string& name) : name(name){
    if(name.size() == 0)
        setEmpty(true);
}

string NameCell::getName() const
{
    return name;
}

void NameCell::setName(string &newName)
{
    name = newName;
}

QString NameCell::toString()
{
    return QString::fromStdString(name);
}
