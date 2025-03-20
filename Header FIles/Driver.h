#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>
#include <map>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"

// Forward declarations
class Product;
class Bid;

class Driver
{
private:
    static Driver *instance_;
    std::map<int, Product *> products;
    std::vector<User *> users;
    User *currentUser;
    std::vector<Bid *> bids;
    int nextProductId;

    // Private constructor to implement Singleton
    Driver();

public:
    // Get the singleton instance
    static Driver *getInstance();

    // Main program execution
    void run();
    void welcomeMessage();

    // Menu handling
    bool mainMenu();
    bool showSellerMenu();
    bool showBuyerMenu();

    // Authentication
    bool login();
    bool registerUser();
    void logout();

    // Product management
    void displayAvailableProducts();
    Product *getProductById(int id);
    std::vector<Product *> getProductsBySeller(Seller *seller);
    int getNextProductId();

    // Buyer methods
    void placeBid(Buyer *buyer, int productId, double amount);
    std::vector<Bid *> getBidsByBuyer(Buyer *buyer);
    std::vector<Bid *> getBidsForProduct(int productId);

    // Seller methods
    void updateUserInformation(Seller *seller);
    void openBidding(Seller *seller, int productId);
    void closeBidding(Seller *seller, int productId);

    // Data loading/saving
    void loadUsers(const std::string &filename);
    void saveUsers(const std::string &filename);
    void loadProducts(const std::string &filename);
    void saveProducts(const std::string &filename);
    void loadBids(const std::string &filename);
    void saveBids(const std::string &filename);
};

// Utility function - defined outside the class
template <typename T>
T getValidNumberChoice(const std::string &prompt, T min, T max);

#endif // DRIVER_H