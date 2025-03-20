#include <iostream>
#include "Header_Files/Driver.h"

int main()
{
    // Get the singleton instance of the Driver
    Driver *driver = Driver::getInstance();

    // Load data from CSV files
    driver->loadUsers("users.csv");
    driver->loadProducts("products.csv");

    // Start the game
    driver->run();

    return 0;
}