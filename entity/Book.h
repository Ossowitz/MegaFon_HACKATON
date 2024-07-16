#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    string genre;
    string currentBorrowerID;
    string borrowDate;
    string returnDate;

    Book(const string &title, const string &author, const string &genre);

    void display() const;
    string serialize() const;
    static Book deserialize(const string& data);
};

#endif //BOOK_H
