#include "crow_all.h"            
#include "LibrarySystem.cpp"     
#include "LibraryController.cpp" 
#include <limits>

using namespace std;

int main() {
    crow::SimpleApp app; 
    LibraryController controller;

    // Populate data
    controller.addBook(make_shared<Book>("B01", "Introduction to C++", "Bjarne Stroustrup"));
    controller.addBook(make_shared<Book>("B02", "Data Structures & Algorithms", "Thomas Cormen"));
    controller.addStudent(make_shared<Student>("RTU101", "Nihat Ersishen"));

    // Route: Sends your book data straight to your browser app
    CROW_ROUTE(app, "/api/catalog")([&](){
        return controller.getCatalogDataJson(); 
    });

    // Start the server on port 18080
    app.port(18080).multithreaded().run();
    
    return 0;
}