#ifndef _BUYER_H_
#define _BUYER_H_

#include "User.h"
#include <vector>

// Forward declaration
class Product;

class Buyer : public User
{
private:
    std::vector<Product *> purchaseHistory_;          // Stores products the buyer has won
    std::vector<std::pair<int, double>> bid_history_; // Product IDs and bid amounts
public:
    // Constructors
    Buyer(const std::string &uname, long phone, const std::string &addr, double bal);

    // Bidding actions
    bool placeBuyerBid(int productId, double bidAmount);

    // Override from User base class
    void updateUserInformation() override;

    // Methods for bidding and purchasing
    bool placeBid(int productId, double amount);
    void viewBiddingHistory(int productId);
    void viewPurchaseHistory(int productId);
    void addPurchasedProduct(Product *product); 

    // Method for displaying available products
    void displayAvailableProducts() const;
};

#endif // _BUYER_H_