#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <iomanip>

#include "entity/Library.h"

using namespace std;

int main()
{
    Library library;
    const filesystem::path booksFile = "books.txt";
    const filesystem::path readersFile = "readers.txt";

    library.loadBooksFromFile(booksFile);
    library.loadReadersFromFile(readersFile);

    char choice;

    do {
        cout << "\nChoose an action:\n"
            << "1: Add Book\n"
            << "2: Add Reader\n"
            << "3: Borrow Book\n"
            << "4: Return Book\n"
            << "5: Display Books\n"
            << "6: Display Readers\n"
            << "7: Save and Exit\n"
            << "Your choice: ";
        cin >> choice;
    }
    while (choice != '7');

    return 0;
}
