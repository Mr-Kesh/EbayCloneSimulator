#include "Seller.h"
#include <iostream>

// Constructor
Seller::Seller(const std::string &uname, long phone, const std::string &addr, double bal) : User(uname, phone, addr, bal) {}



// Seller Actions
void Seller::postProduct(const std::string& name, const std::string& category, double startingPrice, std::string quality) {

}




void Seller::viewHistoricalPrices(const std::string& category) const {
    
}



void Seller::openBid(Product& product) {

    // Set product as available for bidding
    product.setIsActive(true);

}



void Seller::closeBid(Product& product) {

    // Close bidding on a product
    product.setIsActive(false);

}



bool Seller::soldOrNot(const Product& product) const {

    // Check if a product has been sold
    return product.isSold();

}



double Seller::checkAccountBalance() const {

    // Return the seller's account balance
    return getBalance();

}



void Seller::addProductForSale(const Product& product) {
    
}



void Seller::displayProductsForSale() const {
    
    std::cout << "Products listed by " << getUsername() << ":" << std::endl;

}