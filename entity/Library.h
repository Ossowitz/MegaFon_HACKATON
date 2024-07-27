#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include <filesystem>
#include "Book.h"
#include "Reader.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Reader> readers;

public:
    void addBook(const Book& book);
    void addReader(const Reader& reader);
    void loadBooksFromFile(const std::filesystem::path& filepath);
    void loadReadersFromFile(const std::filesystem::path& filepath);
    void saveBooksToFile(const std::filesystem::path& filepath) const;
    void saveReadersToFile(const std::filesystem::path& filepath) const;
    void displayBooks() const;
    void displayReaders() const;
    Book* findBook(const std::string& title);
    Reader* findReader(const std::string& id);
};

#endif //LIBRARY_H
