#ifndef BID_H
#define BID_H

#include <string>

// Forward declarations
class Buyer;
class Product;

class Bid
{
private:
    int bidId_;
    Buyer *buyer_;
    int productId_;
    double amount_;
    std::string timestamp_;

public:
    // Constructor
    Bid(int bidId, Buyer *buyer, int productId, double amount);

    // Getters
    int getBidId() const { return bidId_; }
    Buyer *getBuyer() const { return buyer_; }
    int getProductId() const { return productId_; }
    double getAmount() const { return amount_; }
    std::string getTimestamp() const { return timestamp_; }
};

#endif // BID_H
