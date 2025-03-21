#ifndef _BUYER_H_
#define _BUYER_H_

#include "User.h"
#include "Product.h"
#include <vector>

class Buyer : public User
{
private:
    std::vector<Product *> purchaseHistory_;          // Stores products the buyer has won
    std::vector<std::pair<int, double>> bid_history_; // Product IDs and bid amounts
public:
    // Constructors
    Buyer(int userId, const std::string &uname, long phone, const std::string &addr, double bal);
    Buyer(const std::string &uname, long phone, const std::string &addr, double bal);

    // Bidding actions
    bool placeBid(Product &product, double bidAmount);
    void viewActiveProducts(const std::vector<Product> &allProducts) const;
    void viewBidsPlaced() const;
    void finalizePurchase(Product &product);

    // Purchase history
    void viewPurchaseHistory() const;

    // Override from User base class
    void updateUserInformation() override;

    // New methods moved from Driver
    bool placeBid(int productId, double amount);
    void viewBiddingHistory(int productId);
    void viewPurchaseHistory(int productId);

    // Method for displaying available products
    void displayAvailableProducts() const;
};

#endif // _BUYER_H_