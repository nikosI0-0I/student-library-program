#include "crow_all.h"            
#include "LibrarySystem.cpp"     
#include "LibraryController.cpp" 
#include <limits>

using namespace std;

int main() {
    crow::SimpleApp app; 
    LibraryController controller;

    // Populate Initial Mock Data
    controller.addBook(make_shared<Book>("B01", "Introduction to C++", "Bjarne Stroustrup"));
    controller.addBook(make_shared<Book>("B02", "Data Structures & Algorithms", "Thomas Cormen"));
    controller.addStudent(make_shared<Student>("RTU101", "Nihat Ersishen"));

    // Route 1: Browse Catalog (Existing)
    CROW_ROUTE(app, "/api/catalog")([&](){
        return controller.getCatalogDataJson(); 
    });

    // Route 2: Borrow an Item
    CROW_ROUTE(app, "/api/borrow/<string>/<string>")([&](string studentId, string itemId){
        // Process internal logic
        controller.processBorrow(studentId, itemId);
        return crow::response(200, "{\"status\":\"success\", \"message\":\"Processed borrow request check console details.\"}");
    });

    // Route 3: Return an Item
    CROW_ROUTE(app, "/api/return/<string>/<string>")([&](string studentId, string itemId){
        controller.processReturn(studentId, itemId);
        return crow::response(200, "{\"status\":\"success\", \"message\":\"Processed return request check console details.\"}");
    });

    // Start the server on port 18080
    app.port(18080).multithreaded().run();
    
    return 0;
}