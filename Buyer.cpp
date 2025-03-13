#include "Buyer.h"
#include "User.cpp"

Buyer::Buyer(const std::string &uname, long phone, const std::string &addr, double bal)
    : User(uname, phone, addr, bal) {};

// std::string Buyer::getUserType() const { 
//     return "Buyer"; 
// };
