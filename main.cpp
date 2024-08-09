#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "entity/Library.h"

using namespace std;

int main() {
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

        switch (choice) {
            case '1': {
                Book newBook = Library::inputBook();
                library.addBook(newBook);
                break;
            }
            case '2': {
                Reader newReader = Library::inputReader();
                library.addReader(newReader);
                break;
            }
            case '3': {
                string readerID, bookTitle, returnDate;
                cout << "Enter reader ID: ";
                cin >> readerID;
                cout << "Enter book title: ";
                cin >> ws; // Очищаем пробелы
                getline(cin, bookTitle);
                cout << "Enter return date (dd-mm-yyyy): ";
                getline(cin, returnDate);
                Reader* reader = library.findReader(readerID);
                if (Book* book = library.findBook(bookTitle); reader && book && book->getCurrentBorrowerID().empty()) {
                    reader->borrowBook(*book, returnDate);
                } else {
                    cout << "Error: Book is already borrowed or Reader not found." << endl;
                }
                break;
            }
            case '4': {
                string readerID, bookTitle;
                cout << "Enter reader ID: ";
                cin >> readerID;
                cout << "Enter book title: ";
                cin >> ws;
                getline(cin, bookTitle);
                if (Reader* reader = library.findReader(readerID)) {
                    reader->returnBook(bookTitle);
                    if (Book* book = library.findBook(bookTitle)) {
                        book->setCurrentBorrowerID("");
                        book->setBorrowDate("");
                        book->setReturnDate("");
                    }
                } else {
                    cout << "Reader not found." << endl;
                }
                break;
            }
            case '5': {
                library.displayBooks();
                break;
            }
            case '6': {
                library.displayReaders();
                break;
            }
            case '7': {
                library.saveBooksToFile(booksFile);
                library.saveReadersToFile(readersFile);
                cout << "Data saved!" << endl;
                break;
            }
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
    while (choice != '7');

    return 0;
}
