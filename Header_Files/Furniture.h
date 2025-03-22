#ifndef FURNITURE_H_
#define FURNITURE_H_

#include "Product.h"

class Furniture : public Product {
public:
    Furniture(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& material, const std::string& type)
    : Product(productId, name, "Furniture", base_price, quality, seller), material_(material), type_(type) {}

    std::string getMaterial() const { return material_; }
    std::string getType() const { return type_; }
    void displayProductInfo() const override;

private:
    std::string material_;
    std::string type_;
};

// Furniture Subcategories

class Chair : public Furniture {
public:
    Chair(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& material)
    : Furniture(productId, name, base_price, quality, seller, material, "Chair") {}
};

class OfficeChair : public Chair {
public:
    OfficeChair(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& material)
    : Chair(productId, name, base_price, quality, seller, material) {}
};

class Table : public Furniture {
public:
    Table(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& material)
    : Furniture(productId, name, base_price, quality, seller, material, "Table") {}
};

class CoffeeTable : public Table {
public:
    CoffeeTable(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& material)
    : Table(productId, name, base_price, quality, seller, material) {}
};

class Bed : public Furniture {
public:
    Bed(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& material)
    : Furniture(productId, name, base_price, quality, seller, material, "Bed") {}
};

class TwinBed : public Bed {
public:
    TwinBed(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& material)
    : Bed(productId, name, base_price, quality, seller, material) {}
};

#endif // FURNITURE_H_