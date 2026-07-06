#include "LibraryController.hpp"

using namespace std;

void LibraryController::addBook(shared_ptr<LibraryItem> item) {
    catalog[item->getId()] = item;
}

void LibraryController::addStudent(shared_ptr<Student> student) {
    students[student->getStudentId()] = student;
}

void LibraryController::processCatalogDisplay() const {
    cout << "\n--- Current Library Catalog Stock ---" << endl;
    for (const auto& pair : catalog) {
        pair.second->displayDetails();
    }
}

void LibraryController::processBorrow(const string& studentId, const string& itemId) {
    if (students.find(studentId) == students.end()) {
        cout << "\n❌ Error: Student Profile not found." << endl;
        return;
    }
    if (catalog.find(itemId) == catalog.end()) {
        cout << "\n❌ Error: Book ID not recognized in system registry." << endl;
        return;
    }
    
    students[studentId]->borrowItem(catalog[itemId]);
}

void LibraryController::processReturn(const string& studentId, const string& itemId) {
    if (students.find(studentId) == students.end()) {
        cout << "\n❌ Error: Student Profile not found." << endl;
        return;
    }
    students[studentId]->returnItem(itemId);
}

void LibraryController::processStudentDashboard(const string& studentId) const {
    if (students.find(studentId) == students.end()) {
        cout << "\n❌ Error: Student Profile not found." << endl;
        return;
    }
    students.at(studentId)->displayBorrowed();
}