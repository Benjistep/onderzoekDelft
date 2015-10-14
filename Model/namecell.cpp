#include "namecell.h"

#include "NameCell.h"

NameCell::NameCell(string& name) : name(name){ }

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
    return QString("test");
}
