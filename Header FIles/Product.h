#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <map>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"


enum class Quality { New, Used_VeryGood, Used_Good, Used_Okay };


class Product {
private:
    const int productId_;
    std::string name_;
    std::string category_;
    double basePrice_;
    Quality quality_;
    bool isActive_; 
    bool isSold_;
    Seller* seller_;  
    std::map<Buyer*, double> bids_;  // Using map to track bids by buyer

public:
    // Constructor
    Product(const int productId, const std::string& name, const std::string& category, const double basePrice, const Quality quality, Seller* seller)
    : productId_(productId), name_(name), category_(category), basePrice_(basePrice), quality_(quality), isActive_(true), isSold_(false), seller_(seller) {}

    virtual ~Product() = default;  


    // Getters
    int getProductId() const { return productId_; }
    std::string getName() const { return name_; }
    std::string getCategory() const { return category_; }
    double getBasePrice() const { return basePrice_; }
    bool isActive() const { return isActive_; }
    bool isSold() const { return isSold_; }
    Quality getQuality() const { return quality_; }
    Seller* getSeller() const { return seller_; }
    Buyer* getHighestBidder() const;
    double getHighestBidAmount() const;
    
    
    // Setters
    void setIsActive(bool active) { isActive_ = active; }
    void setIsSold(bool sold) { isSold_ = sold; }


    // Bidding operations
    void addBid(Buyer* buyer, double bidAmount);
    void closeBidding();
    void reopenBidding();
    void rejectWinningBid();
    void markAsSold();


    // Display product information
    virtual void displayProductInfo() const;
};

#endif // PRODUCT_H