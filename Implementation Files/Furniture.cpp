#include "Furniture.h"
#include <iostream>

void Furniture::displayProductInfo() const {

    Product::displayProductInfo();
    std::cout << "Material: " << material_ << std::endl;
    std::cout << "Type: " << type_ << std::endl;
    
}
