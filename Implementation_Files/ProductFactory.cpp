#include "Header_Files/ProductFactory.h"
#include "Header_Files/Product.h"

Product *ProductFactory::CreateProduct(int productId, const std::string &name, const std::string &category, double basePrice, Quality quality, Seller *seller, const std::string &attribute1, const std::string &attribute2)
{
    Product *product = new Product(productId, name, category, basePrice, quality, seller);

    // Set the attributes
    product->setAttribute1(attribute1);
    product->setAttribute2(attribute2);

    return product;
}
