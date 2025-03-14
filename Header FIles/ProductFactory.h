#ifndef PRODUCT_FACTORY_H_
#define PRODUCT_FACTORY_H_



#include "Product.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Furniture.h"
#include "Books.h"
#include "Tools.h"



class ProductFactory {
public:
   static Product* CreateProduct(const int productId, const std::string& category, const std::string& name, const double base_price, 
   const Quality quality, Seller* seller, const std::string& attribute1 = "", const std::string& attribute2 = "") 
   {
       if (category == "Electronics") {
           return new Electronics(productId, name, base_price, quality, seller, attribute1, attribute2); 
       } 
       else if (category == "Clothing") {
           return new Clothing(productId, name, base_price, quality, seller, attribute1, attribute2);
       } 
       else if (category == "Furniture") {
           return new Furniture(productId, name, base_price, quality, seller, attribute1, attribute2);
       } 
       else if (category == "Books") {
           return new Books(productId, name, base_price, quality, seller, attribute1, attribute2);
       } 
       else if (category == "Tools") {
           return new Tools(productId, name, base_price, quality, seller, attribute1);
       } 
       else {
           return nullptr;
       }
   }
};

#endif // PRODUCT_FACTORY_H_