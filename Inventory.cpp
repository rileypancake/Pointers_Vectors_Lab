/**
* @file Inventory.cpp
 * @author Riley Pancake
 * @date 10/26/26
 */

#include "Inventory.h"
#include <iostream>

// Destructor: loops through vector, frees each dynamically allocated Book pointer
Inventory::~Inventory() {
    std::cout << "\n[RAII Cleanup] Invoking Inventory destructor: releasing allocated memory...\n";
    for (Book* b : books) {
        delete b;
    }
    books.clear();
}

void Inventory::addBook(Book* bookPtr) {
    if (bookPtr != nullptr) {
        books.push_back(bookPtr);
    }
}

void Inventory::displayAll() const {
    if (books.empty()) {
        std::cout << "Inventory is currently empty.\n";
        return;
    }

    std::cout << "\n--- Current Inventory ---\n";
    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << "[" << i << "] ";
        books[i]->displayInfo();
    }
    std::cout << "-------------------------\n";
}

void Inventory::removeBook(int index) {
    if (index < 0 || index >= static_cast<int>(books.size())) {
        std::cout << "Error: Invalid index. No book removed.\n";
        return;
    }

    // Free memory before removing pointer from vector
    delete books[index];
    books.erase(books.begin() + index);
    std::cout << "Book successfully deleted and removed from inventory.\n";
}