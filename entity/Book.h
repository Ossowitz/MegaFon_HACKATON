#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string genre;
    string currentBorrowerID;
    string borrowDate;
    string returnDate;

public:
    Book(const string &title, const string &author, const string &genre);

    void display() const;
    string serialize() const;
    static Book deserialize(const string& data);

    void setTitle(const string& t);
    void setAuthor(const string& a);
    void setGenre(const string& g);
    void setCurrentBorrowerID(const string& id);
    void setBorrowDate(const string& date);
    void setReturnDate(const string& date);

    string getTitle() const;
    string getAuthor() const;
    string getGenre() const;
    string getCurrentBorrowerID() const;
    string getBorrowDate() const;
    string getReturnDate() const;
};

#endif // BOOK_H
