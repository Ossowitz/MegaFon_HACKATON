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
                std::string readerID, bookTitle, returnDate;
                std::cout << "Enter reader ID: ";
                std::cin >> readerID;
                std::cout << "Enter book title: ";
                std::cin >> std::ws; // Очищаем пробелы
                std::getline(std::cin, bookTitle);
                std::cout << "Enter return date (dd-mm-yyyy): ";
                std::getline(std::cin, returnDate);
                Reader* reader = library.findReader(readerID);
                if (Book* book = library.findBook(bookTitle); reader && book && book->getCurrentBorrowerID().empty()) {
                    reader->borrowBook(*book, returnDate);
                } else {
                    std::cout << "Error: Book is already borrowed or Reader not found." << std::endl;
                }
                break;
            }
            case '4': {
                std::string readerID, bookTitle;
                std::cout << "Enter reader ID: ";
                std::cin >> readerID;
                std::cout << "Enter book title: ";
                std::cin >> std::ws;
                std::getline(std::cin, bookTitle);
                if (Reader* reader = library.findReader(readerID)) {
                    reader->returnBook(bookTitle);
                    if (Book* book = library.findBook(bookTitle)) {
                        book->setCurrentBorrowerID("");
                        book->setBorrowDate("");
                        book->setReturnDate("");
                    }
                } else {
                    std::cout << "Reader not found." << std::endl;
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
                std::cout << "Data saved!" << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice, try again." << std::endl;
        }
    }
    while (choice != '7');

    return 0;
}
