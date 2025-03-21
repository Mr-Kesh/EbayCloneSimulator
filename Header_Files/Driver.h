#ifndef DRIVER_H_
#define DRIVER_H_

#include <string>
#include <map>
#include <vector>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include "Bid.h"
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
    void welcomeMessage();
    void mainMenu();
    bool showSellerMenu();
    bool showBuyerMenu();
    void returnToBeginningMenu();

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
    const std::map<int, Product *> &getProducts() const { return products; }
    void addProduct(int productId, Product *product);
    const std::vector<Seller *> &getSellers() const { return sellers; }

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
    void loadUsers(const std::string &filename);
    void loadProducts(const std::string &filename);
    void loadData();
    void saveData();
    void saveUsers(const std::string &filename);
    void saveProducts(const std::string &filename);
    Seller *getSellerByUsername(const std::string &username);
    bool validateYesNoInput(char &choice);
};

// Helper function outside of class
template <typename T>
T getValidNumberChoice(const std::string &prompt, T min, T max);
void clearInputBuffer(); // Clear input buffer

#endif // DRIVER_H_