#ifndef BIDTOBUY_H
#define BIDTOBUY_H

#include <vector>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"

// UserID, Username, Role, PhoneNumber, Address, AccountBalance
// ProductID, ProductName, Category, Quality, StartingPrice, FinalSellingPrice, SellerUsername, BuyerUsername

class BidToBuy {
private:
    std::vector<User*> users;  // Store sellers and buyers
    std::vector<Product> products_; // List of all products (active & sold)

public:
    BidToBuy();  // Constructor
    BidToBuy(const std::string& userFile, const std::string& productFile);  // Constructor to initialize the system with files

    void run(); // runs the program

    void loadUsers(const std::string& filename); // Read users from CSV
    void loadProducts(const std::string& filename); // Read product/bid data from CSV`
    void addUser();

    void displayUsers();

    ~BidToBuy(); // Destructor
};

#endif
