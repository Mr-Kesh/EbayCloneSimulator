#include "Header_Files/User.h"

User::User(const std::string &username, long phoneNumber, const std::string &address, double accountBalance)
    : username_(username), phone_no_(phoneNumber), address_(address), account_balance_(accountBalance) {}

void User::updateUserInformation()
{
    
    std::cout << "Updating user information for " << username_ << std::endl;
}