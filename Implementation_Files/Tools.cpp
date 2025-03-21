#include "Header_Files/Tools.h"
#include "Header_Files/Seller.h"
#include <iostream>

void Tools::displayProductInfo() const
{

    Product::displayProductInfo();
    std::cout << "Tool Type: " << tool_type_ << std::endl;
}
