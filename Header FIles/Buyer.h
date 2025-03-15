#ifndef _BUYER_H_
#define _BUYER_H_

#include "User.h"
#include "Product.h"
#include <vector>


class Buyer : public User {
private:
    std::vector<Product*> purchaseHistory_;  // Stores products the buyer has won
    std::vector<std::pair<int, double>> bid_history_;  // Product IDs and bid amounts
public:
    // Constructor
    Buyer(const std::string &uname, long phone, const std::string &addr, double bal);

    //std::string getUserType() const override;

    // Bidding actions
    bool placeBid(Product& product, double bidAmount);
    void viewActiveProducts(const std::vector<Product>& allProducts) const;
    void viewBidsPlaced() const;
    void finalizePurchase(Product& product);

    // Purchase history
    void viewPurchaseHistory() const;
};

#endif  // _BUYER_H_
