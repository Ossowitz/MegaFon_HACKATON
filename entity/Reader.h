#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

class Book;
using namespace std;

class Reader {
public:
    string passport;
    string name;
    string readerID;
    vector<string> borrowedBookTitles;

    Reader(const string& p, const string& n, const string& id);

    void display() const;
    string serialize() const;
    static Reader deserialize(const string& data);
    void borrowBook(Book& book, const string& dateToReturn);
    void returnBook(const string& title);

private:
    static string getCurrentDate();
};

#endif // READER_H
