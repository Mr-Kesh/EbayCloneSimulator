#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <map>
#include "User.h"
#include "Buyer.h"

enum class Quality { New, Used_VeryGood, Used_Good, Used_Okay };

// I dont know if this class is correct

class Product {
private:
    std::string name_;
    std::string category_;
    double basePrice_;
    Quality quality_;
    bool isActive_; // Indicates if bidding is open
    bool isSold_;

    std::map<Buyer*, double> bids_; // Stores buyer pointers and their bid amounts

public:
    // Constructor
    Product(std::string name, std::string category, double basePrice, Quality quality);

    // Getters
    std::string getName() const;
    std::string getCategory() const;
    double getBasePrice() const;
    bool isActive() const;
    bool isSold() const;
    Buyer* getHighestBidder() const;
    double getHighestBidAmount() const;

    // Bidding operations
    void addBid(Buyer* buyer, double bidAmount);
    void closeBidding();
    void reopenBidding();
    void rejectWinningBid();
    void markAsSold();

    // Display product information
    void displayProductInfo() const;
};

#endif // PRODUCT_H
