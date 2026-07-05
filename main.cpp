#include "LibrarySystem.hpp"

using namespace std;

int main() {
    cout << "=== Welcome to the RTU Student Library Program ===\n" << endl;

    // Create library stock
    auto book1 = make_shared<Book>("B01", "Introduction to C++", "Bjarne Stroustrup");
    auto book2 = make_shared<Book>("B02", "Data Structures & Algorithms", "Thomas Cormen");

    // Display library catalog
    cout << "--- Current Library Catalog ---" << endl;
    book1->displayDetails();
    book2->displayDetails();

    // Create user student instance
    Student student("RTU101", "Nihat Ersishen");

    // Simulating safe actions
    student.borrowItem(book1);
    student.borrowItem(book1); // Intentional error validation test

    student.displayBorrowed();

    cout << "\n--- Updated Library Catalog ---" << endl;
    book1->displayDetails();

    student.returnItem("B01");
    student.displayBorrowed();

    return 0;
}