#include "Book.h"

#include <iostream>

using namespace std;

Book::Book(const std::string& t, const std::string& a, const std::string& g)
    : title(t), author(a), genre(g), currentBorrowerID(""), borrowDate(""), returnDate("") {}

void Book::display() const {
    cout << "Title: " << title
    << ", Author: " << author
    << ", Genre: " << genre;

    if (currentBorrowerID.empty()) {
        cout << ", Status: Available" << endl;
    } else {
        cout << ", Status: Currently borrowed by Reader ID: " << currentBorrowerID
        << ", Borrowed on: " << borrowDate
        << ", Return by: " << returnDate << endl;
    }
}
