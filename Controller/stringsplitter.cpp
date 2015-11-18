#include <iostream>
#include "StringSplitter.h"

//splits "input" at "delimiter" and puts string pieces in "output:"
void StringSplitter::splitString(const string& input, const string& delimiter, vector<string>& output)
{
    unsigned int highposition = 0, lowposition = 0;
    do{
        //finds position of delimiter char in input, starting at lowposition
        highposition = input.find(delimiter, lowposition);

        //pushes substring back to output vector
        output.push_back(input.substr(lowposition, highposition - lowposition));

        //sets lowposition to a new starting point
        lowposition = highposition + delimiter.size();

        //loop while not at and of string
    }while(highposition != string::npos);
}
