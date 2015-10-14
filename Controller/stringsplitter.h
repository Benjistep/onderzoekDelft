#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H


#include <vector>
#include <string>

using namespace std;

class StringSplitter {
public:
    static void splitString(const string& input, const string& delimiter, vector<string>& output);
};

#endif // STRINGSPLITTER_H
