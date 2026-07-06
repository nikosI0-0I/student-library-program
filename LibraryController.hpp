#ifndef LIBRARY_CONTROLLER_HPP
#define LIBRARY_CONTROLLER_HPP

#include "LibrarySystem.hpp"
#include <map>
#include <sstream>
#include <memory>

class LibraryController {
private:
    // Your simulated database tables
    std::map<std::string, std::shared_ptr<LibraryItem>> catalog;
    std::map<std::string, std::shared_ptr<Student>> students;

public:
    LibraryController() = default;

    void addBook(std::shared_ptr<LibraryItem> item);
    void addStudent(std::shared_ptr<Student> student);
    
    void processCatalogDisplay() const;
    void processBorrow(const std::string& studentId, const std::string& itemId);
    void processReturn(const std::string& studentId, const std::string& itemId);
    void processStudentDashboard(const std::string& studentId) const;

    // Fixed: Now correctly loops through 'catalog' and converts it to JSON strings
    std::string getCatalogDataJson() {
        std::stringstream json;
        json << "[";
        bool first = true;
        
        for (const auto& pair : catalog) {
            if (!first) json << ",";
            json << "{\"id\":\"" << pair.second->getId() << "\","
                 << "\"title\":\"" << pair.second->getTitle() << "\"}";
            // Note: Since LibraryItem is abstract, we fetch ID and Title here.
            first = false;
        }
        json << "]";
        return json.str();
    }
};

#endif // LIBRARY_CONTROLLER_HPP