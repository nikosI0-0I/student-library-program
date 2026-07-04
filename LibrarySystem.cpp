#include "LibrarySystem.hpp"

using namespace std; // Sweeps away all the std:: prefixes!

// LibraryItem Implementation
LibraryItem::LibraryItem(string itemId, string itemTitle) 
    : id(itemId), title(itemTitle), isBorrowed(false) {}

string LibraryItem::getId() const { return id; }
string LibraryItem::getTitle() const { return title; }
bool LibraryItem::getBorrowStatus() const { return isBorrowed; }
void LibraryItem::setBorrowStatus(bool status) { isBorrowed = status; }

// Book Implementation
Book::Book(string itemId, string itemTitle, string itemAuthor)
    : LibraryItem(itemId, itemTitle), author(itemAuthor) {}

void Book::displayDetails() const {
    cout << "[Book] ID: " << id 
         << " | Title: \"" << title << "\""
         << " | Author: " << author 
         << " | Status: " << (isBorrowed ? "Borrowed ❌" : "Available ✅") 
         << endl;
}

// Student Implementation
Student::Student(string sId, string sName) : studentId(sId), name(sName) {}

string Student::getStudentId() const { return studentId; }
string Student::getName() const { return name; }

void Student::borrowItem(shared_ptr<LibraryItem> item) {
    if (!item->getBorrowStatus()) {
        item->setBorrowStatus(true);
        borrowedItems.push_back(item);
        cout << "\n🎉 " << name << " successfully borrowed: " << item->getTitle() << endl;
    } else {
        cout << "\n Error: This item is already borrowed by someone else." << endl;
    }
}

void Student::returnItem(string itemId) {
    for (auto it = borrowedItems.begin(); it != borrowedItems.end(); ++it) {
        if ((*it)->getId() == itemId) {
            (*it)->setBorrowStatus(false);
            cout << "\n✅ Successfully returned: " << (*it)->getTitle() << endl;
            borrowedItems.erase(it);
            return;
        }
    }
    cout << "\n Error: You did not borrow an item with ID " << itemId << endl;
}

void Student::displayBorrowed() const {
    cout << "\n--- Books borrowed by " << name << " ---" << endl;
    if (borrowedItems.empty()) {
        cout << "No books borrowed currently." << endl;
        return;
    }
    for (const auto& item : borrowedItems) {
        cout << "- " << item->getTitle() << " (ID: " << item->getId() << ")" << endl;
    }
}