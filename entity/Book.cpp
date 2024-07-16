#include "Book.h"

#include <iostream>

using namespace std;

Book::Book(const string& title, const string& author, const string& genre)
    : title(title), author(author), genre(genre) {}

void Book::display() const {
    cout << "Title: " << title
    << ", Author: " << author
    << ", Genre: " << genre;
}
