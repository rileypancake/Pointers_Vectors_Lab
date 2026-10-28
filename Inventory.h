/**
* @file Inventory.h
 * @author Riley Pancake
 * @date 10/26/26
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <vector>

class Inventory {
private:
    std::vector<Book*> books;

public:
    // Default constructor
    Inventory() = default;

    // Destructor (RAII: cleans up all dynamically allocated Book pointers)
    ~Inventory();

    // Prevent inadvertent shallow copying of owned raw pointers
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    // Core methods specified in the assignment
    void addBook(Book* bookPtr);
    void displayAll() const;
    void removeBook(int index);
};

#endif // INVENTORY_H