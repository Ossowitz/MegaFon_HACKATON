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

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addReader(const Reader& reader) {
    readers.push_back(reader);
}

