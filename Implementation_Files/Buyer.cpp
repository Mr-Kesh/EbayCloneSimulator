#include "Header_Files/Buyer.h"
#include <iostream>
#include <limits>

Buyer::Buyer(const std::string &uname, long phone, const std::string &addr, double bal)
    : User(uname, phone, addr, bal)
{
    user_type_ = "Buyer";
}

// std::string Buyer::getUserType() const {
//     return "Buyer";
// };

// Implement existing methods (empty for now)
bool Buyer::placeBid(Product &product, double bidAmount)
{
    // Implementation...
    return false;
}

void Buyer::viewActiveProducts(const std::vector<Product> &allProducts) const
{
    // Implementation...
}

void Buyer::viewBidsPlaced() const
{
    // Implementation...
}

void Buyer::finalizePurchase(Product &product)
{
    // Implementation...
}

void Buyer::viewPurchaseHistory() const
{
    // Implementation...
}

void Buyer::updateUserInformation()
{
    std::string newUsername;
    long newPhone;
    std::string newAddress;

    std::cout << "Enter new username (or press Enter to keep current): ";
    std::getline(std::cin, newUsername);
    if (!newUsername.empty())
    {
        setUsername(newUsername);
    }

    std::cout << "Enter new phone number (or enter 0 to keep current): ";
    std::cin >> newPhone;
    std::cin.ignore();
    if (newPhone != 0)
    {
        setPhoneNumber(newPhone);
    }

    std::cout << "Enter new address (or press Enter to keep current): ";
    std::getline(std::cin, newAddress);
    if (!newAddress.empty())
    {
        setAddress(newAddress);
    }

    std::cout << "User information updated successfully!" << std::endl;
}

// New methods moved from Driver
bool Buyer::placeBid(int productId, double amount)
{
    std::cout << "Placing bid of $" << amount << " on product ID " << productId << std::endl;

    // 1. Find the product by ID
    // 2. Check if the product is active for bidding
    // 3. Verify the bid amount is higher than current bids
    // 4. Place the bid and add it to bid history

    // For now, we'll just add it to our bid history
    bid_history_.push_back(std::make_pair(productId, amount));

    return true;
}

void Buyer::viewBiddingHistory(int productId)
{
    std::cout << "Viewing bidding history for product ID " << productId << std::endl;

    bool foundBids = false;

    // Print all bids for the specified product
    for (const auto &bid : bid_history_)
    {
        if (bid.first == productId || productId == 0)
        {
            std::cout << "Product ID: " << bid.first << ", Bid amount: $" << bid.second << std::endl;
            foundBids = true;
        }
    }

    if (!foundBids)
    {
        std::cout << "No bids found for this product." << std::endl;
    }
}

void Buyer::viewPurchaseHistory(int productId)
{
    std::cout << "Viewing purchase history for product ID " << productId << std::endl;

    bool foundProduct = false;

    // Not done yet, this would search through purchase history
    // For now, we'll just print a message
    for (const auto &product : purchaseHistory_)
    {
        if (product->getProductId() == productId || productId == 0)
        {
            std::cout << "Product: " << product->getName() << ", Price: $" << product->getBasePrice() << std::endl;
            foundProduct = true;
        }
    }

    if (!foundProduct)
    {
        std::cout << "No purchase found for this product ID." << std::endl;
    }
}

void Buyer::displayAvailableProducts() const
{
    std::cout << "===================================\n";
    std::cout << "📋  Available Products  \n";
    std::cout << "===================================\n";

    // Not Done
    std::cout << "To see available products, please use the main menu option.\n";
    std::cout << "-----------------------------------" << std::endl;
}
