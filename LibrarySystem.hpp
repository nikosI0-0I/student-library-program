#ifndef LIBRARY_SYSTEM_HPP
#define LIBRARY_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Base abstract class for library items (Abstraction)
class LibraryItem {
protected:
    std::string id;
    std::string title;
    bool isBorrowed;

public:
    LibraryItem(std::string itemId, std::string itemTitle);
    virtual ~LibraryItem() = default;

    // Pure virtual function (Polymorphism)
    virtual void displayDetails() const = 0; 

    std::string getId() const;
    std::string getTitle() const;
    bool getBorrowStatus() const;
    void setBorrowStatus(bool status);
};

// Derived Book class (Inheritance)
class Book : public LibraryItem {
private:
    std::string author;

public:
    Book(std::string itemId, std::string itemTitle, std::string itemAuthor);
    void displayDetails() const override;
};

// Student Class managing items (Data Structures)
class Student {
private:
    std::string studentId;
    std::string name;
    std::vector<std::shared_ptr<LibraryItem>> borrowedItems;

public:
    Student(std::string sId, std::string sName);
    std::string getStudentId() const;
    std::string getName() const;
    
    void borrowItem(std::shared_ptr<LibraryItem> item);
    void returnItem(std::string itemId);
    void displayBorrowed() const;
};

#endif // LIBRARY_SYSTEM_HPP