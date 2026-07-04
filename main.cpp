#include "LibrarySystem.hpp"

using namespace std;

int main() {
    cout << "=== Welcome to the RTU Student Library Program ===\n" << endl;

    // Create some books using smart pointers
    auto book1 = make_shared<Book>("B01", "Introduction to C++", "Bjarne Stroustrup");
    auto book2 = make_shared<Book>("B02", "Data Structures & Algorithms", "Thomas Cormen");

    // Display original library stock
    cout << "--- Current Library Catalog ---" << endl;
    book1->displayDetails();
    book2->displayDetails();

    // Create a student object
    Student student("RTU101", "Nihat Ersishen");

    // Simulating transactions
    student.borrowItem(book1);
    student.borrowItem(book1); // Error checking test

    // View student status
    student.displayBorrowed();

    // Check book status again
    cout << "\n--- Updated Library Catalog ---" << endl;
    book1->displayDetails();

    // Return the book
    student.returnItem("B01");
    student.displayBorrowed();

    return 0;
}