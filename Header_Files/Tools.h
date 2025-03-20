#ifndef TOOLS_H_
#define TOOLS_H_



#include "Product.h"


class Tools : public Product {
public:
    Tools(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& tool_type)
    : Product(productId, name, "Tools", base_price, quality, seller), tool_type_(tool_type) {}

    std::string getToolType() const { return tool_type_; }
    void displayProductInfo() const override;

private:
    std::string tool_type_;
};



class HandTool : public Tools {
public:
    HandTool(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller)
    : Tools(productId, name, base_price, quality, seller, "Hand Tool") {}
};



class Hammer : public HandTool {
public:
    Hammer(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller)
    : HandTool(productId, name, base_price, quality, seller) {}
};



class PowerTool : public Tools {
public:
    PowerTool(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller)
    : Tools(productId, name, base_price, quality, seller, "Power Tool") {}
};



class Drill : public PowerTool {
public:
    Drill(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller)
    : PowerTool(productId, name, base_price, quality, seller) {}
};



class GardenTool : public Tools {
public:
    GardenTool(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller)
    : Tools(productId, name, base_price, quality, seller, "Garden Tool") {}
};



class LawnMower : public GardenTool {
public:
    LawnMower(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller)
    : GardenTool(productId, name, base_price, quality, seller) {}
};



#endif // TOOLS_H_