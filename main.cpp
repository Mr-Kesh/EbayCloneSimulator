#include <iostream>
#include "Header_Files/Driver.h"

int main()
{
    // Get the singleton instance of the Driver
    Driver *driver = Driver::getInstance();
    driver->loadUsers();
    driver->loadProducts();

    // Run the application
    driver->run();

    return 0;
}