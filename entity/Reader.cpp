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

Reader::Reader(const std::string& p, const std::string& n, const std::string& id)
    : passport(p), name(n), readerID(id) {}
