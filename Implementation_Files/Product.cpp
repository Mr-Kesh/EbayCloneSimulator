#include "Header_Files/Product.h"
#include "Header_Files/Buyer.h"
#include "Header_Files/Seller.h"
#include <iostream>
#include <algorithm> // Include for max_element

/**
 * @brief Gets the buyer with the highest bid for this product.
 *
 * @return Buyer* Pointer to the buyer with the highest bid, or nullptr if no bids exist.
 */
Buyer *Product::getHighestBidder() const
{
    // If nobody's bidding yet, just return nothing
    if (bids_.empty())
        return nullptr;
    // max_element thing to loop through all bids and find the biggest one
    // a and b are just the different bids we're comparing
    // We check if a's price is smaller than b's price
    return std::max_element(bids_.begin(), bids_.end(),
                            [](const auto &a, const auto &b)
                            { return a.second < b.second; })
        ->first; // Give back the buyer who made the biggest bid
}

/**
 * @brief Gets the highest bid amount for this product
 *
 * @return double The amount of the highest bid, or 0.0 if no bids exist
 */
double Product::getHighestBidAmount() const
{
    // If nobody's bidding, return $0
    if (bids_.empty())
        return 0.0;
    // Same thing as the function above - find the max bid and return the amount
    return std::max_element(bids_.begin(), bids_.end(),
                            [](const auto &a, const auto &b)
                            { return a.second < b.second; })
        ->second; // Give back the biggest bid amount
}

/**
 * @brief Opens bidding for this product.
 *
 * @return void This function sets the product as active for bidding.
 */
void Product::openBidding()
{
    isActive_ = true;
    std::cout << "Bidding opened for product: " << getName() << std::endl;
}

/**
 * @brief Closes bidding for this product.
 *
 * @return void This function sets the product as inactive for bidding.
 */
void Product::closeBidding()
{
    isActive_ = false;
    std::cout << "Bidding closed for product: " << getName() << std::endl;
}

/**
 * @brief Reopens bidding for a previously closed product.
 *
 * @return void This function sets the product as active for bidding again.
 */
void Product::reopenBidding()
{
    isActive_ = true;
    std::cout << "Bidding reopened for product: " << getName() << std::endl;
}

/**
 * @brief Rejects the current highest bid for this product.
 *
 * @return void This function removes the highest bidder from the bids map.
 */
void Product::rejectWinningBid()
{
    if (!bids_.empty())
    {
        auto highestBidder = getHighestBidder();
        bids_.erase(highestBidder); // Delete the highest bidder from our map
        std::cout << "Winning bid rejected for product: " << getName() << std::endl;
    }
}

/**
 * @brief Marks the product as sold.
 *
 * @return void This function updates the product's sold status to true.
 */
void Product::markAsSold()
{
    isSold_ = true;
    std::cout << "Product marked as sold: " << getName() << std::endl;
}

/**
 * @brief Displays formatted information about the product.
 *
 * @return void This function outputs product details to the console.
 */
void Product::displayProductInfo() const
{
    std::cout << "\n\n===================================\n"
              << " Your Products for Sale \n"
              << "===================================\n"
              << "ID: " << productId_
              << " | Name: " << name_
              << " | Category: " << category_
              << " | Price: $" << basePrice_
              << " | Status: " << (isActive_ ? "Bidding Open" : "Bidding Closed")
              << "\n-----------------------------------" << std::endl;
}

bool Product::addBid(Buyer *buyer, double amount)
{
    // Check if this is a higher bid
    if (amount > getHighestBidAmount())
    {
        bids_[buyer] = amount;

        // Add to bid history regardless of whether it's the highest
        bidHistory_.push_back(BidInfo(buyer, amount));

        return true;
    }

    // Even if not the highest bid, still record it in history
    bidHistory_.push_back(BidInfo(buyer, amount));

    return false;
}

/**
 * @brief Displays the sales history of the product.
 *
 * @return void This function shows the sales history of the product.
 */
void Product::viewSalesHistory()
{
    std::cout << "\n\n===================================" << std::endl;
    std::cout << "  Sales History for Product #" << productId_ << "  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Category: " << category_ << std::endl;
    std::cout << "Base Price: $" << basePrice_ << std::endl;
    std::cout << "Status: " << (isActive_ ? "Active" : "Inactive") << ", " << (isSold_ ? "Sold" : "Not Sold") << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    // Additional sales history details could be shown here
    if (isSold_)
    {
        Buyer *highestBidder = getHighestBidder();
        if (highestBidder)
        {
            std::cout << "Sold to: " << highestBidder->getUsername() << std::endl;
            std::cout << "Sale Price: $" << getHighestBidAmount() << std::endl;
        }
    }
    else
    {
        std::cout << "This product has not been sold yet." << std::endl;
    }
}

/**
 * @brief Displays a concise sales history summary of the product.
 * This is used when showing multiple products at once.
 */
void Product::displaySalesHistorySummary() const
{
    std::cout << "Product #" << productId_ << " - " << name_ << " | ";
    std::cout << "Price: $" << basePrice_ << " | ";
    std::cout << "Status: " << (isActive_ ? "Active" : "Inactive");

    if (isSold_)
    {
        std::cout << ", Sold for $" << getHighestBidAmount();
    }
    else if (!bids_.empty())
    {
        std::cout << ", Current bid: $" << getHighestBidAmount();
    }
    else
    {
        std::cout << ", No bids";
    }

    std::cout << std::endl;
}

/**
 * @brief Displays the full bid history for this product
 *
 * This function shows all bids placed on the product in chronological order
 */
void Product::displayBidHistoryForProduct() const
{
    std::cout << "\n\n===================================" << std::endl;
    std::cout << "  Bid History for Product #" << productId_ << "  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Base Price: $" << basePrice_ << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    if (bidHistory_.empty())
    {
        std::cout << "No bids have been placed on this product yet." << std::endl;
        return;
    }

    std::cout << "Bid History (in chronological order):" << std::endl;

    for (size_t i = 0; i < bidHistory_.size(); i++)
    {
        const BidInfo &bid = bidHistory_[i];
        std::cout << "Bid #" << (i + 1) << ": $" << bid.amount
                  << " by " << bid.buyer->getUsername() << std::endl;
    }

    // Show current highest bid
    Buyer *highestBidder = getHighestBidder();
    if (highestBidder)
    {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Current highest bid: $" << getHighestBidAmount()
                  << " by " << highestBidder->getUsername() << std::endl;
    }
}
