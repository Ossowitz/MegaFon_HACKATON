#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <iomanip>

#include "Library.h"

using namespace std;

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addReader(const Reader& reader) {
    readers.push_back(reader);
}

void Library::loadBooksFromFile(const filesystem::path& filepath) {
    ifstream file(filepath);
    string line;

    books.clear();
    while (getline(file, line)) {
        if (!line.empty()) {
            books.push_back(Book::deserialize(line));
        }
    }
}

void Library::loadReadersFromFile(const filesystem::path& filepath) {
    ifstream file(filepath);
    string line;

    readers.clear();
    while (getline(file, line)) {
        if (!line.empty()) {
            readers.push_back(Reader::deserialize(line));
        }
    }
}

void Library::saveBooksToFile(const filesystem::path& filepath) const {
    ofstream file(filepath);
    for (const auto& book : books) {
        file << book.serialize() << endl;
    }
}

void Library::saveReadersToFile(const filesystem::path& filepath) const {
    ofstream file(filepath);
    for (const auto& reader : readers) {
        file << reader.serialize() << endl;
    }
}

void Library::displayBooks() const {
    cout << "Books in Library:\n";
    for (const auto& book : books) {
        book.display();
    }
}

void Library::displayReaders() const {
    cout << "Readers in Library:\n";
    for (const auto& reader : readers) {
        reader.display();
    }
}