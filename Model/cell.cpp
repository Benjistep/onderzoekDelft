#include "cell.h"
#include <string>

using namespace std;

Cell::~Cell()
{
}

bool Cell::isEmpty() const
{
    return empty;
}


void Cell::setEmpty(bool empty){
    this->empty = empty;
}
