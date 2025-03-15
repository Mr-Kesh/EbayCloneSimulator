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
void Driver::run() {

  /*std::string userType, username;
  std::cout << "Are you a Buyer or a Seller? ";
  std::cin >> userType;
  std::cin.ignore();

  std::cout << "Enter your username: ";
  std::getline(std::cin, username);

  // User *existingUser = findExistingUser(username);
  // if (existingUser != nullptr) {
  //   std::cout << "Logged in as " << existingUser->getUsername() << " (" << existingUser->getUserType() << ")\n";
  // } else {
    std::cout << "Can't find account, make a new one.\n";
    std::cout << "Enter phone number: ";
    long phoneNumber;
    std::cin >> phoneNumber;
    std::cin.ignore();

    std::cout << "Enter address: ";
    std::string address;
    std::getline(std::cin, address);

    std::cout << "Enter initial balance: ";
    double balance;
    std::cin >> balance;
    std::cin.ignore();

    if (userType == "Buyer") {
      User newUser = Buyer(username, phoneNumber, address, balance);
      users.push_back(&newUser);
    } else if (userType == "Seller") {
      User newUser = Seller(username, phoneNumber, address, balance);
      users.push_back(&newUser);
    } else {
      std::cout << "Invalid user type.\n";
      return;
    }
    
    //saveUserToFile("users.csv", *newUser);
    std::cout << "Account created successfully.\n";
  //}


  
  Step 3: Show Main Menu Based on the User Type
  while user hasn't chosen to exit {
      
      if userType is Seller {
          
          Print 1. Add a product for sale
          Print 2. Open bidding on a product
          Print 3. Close bidding on a product
          Print 4. View sales history
          Print 5. Update user information
          Print 6. Exit

          Get user selection

          if selection is 1 {
              
              Ask for product details (name, category, starting price, condition)
              Add product to system
              
          } elif selection is 2 {

              Ask for product ID to open for bidding
              put product as active for bidding
              
          } elif selection is 3 {

              Ask for product ID to close bidding
              Determine highest bidder
              Transfer ownership and update balances

          } elif selection is 4 {

              Print past sales transactions

          } elif selection is 5 {

              Allow seller to update phone number, address, or username

          } elif selection is 6 {

              Save users to users.csv
              Save products to products.csv
              Print Goodbye!
              Get out program

          }
      }

      elif userType is Buyer {

          Print 1. View available products
          Print 2. Place a bid on a product
          Print 3. View bidding history
          Print 4. View purchase history
          Print 5. Update user information
          Print 6. Exit

          Get user selection

          if selection is 1 {
              
              Print list of all active products open for bidding
          
          } elif selection is 2 {

              Ask for product ID and bid amount
              if bid is higher than current bid && user has sufficient balance {

                  Place bid and update bid history
                  
              } else {

                  Print Bid isn’t valid, make sure your bid is higher and you have enough balance broke boy

              }
          } elif selection is 3 {

              Print list of previous bids placed by the buyer

          } elif selection is 4 {

              Print list of items won through bidding

          } elif selection is 5 {

              Allow buyer to update phone number, address, or username

          } elif selection is 6 {

              Save users to users.csv
              Save products to products.csv
              Print a bye message
              Turn off program

          }
      }
  }*/
}

void Driver::loadUsers(const std::string& filename) {

 /* // Users.csv
  std::vector<User*> users; 
  std::ifstream file("users.csv");
  std::string line;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string username, address, user_id, user_type;
    std::string phone_str, balance_str;

    // Read values as strings
    std::getline(ss, user_id, ',');
    std::getline(ss, username, ',');
    std::getline(ss, user_type, ',');
    std::getline(ss, phone_str, ',');
    std::getline(ss, address, ',');
    std::getline(ss, balance_str, ',');

    // Convert to proper types
    long phoneNumber = std::stol(phone_str);
    double balance = std::stod(balance_str);

    User *u = new User(username, phoneNumber, address, balance);
    users.push_back(u);
  }

  // Print all usernames
//   for (User* user : users) {
//     std::cout << user->getUsername() << "," << user->getPhoneNumber() << "," << user->getAddress() << "," << user->getBalance() << std::endl;
//   }*/
}

void Driver::loadProducts(const std::string& filename) {}



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