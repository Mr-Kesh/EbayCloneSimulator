#include "Seller.h"
#include "User.cpp"

Seller::Seller(const std::string &uname, long phone, const std::string &addr, double bal)
    : User(uname, phone, addr, bal) {};

// std::string Seller::getUserType() const { 
//     return "Seller"; 
// };