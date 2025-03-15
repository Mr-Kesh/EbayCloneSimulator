#include "Clothing.h"
#include <iostream>

void Clothing::displayProductInfo() const {
    // Basic implementation for Deliverable 2
    Product::displayProductInfo();
    std::cout << "Size: " << size_ << std::endl;
    std::cout << "Type: " << type_ << std::endl;
}
