/**
 * @file main.cpp
 * @author Riley Pancake
 * @date 10/26/26
 */

#include "Inventory.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    // Single stack-allocated Inventory object (triggers ~Inventory() upon exit)
    Inventory store;
    int choice = 0;

    do {
        std::cout << "\n=== Book Inventory Management ===\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Remove Book by Index\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice (1-4): ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer(); // Consume newline left by std::cin >>

        switch (choice) {
            case 1: {
                std::string title;
                std::string author;
                double price = 0.0;

                std::cout << "Enter book title: ";
                std::getline(std::cin, title);

                std::cout << "Enter author name: ";
                std::getline(std::cin, author);

                std::cout << "Enter price: $";
                while (!(std::cin >> price) || price < 0.0) {
                    std::cout << "Invalid price. Please enter a non-negative number: $";
                    clearInputBuffer();
                }
                clearInputBuffer();

                // Allocate dynamically using new, transfer ownership to store
                Book* newBook = new Book(title, author, price);
                store.addBook(newBook);
                std::cout << "Book added successfully!\n";
                break;
            }
            case 2:
                store.displayAll();
                break;

            case 3: {
                int index = -1;
                std::cout << "Enter the index of the book to remove: ";
                if (std::cin >> index) {
                    store.removeBook(index);
                } else {
                    std::cout << "Invalid index format.\n";
                }
                clearInputBuffer();
                break;
            }
            case 4:
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid choice. Please choose from 1 to 4.\n";
                break;
        }

    } while (choice != 4);

    // store goes out of scope here: ~Inventory() runs automatically
    return 0;
}