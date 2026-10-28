/**
* @file Book.cpp
 * @author Riley Pancake
 * @date 10/26/26
 */

#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book(const std::string& bookTitle, const std::string& bookAuthor, double bookPrice)
    : title(bookTitle), author(bookAuthor), price(bookPrice) {}

void Book::displayInfo() const {
    std::cout << "Title: \"" << title << "\" | Author: " << author
              << " | Price: $" << std::fixed << std::setprecision(2) << price << "\n";
}