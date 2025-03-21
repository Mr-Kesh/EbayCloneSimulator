#include "Header_Files/ProductFactory.h"
#include "Header_Files/Product.h"

// This file is needed to ensure proper linking, but the inline implementation in the header
// contains the main functionality. Just to be sure attributes are set properly, we'll add
// a function to set attributes on generic Product objects.

void ProductFactory::SetAttributesOnProduct(Product *product, const std::string &attribute1, const std::string &attribute2)
{
    if (product)
    {
        product->setAttribute1(attribute1);
        product->setAttribute2(attribute2);
    }
}
