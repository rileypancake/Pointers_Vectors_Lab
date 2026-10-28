cmake_minimum_required(VERSION 4.3)
project(Pointers_Vectors_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pointers_Vectors_Lab main.cpp
        Book.h
        Book.cpp
        Inventory.h
        Inventory.cpp)
