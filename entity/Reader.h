#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <iomanip>

class Book;
using namespace std;

class Reader {
public:
    string passport;
    string name;
    string readerId;
    vector<string> borrowedBookTitles;

    Reader(const string& p, const string& n, const string& id);

    void display();
    string serialize() const;
    static Reader deserialize(const string& data);
    void borrowBook(Book& book, const std::string& dateToReturn);
    void returnBook(const std::string& title);
};

#endif //READER_H
