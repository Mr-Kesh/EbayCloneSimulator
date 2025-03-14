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

class Driver {
private:
    // Singleton instance
    static Driver* instance;
    
    // Constructor is private for singleton pattern
    Driver();
    
    // Maps and collections to store data
    std::map<std::string, User*> users;
    std::map<int, Product*> products;
    std::vector<Bid*> bids;
    
    // Current logged in user
    User* currentUser;
    
public:
    // Delete copy constructor and assignment operator
    Driver(const Driver& other) = delete;
    Driver& operator=(const Driver& other) = delete;
    
    // Get singleton instance
    static Driver* getInstance();
    
    // Main program operations
    void run();
    void loadData();
    void saveData();
    
    // User management
    User* login(const std::string& username);
    void createAccount(bool isSeller);
    void displayMainMenu();
    void displayAvailableProducts();


    void addProduct(Seller* seller);
    Product* getProductById(int productId);
    
   
    void placeBid(Buyer* buyer, int productId, double amount);
    void closeBidding(Seller* seller, int productId);
    
   
    std::vector<Product*> getProductsBySeller(Seller* seller);
    std::vector<Bid*> getBidsByBuyer(Buyer* buyer);
    std::vector<Bid*> getBidsForProduct(int productId);
    
    // Cleanup resources when program ends
    ~Driver();
};

#endif // DRIVER_H_