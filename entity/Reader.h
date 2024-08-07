#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

class Book;
using namespace std;

class Reader {
public:
    Reader(const string& p, const string& n, const string& id);

    void display() const;
    string serialize() const;
    static Reader deserialize(const string& data);
    void borrowBook(Book& book, const string& dateToReturn);
    void returnBook(const string& title);

    string getPassport() const;
    string getName() const;
    string getReaderID() const;
    const vector<string>& getBorrowedBookTitles() const;

    void setPassport(const string& p);
    void setName(const string& n);
    void setReaderID(const string& id);

private:
    string passport;
    string name;
    string readerID;
    vector<string> borrowedBookTitles;

    static string getCurrentDate();
};

#endif // READER_H
