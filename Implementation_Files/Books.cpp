#include "Header_Files/Books.h"
#include "Header_Files/Seller.h"
#include <iostream>

void Books::displayProductInfo() const
{
    Product::displayProductInfo();
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "Genre: " << genre_ << std::endl;
}
