/**
* @file Book.h
 * @author [Riley Pancake]
 * @date [10/26/26]
 */

#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    // Constructor
    Book(const std::string& bookTitle, const std::string& bookAuthor, double bookPrice);

    // Displays formatted book details
    void displayInfo() const;
};

#endif // BOOK_H