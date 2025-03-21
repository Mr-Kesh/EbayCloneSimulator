#include "Header_Files/User.h"

// Constructor implementation
User::User(const std::string &username, long phoneNumber, const std::string &address, double accountBalance)
    : username_(username), phone_no_(phoneNumber), address_(address), account_balance_(accountBalance) {}

// Setter implementations
// void User::setUsername(std::string new_username)
// {
//     username_ = new_username;
// }

// void User::setPhoneNumber(long new_phone_no)
// {
//     phone_no_ = new_phone_no;
// }

// void User::setAddress(std::string new_address)
// {
//     address_ = new_address;
// }

// void User::updateBalance(double amount)
// {
//     account_balance_ += amount;
// }

void User::updateUserInformation()
{
    // Implementation for updating user information
    std::cout << "Updating user information for " << username_ << std::endl;
}