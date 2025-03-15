#ifndef BID_H_
#define BID_H_

#include "Buyer.h"
#include "Product.h"

class Bid {
private:
    Buyer* buyer_;   // The buyer placing the bid
    Product* product_; // The product being bid on
    double bidAmount_; 


public:
    // Constructor
    Bid(Buyer* buyer, Product* product, double bidAmount);

    // Getters
    Buyer* getBuyer() const { return buyer_; }
    Product* getProduct() const { return product_; }
    double getBidAmount() const { return bidAmount_; }

    // Display bid information
    void displayBidInfo() const;
};

#endif // BID_H_
