#include "User.h"

// User constructor definition
User::User(const std::string& username, long phoneNumber, const std::string& address, double balance)
    : username_(username), phone_no_(phoneNumber), address_(address), account_balance_(balance) {
    // Initialization list used to initialize data members
}

// Getters
std::string User::getUsername() const{
    return username_;
};

long User::getPhoneNumber() const{
    return phone_no_;
};

std::string User::getAddress() const{
    return address_;
};

double User::getBalance() const{
    return account_balance_;
};
