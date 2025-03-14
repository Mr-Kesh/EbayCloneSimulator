#include <iostream>
#include "Implementation Files/Driver.cpp"

int main(){

    // Get the Singleton instance of Driver
    Driver* driver = Driver::getInstance();

    // Load data from CSV files
    driver->loadUsers("users.csv");
    driver->loadProducts("products.csv");

    // Start the game
    driver->run(); 

    return 0;
}