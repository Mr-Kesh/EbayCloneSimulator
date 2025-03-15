#include "Tools.h"
#include <iostream>

void Tools::displayProductInfo() const {

    Product::displayProductInfo();
    std::cout << "Tool Type: " << tool_type_ << std::endl;
    
}
