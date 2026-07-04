#ifndef LIBRARY_SYSTEM_HPP
#define LIBRARY_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ==========================================
// 1. ABSTRACTION: Base Class for all Items
// ==========================================
class LibraryItem {
protected:
    std::string id;
    std::string title;
    bool isBorrowed;

public:
    LibraryItem(std::string itemId, std::string itemTitle) 
        : id(itemId), title(itemTitle), isBorrowed(false) {}
        
    virtual ~LibraryItem() = default; // Virtual destructor for safe dynamic memory

    // Pure virtual function making this a truly abstract class
    virtual void displayDetails() const = 0; 

    // Getters and Setters
    std::string getId() const { return id; }
    std::string getTitle() const { return title; }
    bool getBorrowStatus() const { return isBorrowed; }
    void setBorrowStatus(bool status) { isBorrowed = status; }
};

// ==========================================
// 2. INHERITANCE: Specific Book Type
// ==========================================
class Book : public LibraryItem {
private:
    std::string author;

public:
    Book(std::string itemId, std::string itemTitle, std::string itemAuthor)
        : LibraryItem(itemId, itemTitle), author(itemAuthor) {}

    // Overriding the abstract method
    void displayDetails() const override {
        std::cout << "[Book] ID: " << id 
                  << " | Title: " << title 
                  << " | Author: " << author 
                  << " | Status: " << (isBorrowed ? "Borrowed" : "Available") 
                  << std::endl;
    }
};

// ==========================================
// 3. STUDENT CLASS
// ==========================================
class Student {
private:
    std::string studentId;
    std::string name;
    std::vector<std::shared_ptr<LibraryItem>> borrowedItems; // Vector Data Structure

public:
    Student(std::string sId, std::string sName) : studentId(sId), name(sName) {}

    std::string getStudentId() const { return studentId; }
    std::string getName() const { return name; }

    void borrowItem(std::shared_ptr<LibraryItem> item) {
        if (!item->getBorrowStatus()) {
            item->setBorrowStatus(true);
            borrowedItems.push_back(item);
            std::cout << name << " successfully borrowed: " << item->getTitle() << std::endl;
        } else {
            // Future step: Implement custom exception handling here!
            std::cout << "Error: Item is already borrowed." << std::endl;
        }
    }
};

#endif // LIBRARY_SYSTEM_HPP