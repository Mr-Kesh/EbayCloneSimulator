#include "Electronics.h"
#include <iostream>

void Electronics::displayProductInfo() const {

    Product::displayProductInfo();
    std::cout << "Brand: " << brand_ << std::endl;
    std::cout << "Model: " << model_ << std::endl;
    
}