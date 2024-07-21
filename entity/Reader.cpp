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

