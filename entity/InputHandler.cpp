#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <iomanip>

#include "InputHandler.h"

Book InputHandler::inputBook() {
    std::string title, author, genre;

    std::cout << "Enter book title: ";
    std::cin >> std::ws;
    std::getline(std::cin, title);

    std::cout << "Enter book author: ";
    std::getline(std::cin, author);

    std::cout << "Enter book genre: ";
    std::getline(std::cin, genre);

    return Book(title, author, genre);
}
