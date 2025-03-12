#include "User.h"

// User constructor definition
User::User(const std::string& username, long phoneNumber, const std::string& address, double balance)
    : username_(username), phone_no_(phoneNumber), address_(address), account_balance_(balance) {
    // Initialization list used to initialize data members
}
