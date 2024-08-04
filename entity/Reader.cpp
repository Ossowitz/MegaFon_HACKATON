#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <iomanip>

#include "Reader.h"
#include "Book.h"

using namespace std;

Reader::Reader(const string& p, const string& n, const string& id)
    : passport(p), name(n), readerID(id) {}

void Reader::display() const {
    cout << "Passport: " << passport
              << ", Name: " << name
              << ", Reader ID: " << readerID << endl;
    cout << "Borrowed Books:\n";
    for (const string& title : borrowedBookTitles) {
        cout << " - " << title << endl;
    }
}

string Reader::serialize() const {
    ostringstream oss;
    oss << passport << ";" << name << ";" << readerID << ";";
    for (const string& title : borrowedBookTitles) {
        oss << title << ",";
    }
    return oss.str();
}

Reader Reader::deserialize(const string& data) {
    istringstream iss(data);
    string passport, name, readerID, borrowedBookTitles;

    getline(iss, passport, ';');
    getline(iss, name, ';');
    getline(iss, readerID, ';');
    getline(iss, borrowedBookTitles);

    Reader reader(passport, name, readerID);

    istringstream titlesStream(borrowedBookTitles);
    string title;
    while (getline(titlesStream, title, ',')) {
        if (!title.empty()) {
            reader.borrowedBookTitles.push_back(title);
        }
    }
    return reader;
}

void Reader::borrowBook(Book& book, const string& dateToReturn) {
    borrowedBookTitles.push_back(book.title);
    book.currentBorrowerID = readerID;
    book.borrowDate = getCurrentDate();
    book.returnDate = dateToReturn;
}

void Reader::returnBook(const string& title) {
    auto it = remove(borrowedBookTitles.begin(), borrowedBookTitles.end(), title);
    if (it != borrowedBookTitles.end()) {
        borrowedBookTitles.erase(it, borrowedBookTitles.end());
    }
}

string Reader::getCurrentDate() {
    const auto now = chrono::system_clock::now();
    time_t nowTime = chrono::system_clock::to_time_t(now);
    tm nowTm;
#ifdef _WIN32
    localtime_s(&nowTm, &nowTime); // Windows
#else
    localtime_r(&nowTime, &nowTm); // Unix/Linux
#endif
    ostringstream oss;
    oss << put_time(&nowTm, "%d-%m-%Y"); // Формат: dd-mm-yyyy
    return oss.str();
}
