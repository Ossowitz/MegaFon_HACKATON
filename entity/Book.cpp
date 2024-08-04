#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "Book.h"

using namespace std;

Book::Book(const string& t, const string& a, const string& g)
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

string Book::serialize() const {
    ostringstream oss;
    oss << title << ";" << author << ";" << genre << ";"
        << currentBorrowerID << ";" << borrowDate << ";" << returnDate;
    return oss.str();
}

Book Book::deserialize(const string& data) {
    istringstream iss(data);
    string title, author, genre, borrowerId, bDate, rDate;

    getline(iss, title, ';');
    getline(iss, author, ';');
    getline(iss, genre, ';');
    getline(iss, borrowerId, ';');
    getline(iss, bDate, ';');
    getline(iss, rDate);

    Book book(title, author, genre);

    book.currentBorrowerID = borrowerId;
    book.borrowDate = bDate;
    book.returnDate = rDate;

    return book;
}