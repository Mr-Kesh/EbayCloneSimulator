#include "Bid.h"
#include <iostream>

// Constructor
Bid::Bid(Buyer* buyer, Product* product, double bidAmount) : buyer_(buyer), product_(product), bidAmount_(bidAmount) {}



// Display bid details
void Bid::displayBidInfo() const {
    std::cout << "Bid Info: " << std::endl;
    std::cout << "   Buyer: " << buyer_->getUsername() << std::endl;
    std::cout << "   Product: " << product_->getName() << std::endl;
    std::cout << "   Bid Amount: $" << bidAmount_ << std::endl;
}
