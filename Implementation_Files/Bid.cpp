#include "Header_Files/Bid.h"
#include "Header_Files/Buyer.h"
#include "Header_Files/Product.h"
#include <iostream>

// Constructor
Bid::Bid(Buyer *buyer, Product *product, double bidAmount) : bidId_(0), buyer_(buyer), productId_(product->getProductId()), amount_(bidAmount), timestamp_("") {}

// Display bid details
void Bid::displayBidInfo() const
{
    std::cout << "Bid Information:" << std::endl;
    std::cout << "   Bid ID: " << bidId_ << std::endl;
    std::cout << "   Buyer: " << buyer_->getUsername() << std::endl;
    std::cout << "   Product ID: " << productId_ << std::endl;
    std::cout << "   Bid Amount: $" << amount_ << std::endl;
    std::cout << "   Timestamp: " << timestamp_ << std::endl;
}
