#include "UserFactory.h"

User *UserFactory::createUser(const std::string &type, const std::string &username,
                              long phoneNumber, const std::string &address, double balance)
{
    if (type == "Buyer")
    {
        return createBuyer(username, phoneNumber, address, balance);
    }
    else if (type == "Seller")
    {
        return createSeller(username, phoneNumber, address, balance);
    }
    return nullptr; // Invalid type
}

User *UserFactory::createUserFromCSV(const std::string &user_id, const std::string &username,
                                     const std::string &user_type, long phoneNumber,
                                     const std::string &address, double balance)
{
    // You can use the user_id if needed or just pass it along
    return createUser(user_type, username, phoneNumber, address, balance);
}

Buyer *UserFactory::createBuyer(const std::string &username, long phoneNumber,
                                const std::string &address, double balance)
{
    return new Buyer(username, phoneNumber, address, balance);
}

Seller *UserFactory::createSeller(const std::string &username, long phoneNumber,
                                  const std::string &address, double balance)
{
    return new Seller(username, phoneNumber, address, balance);
}
