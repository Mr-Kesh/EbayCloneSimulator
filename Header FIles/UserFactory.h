#ifndef USER_FACTORY_H
#define USER_FACTORY_H

#include <string>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"

class UserFactory
{
public:
    // Create a user based on type
    static User *createUser(const std::string &type, const std::string &username,
                            long phoneNumber, const std::string &address, double balance);

    // Create a user from CSV data
    static User *createUserFromCSV(const std::string &user_id, const std::string &username,
                                   const std::string &user_type, long phoneNumber,
                                   const std::string &address, double balance);

    // Helper methods to create specific user types
    static Buyer *createBuyer(const std::string &username, long phoneNumber,
                              const std::string &address, double balance);

    static Seller *createSeller(const std::string &username, long phoneNumber,
                                const std::string &address, double balance);
};

#endif // USER_FACTORY_H
