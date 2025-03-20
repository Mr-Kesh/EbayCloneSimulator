#include <iostream>
#include "Header_Files/Driver.h"

int main()
{
    // Get the singleton instance of the Driver
    Driver *driver = Driver::getInstance();

    // Run the application
    driver->run();

    return 0;
}