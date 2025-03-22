#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <map>

// Forward declarations
class Buyer;
class Seller;

// Struct to store bid information
struct BidInfo
{
    Buyer *buyer;
    double amount;
    BidInfo(Buyer *b, double a) : buyer(b), amount(a) {}
};

enum class Quality
{
    New,
    Used_VeryGood,
    Used_Good,
    Used_Okay
};

class Product
{
private:
    const int productId_;
    std::string name_;
    std::string category_;
    double basePrice_;
    Quality quality_;
    bool isActive_;
    bool isSold_;
    Seller *seller_;
    std::map<Buyer *, double> bids_;  // Using map to track bids by buyer
    std::vector<BidInfo> bidHistory_; // Vector to store all bids in chronological order
    std::string attribute1_;          // First attribute specific to product type
    std::string attribute2_;          // Second attribute specific to product type

public:
    // Constructor
    Product(const int productId, const std::string &name, const std::string &category, const double basePrice, const Quality quality, Seller *seller)
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
    Seller *getSeller() const { return seller_; }
    Buyer *getHighestBidder() const;
    double getHighestBidAmount() const;
    const std::vector<BidInfo> &getBidHistory() const { return bidHistory_; }

    // New attribute getters
    std::string getAttribute1() const { return attribute1_; }
    std::string getAttribute2() const { return attribute2_; }

    // New attribute setters
    void setAttribute1(const std::string &attr) { attribute1_ = attr; }
    void setAttribute2(const std::string &attr) { attribute2_ = attr; }

    // Setters
    void setIsActive(bool active) { isActive_ = active; }
    void setIsSold(bool sold) { isSold_ = sold; }

    // Bid management
    bool addBid(Buyer *buyer, double amount);
    void openBidding();
    void closeBidding();
    void reopenBidding();
    void rejectWinningBid();
    void markAsSold();
    void viewSalesHistory();
    void displaySalesHistorySummary() const;
    void displayBidHistoryForProduct() const;
    // Display product information
    virtual void displayProductInfo() const;
};

#endif // PRODUCT_H