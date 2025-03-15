#ifndef CLOTHING_H_
#define CLOTHING_H_



#include "Product.h"


class Clothing : public Product {
public:
   Clothing(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& size, const std::string& type)
   : Product(productId, name, "Clothing", base_price, quality, seller), size_(size), type_(type) {}

   std::string getSize() const { return size_; }
   std::string getType() const { return type_; }  
   void displayProductInfo() const override;


private:
   std::string size_;  
   std::string type_;  
};



// Clothing Subcategories
class Shirt : public Clothing {
public:
   Shirt(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& size)
   : Clothing(productId, name, base_price, quality, seller, size, "Shirt") {}  
};



class TShirt : public Shirt {
public:
   TShirt(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& size)
   : Shirt(productId, name, base_price, quality, seller, size) {}
};



class Pants : public Clothing {
public:
   Pants(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& size)
   : Clothing(productId, name, base_price, quality, seller, size, "Pants") {}  
};



class Jeans : public Pants {
public:
   Jeans(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& size)
   : Pants(productId, name, base_price, quality, seller, size) {}
};



class Shoes : public Clothing {
public:
   Shoes(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& size)
   : Clothing(productId, name, base_price, quality, seller, size, "Shoes") {}  
};



class Sneakers : public Shoes {
public:
   Sneakers(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& size)
   : Shoes(productId, name, base_price, quality, seller, size) {}
};



#endif // CLOTHING_H_