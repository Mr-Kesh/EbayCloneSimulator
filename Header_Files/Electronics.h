#ifndef ELECTRONICS_H_
#define ELECTRONICS_H_

#include "Product.h"

class Electronics : public Product {
public:
   Electronics(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& brand, const std::string& model)
   : Product(productId, name, "Electronics", base_price, quality, seller), brand_(brand), model_(model) {}

   std::string getBrand() const { return brand_; }
   std::string getModel() const { return model_; }
   void displayProductInfo() const override;

private:
   std::string brand_;
   std::string model_;
};

// Electronics Subcategories

class Computer : public Electronics {
public:
   Computer(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& brand, const std::string& model)
   : Electronics(productId, name, base_price, quality, seller, brand, model) {}
};

class Laptop : public Computer {
public:
   Laptop(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& brand, const std::string& model)
   : Computer(productId, name, base_price, quality, seller, brand, model) {}
};

class Phone : public Electronics {
public:
   Phone(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& brand, const std::string& model)
   : Electronics(productId, name, base_price, quality, seller, brand, model) {}
};

class Smartphone : public Phone {
public:
   Smartphone(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& brand, const std::string& model)
   : Phone(productId, name, base_price, quality, seller, brand, model) {}
};

class TV : public Electronics {
public:
   TV(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& brand, const std::string& model)
   : Electronics(productId, name, base_price, quality, seller, brand, model) {}
};

class SmartTV : public TV {
public:
   SmartTV(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& brand, const std::string& model)
   : TV(productId, name, base_price, quality, seller, brand, model) {}
};

#endif // ELECTRONICS_H_