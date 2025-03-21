#include "Header_Files/Books.h"
#include "Header_Files/Seller.h"
#include <iostream>

// Books class implementation
void Books::displayProductInfo() const
{
    // Basic implementation for Deliverable 2
    Product::displayProductInfo();
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "Genre: " << genre_ << std::endl;
}
