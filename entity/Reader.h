#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Reader {
public:
    string passport;
    string name;
    string readerId;
    vector<string> borrowedBookTitles;
};

#endif //READER_H
