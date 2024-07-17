#include "Book.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <iomanip>


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

string Book::serialize() const {
    ostringstream oss;
    oss << title << ";" << author << ";" << genre << ";"
        << currentBorrowerID << ";" << borrowDate << ";" << returnDate;
    return oss.str();
}

