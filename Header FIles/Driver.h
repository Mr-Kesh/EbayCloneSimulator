#ifndef DRIVER_H_
#define DRIVER_H_

#include <string>
#include <map>
#include <vector>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include "BidToBuy.h"

class Driver
{
private:
    // Singleton instance
    static Driver *instance;

    // Constructor is private for singleton pattern
    Driver();

    // Maps and collections to store data
    std::map<std::string, User *> users;
    std::map<int, Product *> products;
    std::vector<Bid *> bids;
    std::vector<Seller *> sellers;

    // Current logged in user
    User *currentUser;

public:
    // Delete copy constructor and assignment operator
    Driver(const Driver &other) = delete;
    Driver &operator=(const Driver &other) = delete;
    ~Driver();

    /****************************************************
     * Singleton and Main Program Functions
     ****************************************************/
    static Driver *getInstance();
    void run();
    void mainMenu();
    bool showSellerMenu();
    bool showBuyerMenu();

    /****************************************************
     * Authentication and Account Functions
     ****************************************************/
    User *authenticateUser();
    User *authenticateUserType();
    long enterPhoneNumber();
    std::string enterAddress();
    double enterBalance();
    Buyer *createBuyer();
    Seller *createSeller();
    User *login(const std::string &username);
    void createAccount();
    User *findExistingUser(const std::string &username);

    /****************************************************
     * Product Functions
     ****************************************************/
    void displayAvailableProducts();
    Product *getProductById(int productId);
    std::vector<Product *> getProductsBySeller(Seller *seller);
    int getNextProductId();

    /****************************************************
     * Bid Functions
     ****************************************************/
    void placeBid(Buyer *buyer, int productId, double amount);
    std::vector<Bid *> getBidsByBuyer(Buyer *buyer);
    std::vector<Bid *> getBidsForProduct(int productId);
    void openBidding(Seller *seller, int productId);
    void closeBidding(Seller *seller, int productId);

    /****************************************************
     * User Update Functions
     ****************************************************/
    void updateUserInformation(Seller *seller);

    /****************************************************
     * Data CSV Files Functions
     ****************************************************/
    void loadData();
    void loadUsers(const std::string &filename);
    void loadProducts(const std::string &filename);
    void saveData();
    Seller *getSellerByUsername(const std::string &username);
};

// Helper function outside of class
double getValidNumberChoice(const std::string &prompt, double min, double max);

#endif // DRIVER_H_