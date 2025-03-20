#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include <vector>

// Forward declarations
class Product;

class Buyer : public User
{
private:
    std::vector<int> purchaseHistory_;
    std::vector<int> biddingHistory_;

public:
    Buyer(const std::string &username, long phoneNumber, const std::string &address, double balance);

    // Bidding functions
    bool placeBid(int productId, double amount);
    void viewBiddingHistory(int productId);
    void viewPurchaseHistory(int productId);

    // Display available products
    void displayAvailableProducts() const;

    // User information management
    void updateUserInformation() override;
};

#endif // BUYER_H
