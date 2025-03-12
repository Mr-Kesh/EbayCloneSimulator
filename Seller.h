#ifndef _SELLER_H_
#define _SELLER_H_

#include "User.h"
#include <vector>
#include <string>
#include "Product.h"

class Seller : public User {
private:
    std::vector<Product> productsForSale_; // List of products the seller is selling
public:
    // Constructor
    Seller(std::string username, long phone_no, std::string address, double account_balance);

    // Seller Actions
    void postProduct(const std::string& name, const std::string& category, double startingPrice, std::string quality);
    void viewHistoricalPrices(const std::string& category) const;
    void openBid(Product& product);
    void closeBid(Product& product);
    bool soldOrNot(const Product& product) const;
    double checkAccountBalance() const;

    void addProductForSale(const Product& product);
    void displayProductsForSale() const;
};

#endif  // _SELLER_H_
