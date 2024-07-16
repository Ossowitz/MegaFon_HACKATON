cmake_minimum_required(VERSION 3.29)
project(LibraryAutomation__)

set(CMAKE_CXX_STANDARD 23)

add_executable(LibraryAutomation__ main.cpp
        entity/Book.cpp
        entity/Book.h)
