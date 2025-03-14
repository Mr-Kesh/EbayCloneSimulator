#include "Driver.h"
#include "Bid.h"


// Initialize static instance pointer
Driver* Driver::instance = nullptr;


// Private constructor
Driver::Driver() : currentUser(nullptr) {}


// Get singleton instance
Driver* Driver::getInstance() {
    if (instance == nullptr) {
        instance = new Driver();
    }
    return instance;
}


// Main program operations
void Driver::run() {}


void Driver::loadData() {}


void Driver::saveData() {}


// User
User* Driver::login(const std::string& username) {
    return nullptr;
}


void Driver::createAccount(bool isSeller) {}


void Driver::displayMainMenu() {}


void Driver::displayAvailableProducts() {}


// Product
void Driver::addProduct(Seller* seller) {}


Product* Driver::getProductById(int productId) {
    return nullptr;
}


// Bid 
void Driver::placeBid(Buyer* buyer, int productId, double amount) {}


void Driver::closeBidding(Seller* seller, int productId) {}



std::vector<Product*> Driver::getProductsBySeller(Seller* seller) {
    return std::vector<Product*>();
}


std::vector<Bid*> Driver::getBidsByBuyer(Buyer* buyer) {
    return std::vector<Bid*>();
}


std::vector<Bid*> Driver::getBidsForProduct(int productId) {
    return std::vector<Bid*>();
}


// Destructor
Driver::~Driver() {}