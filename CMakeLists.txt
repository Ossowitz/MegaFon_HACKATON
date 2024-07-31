cmake_minimum_required(VERSION 3.29)
project(LibraryAutomation)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryAutomation main.cpp
        entity/Book.cpp
        entity/Book.h
        entity/Reader.cpp
        entity/Reader.h
        entity/Library.cpp
        entity/Library.h
        entity/InputHandler.cpp
        entity/InputHandler.h
)
