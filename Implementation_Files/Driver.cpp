#include <iostream> // For std::cout
#include <fstream>  // For std::ifstream
#include <sstream>  // For std::stringstream
#include <vector>   // For std::vector
#include <map>      // For std::map
#include <limits>   // For std::numeric_limits
#include "Header_Files/Driver.h"
#include "Header_Files/Bid.h"
#include "Header_Files/UserFactory.h"
#include "Header_Files/ProductFactory.h"

Driver *Driver::instance = nullptr;

// Private constructor
Driver::Driver() : currentUser(nullptr)
{
    // Load users and products from CSV files when the Driver is instantiated
    loadData();
}

/**
 * @brief Destructor for the Driver class.
 *
 * @return void This function cleans up any resources used by the Driver when it's no longer needed.
 */
Driver::~Driver() {}

/****************************************************
 * Singleton and Main Program Functions
 ****************************************************/

/**
 * @brief Gets the singleton instance of the Driver class.
 *
 * @return Driver* A pointer to the single instance of Driver.
 */
Driver *Driver::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Driver();
    }
    return instance;
}

/**
 * @brief Runs the main operations of the program.
 *
 * @return void This function handles user interactions and manages the flow of the application.
 */
void Driver::run()
{
    // Only show welcome message if no user is logged in
    if (currentUser == nullptr)
    {
        welcomeMessage();
    }

    // If a user is logged in, show the main menu
    if (currentUser != nullptr)
    {
        mainMenu();
    }

    // If we get here and no user is logged in, ask again
    if (currentUser == nullptr)
    {
        run();
    }
}

/**
 * @brief Returns the user to the beginning menu.
 *
 * This function displays the beginning menu and allows the user to login, create a new account, or exit the program.
 *
 * @return void This function sets up the new user account.
 */
void Driver::returnToBeginningMenu()
{
    std::cout << "\n\n===================================" << std::endl;
    std::cout << "  What would you like to do now?  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Create a New Account" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    double selection = getValidNumberChoice("Enter your choice: ", 1, 3);

    if (selection == 1)
    {
        User *user = authenticateUser();
        if (user != nullptr)
        {
            // User authenticated successfully
            currentUser = user;
            mainMenu(); // Go directly to main menu after login
        }
        else
        {
            // Failed authentication, try again
            returnToBeginningMenu();
        }
    }
    else if (selection == 2)
    {
        createAccount();
    }
    else if (selection == 3)
    {
        std::cout << "Goodbye!\n";
        exit(0);
    }
}

/**
 * @brief Displays the welcome message and handles user input.
 *
 * This function displays a welcome message and gives options for the user to login, create an account, or exit the program.
 * It then waits for the user to make a selection and processes the choice
 */
void Driver::welcomeMessage()
{
    std::cout << "\n\n===================================" << std::endl;
    std::cout << "  Welcome to the Auction System  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Create a New Account" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    double selection = getValidNumberChoice("Enter your choice: ", 1, 3);

    if (selection == 1)
    {
        User *user = authenticateUser();
        if (user != nullptr)
        {
            // User authenticated successfully
            currentUser = user;
            mainMenu(); // Show main menu right after successful login
        }
        else
        {
            // Authentication failed, return to welcome
            welcomeMessage();
        }
    }
    else if (selection == 2)
    {
        createAccount();
    }
    else if (selection == 3)
    {
        std::cout << "Goodbye!" << std::endl;
        exit(0);
    }
}

/**
 * @brief Displays the main menu for the user.
 *
 * @return void This function shows the options available to the user based on their role.
 */
void Driver::mainMenu()
{
    while (currentUser != nullptr) // Only run the menu if we have a current user
    {
        std::string userType = currentUser->getUserType();

        if (userType == "Seller")
        {
            if (!showSellerMenu())
                return; // Exit if user chose to exit
        }
        else if (userType == "Buyer")
        {
            if (!showBuyerMenu())
                return; // Exit if user chose to exit
        }
    }
}

/**
 * @brief Displays the seller menu for the user.
 *
 * @return void This function shows the options available to the user based on their role.
 */
bool Driver::showSellerMenu()
{
    // Basically just in case it's not a seller
    Seller *seller = dynamic_cast<Seller *>(currentUser);
    if (!seller)
    {
        std::cout << "Error: Current user isn't a seller.\n";
        return false;
    }

    std::cout << "\n\n===================================" << std::endl;
    std::cout << "  Seller Menu  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. Add a product for sale" << std::endl;
    std::cout << "2. Open bidding on a product" << std::endl;
    std::cout << "3. Close bidding on a product" << std::endl;
    std::cout << "4. View sales history" << std::endl;
    std::cout << "5. Update user information" << std::endl;
    std::cout << "6. Logout" << std::endl;
    std::cout << "7. Exit the program" << std::endl;

    int selection = getValidNumberChoice("Select an option: ", 1, 7);

    switch (selection)
    {
    case 1:
        seller->addProduct();
        break;
    case 2:
    {
        int productId = getValidNumberChoice("Enter Product ID to open for bidding: ", 1000, 9999);
        seller->openBidding(productId);
        break;
    }
    case 3:
    {
        int productId = getValidNumberChoice("Enter Product ID to close bidding: ", 1000, 9999);
        seller->closeBidding(productId);
        break;
    }
    case 4:
    {
        int productId = getValidNumberChoice("Enter Product ID (0 to view all): ", 0, 9999);
        seller->viewSalesHistory(productId);
        break;
    }
    case 5:
        updateUserInformation(seller);
        break;
    case 6:
        std::cout << "Logging out...\n";
        currentUser = nullptr; // Clear current user on logout
        returnToBeginningMenu();
        return false; // Exit the seller menu
    case 7:
        std::cout << "Goodbye!\n";
        exit(0);
    default:
        std::cout << "Invalid selection. Please try again.\n";
        break;
    }
    return true; // Continue the menu loop
}

/**
 * @brief Displays the buyer menu for the user.
 *
 * @return void This function shows the options available to the user based on their role.
 */
bool Driver::showBuyerMenu()
{
    // Properly cast the currentUser to Buyer
    Buyer *buyer = dynamic_cast<Buyer *>(currentUser);
    if (!buyer)
    {
        std::cout << "Error: Current user isn't a buyer.\n";
        return false;
    }
    std::cout << "\n\n===================================" << std::endl;
    std::cout << "  Buyer Menu  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. View available products" << std::endl;
    std::cout << "2. Place a bid on a product" << std::endl;
    std::cout << "3. View bidding history" << std::endl;
    std::cout << "4. View purchase history" << std::endl;
    std::cout << "5. Update user information" << std::endl;
    std::cout << "6. Logout" << std::endl;
    std::cout << "7. Exit program" << std::endl;

    int selection = getValidNumberChoice("Select an option: ", 1, 7);

    switch (selection)
    {
    case 1:
        displayAvailableProducts();
        break;
    case 2:
    {
        displayAvailableProducts();
        int productId = getValidNumberChoice("Enter Product ID to bid on: ", 1000, 9999);
        double bidAmount = getValidNumberChoice("Enter bid amount: $", 0.01, 99999.99);
        placeBid(buyer, productId, bidAmount);
        break;
    }
    case 3:
    {
        int productId = getValidNumberChoice("Enter Product ID (0 to view all): ", 0, 9999);
        buyer->viewBiddingHistory(productId);
        break;
    }
    case 4:
    {
        int productId = getValidNumberChoice("Enter Product ID (0 to view all): ", 0, 9999);
        buyer->viewPurchaseHistory(productId);
        break;
    }
    case 5:
        buyer->updateUserInformation();
        break;
    case 6:
        std::cout << "Logging out...\n";
        currentUser = nullptr; // Clear current user on logout
        returnToBeginningMenu();
        return false; // Return false to exit
    case 7:
        std::cout << "Goodbye!\n";
        exit(0);
    default:
        std::cout << "Invalid selection. Please try again.\n";
        break;
    }
    return true; // Continue the menu loop
}

/****************************************************
 * Authentication and Account Functions
 ****************************************************/

/**
 * @brief Authenticates the user based on their username.
 *
 * This function prompts the user to enter their username and checks if it exists in the system.
 * If the username is found, it logs the user in and displays their type.
 * If the username is not found, it offers the user the option to create a new account.
 *
 * @return User* A pointer to the authenticated User object.
 */
User *Driver::authenticateUser()
{
    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    User *existingUser = findExistingUser(username);
    if (existingUser != nullptr)
    {
        std::cout << "Logged in as " << existingUser->getUsername() << " (" << existingUser->getUserType() << ")\n";
        return existingUser;
    }
    else
    {
        char choice;
        std::cout << "Username not found. Would you like to create a new account? (y/n): ";
        std::cin >> choice;
        std::cin.ignore();

        if (validateYesNoInput(choice))
        {
            createAccount();
        }
        else
        {
            returnToBeginningMenu();
        }
        return nullptr;
    }
}

/**
 * @brief Prompts the user to enter a phone number.
 *
 * This function allows the user to input their phone number.
 *
 * @return long The phone number entered by the user.
 */
long Driver::enterPhoneNumber()
{
    std::cout << "Enter phone number: ";
    long phoneNumber;

    while (!(std::cin >> phoneNumber))
    {
        std::cout << "Invalid phone number. Please enter a numeric value: ";
        std::cin.clear(); // Clear error flags
        clearInputBuffer();
    }

    clearInputBuffer(); // Add this back - needed to consume the newline after reading a number
    return phoneNumber;
}

/**
 * @brief Prompts the user to enter an address.
 *
 * This function allows the user to input their address.
 *
 * @return std::string The address entered by the user.
 */
std::string Driver::enterAddress()
{
    std::cout << "Enter address: ";
    std::string address;
    std::getline(std::cin, address);
    return address;
}

/**
 * @brief Prompts the user to enter a starting balance.
 *
 * This function ensures that the balance is a positive number.
 *
 * @return double The starting balance entered by the user.
 */
double Driver::enterBalance()
{
    std::cout << "Enter starting balance: ";
    double balance;

    while (!(std::cin >> balance) || balance < 0)
    {
        if (std::cin.fail())
        {
            std::cout << "Invalid balance. Please enter a numeric value: ";
            std::cin.clear();
            clearInputBuffer();
        }
        else
        {
            std::cout << "Balance can't be negative. Please enter a valid balance: ";
        }
    }

    clearInputBuffer(); // Add this back - needed to consume the newline after reading a number
    return balance;
}

/**
 * @brief Creates a new Buyer account.
 *
 * This function prompts the user for their details and creates a Buyer object using the UserFactory.
 * It ensures that the user has valid input for their balance.
 *
 * @return Buyer* A pointer to the newly created Buyer object.
 */
Buyer *Driver::createBuyer()
{
    std::string username;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    long phoneNumber = enterPhoneNumber();
    std::string address = enterAddress();
    double balance = enterBalance();

    return UserFactory::createBuyer(username, phoneNumber, address, balance);
}

/**
 * @brief Creates a new Seller account.
 *
 * This function prompts the user for their details and creates a Seller object using the UserFactory.
 * It ensures that the user has valid input for their balance.
 *
 * @return Seller* A pointer to the newly created Seller object.
 */
Seller *Driver::createSeller()
{
    std::string username;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    long phoneNumber = enterPhoneNumber();
    std::string address = enterAddress();
    double balance = enterBalance();

    return UserFactory::createSeller(username, phoneNumber, address, balance);
}

/**
 * @brief Logs in a user based on their username.
 *
 * @param username The username of the user trying to log in.
 * @return User* A pointer to the User object if found, or nullptr if the user doesn't exist.
 */
User *Driver::login(const std::string &username)
{
    return nullptr;
}

/**
 * @brief Creates a new account for a user.
 *
 * @param isSeller A boolean that tells us if the new account is for a seller (true) or a buyer (false).
 * @return void This function sets up the new user account.
 */
void Driver::createAccount()
{
    std::cout << "\n\n===================================" << std::endl;
    std::cout << "  Create a New Account  " << std::endl;
    std::cout << "===================================" << std::endl;

    std::cout << "Are you signing up as a: " << std::endl;
    std::cout << "1. Buyer" << std::endl;
    std::cout << "2. Seller" << std::endl;

    double selection = getValidNumberChoice("Enter your choice: ", 1, 2);

    if (selection == 1)
    {
        Buyer *newBuyer = createBuyer();
        users[newBuyer->getUsername()] = newBuyer;
        std::cout << "Account created as a Buyer successfully!" << std::endl;
    }
    else
    {
        Seller *newSeller = createSeller();
        users[newSeller->getUsername()] = newSeller;
        std::cout << "Account created as a Seller successfully!" << std::endl;
    }

    returnToBeginningMenu();
}

/**
 * @brief Finds an existing user by their username.
 *
 * @param username The username of the user we want to find.
 * @return User* A pointer to the User object if found, or nullptr if the user doesn't exist.
 */
User *Driver::findExistingUser(const std::string &username)
{
    auto it = users.find(username); // Use the find method to look for the username
    if (it != users.end())
    {
        return it->second; // Return the User* if found
    }
    return nullptr; // Return nullptr if no matching user is found
}

/****************************************************
 * Product Functions
 ****************************************************/

/**
 * @brief Displays the available products for bidding.
 *
 * @return void This function shows all the products that users can bid on.
 */
void Driver::displayAvailableProducts()
{
    // Display all products that are available for bidding
    for (const auto &pair : products)
    {
        Product *product = pair.second;
        if (product->isActive())
        {
            product->displayProductInfo();
        }
    }
}

/**
 * @brief Gets a product by its ID.
 *
 * @param productId The ID of the product we want to find.
 * @return Product* A pointer to the Product object if found, or nullptr if it doesn't exist.
 */
Product *Driver::getProductById(int productId)
{
    auto it = products.find(productId);
    if (it != products.end())
    {
        return it->second;
    }
    return nullptr;
}

/**
 * @brief Adds a product to the products map.
 *
 * @param productId The ID of the product.
 * @param product The product to add.
 */
void Driver::addProduct(int productId, Product *product)
{
    products[productId] = product;
}

/**
 * @brief Gets all products listed by a specific seller.
 *
 * @param seller A pointer to the Seller object whose products we want to find.
 * @return std::vector<Product*> A vector of pointers to Product objects that belong to the seller.
 */
std::vector<Product *> Driver::getProductsBySeller(Seller *seller)
{
    std::vector<Product *> sellerProducts;

    // Iterate through all products in the products map
    for (const auto &pair : products)
    {
        Product *product = pair.second;
        if (product->getSeller() == seller)
        {
            sellerProducts.push_back(product);
        }
    }

    return sellerProducts;
}

/****************************************************
 * Bid Functions
 ****************************************************/

/**
 * @brief Places a bid on a product by a buyer.
 *
 * @param buyer A pointer to the Buyer object who is placing the bid.
 * @param productId The ID of the product being bid on.
 * @param amount The amount of the bid being placed.
 * @return void This function processes the bid for the specified product.
 */
void Driver::placeBid(Buyer *buyer, int productId, double amount)
{
    Product *product = getProductById(productId);
    if (product && product->isActive())
    {
        product->addBid(buyer, amount);
    }
    else
    {
        std::cout << "Product is not active or does not exist.\n";
    }
}

/**
 * @brief Gets all bids placed by a specific buyer.
 *
 * @param buyer A pointer to the Buyer object whose bids we want to find.
 * @return std::vector<Bid*> A vector of pointers to Bid objects made by the buyer.
 */
std::vector<Bid *> Driver::getBidsByBuyer(Buyer *buyer)
{
    return std::vector<Bid *>();
}

/**
 * @brief Gets all bids for a specific product.
 *
 * @param productId The ID of the product we want to check bids for.
 * @return std::vector<Bid*> A vector of pointers to Bid objects for the specified product.
 */
std::vector<Bid *> Driver::getBidsForProduct(int productId)
{
    return std::vector<Bid *>();
}

/****************************************************
 * User Update Functions
 ****************************************************/

void Driver::updateUserInformation(Seller *seller)
{
    std::string oldUsername = seller->getUsername();

    // Call the seller's updateUserInformation method
    seller->updateUserInformation();

    // If username was changed, update the users map
    std::string newUsername = seller->getUsername();
    if (oldUsername != newUsername)
    {
        // Remove the old username entry
        users.erase(oldUsername);

        // Add the user with the new username
        users[newUsername] = seller;

        std::cout << "Username updated in the system from '" << oldUsername << "' to '" << newUsername << "'\n";
    }
}

/****************************************************
 * Data CSV Files Functions
 ****************************************************/

/**
 * @brief Loads users from a specified CSV file and stores them in the users vector.
 *
 * @param filename The name of the CSV file to read user data from. This should be a string like "users.csv".
 * @return void This function populates the users vector with User objects.
 */
void Driver::loadUsers(const std::string &filename)
{

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "ERROR: Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
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

        User *u = UserFactory::createUserFromCSV(user_id, username, user_type, phoneNumber, address, balance);

        // Add user to the users map using username as key
        if (u != nullptr)
        {
            users[username] = u;
        }
    }

    file.close();
}

/**
 * @brief Loads products from a specified CSV file.
 *
 * @param filename The name of the CSV file to read product data from. This should be a string like "products.csv".
 * @return void This function populates the products vector with Product objects.
 */
void Driver::loadProducts(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;
    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string productIdStr, category, attribute1, attribute2, buyerName, productName, basePriceStr, qualityStr, sellerName;

        // Parse CSV line based on actual bids.csv format:
        // Product ID,Category,Attribute 1,Attribute 2,Buyer,Product Name,Base Price,Quality,Seller
        std::getline(ss, productIdStr, ',');
        std::getline(ss, category, ',');
        std::getline(ss, attribute1, ',');
        std::getline(ss, attribute2, ',');
        std::getline(ss, buyerName, ',');
        std::getline(ss, productName, ',');
        std::getline(ss, basePriceStr, ',');
        std::getline(ss, qualityStr, ',');
        std::getline(ss, sellerName);

        // Convert numeric values
        int productId = std::stoi(productIdStr);
        double basePrice = std::stod(basePriceStr);

        // Find the seller
        Seller *seller = nullptr;
        for (const auto &pair : users)
        {
            User *user = pair.second;
            if (user->getUsername() == sellerName && user->getUserType() == "Seller")
            {
                seller = static_cast<Seller *>(user);
                break;
            }
        }

        if (seller)
        {
            // Convert string to Quality enum
            Quality quality = Quality::Used_Okay; // Default value
            if (qualityStr == "New")
            {
                quality = Quality::New;
            }
            else if (qualityStr == "Used_VeryGood")
            {
                quality = Quality::Used_VeryGood;
            }
            else if (qualityStr == "Used_Good")
            {
                quality = Quality::Used_Good;
            }
            else if (qualityStr == "Used_Okay")
            {
                quality = Quality::Used_Okay;
            }
            else
            {
                std::cout << "Unknown quality '" << qualityStr << "' for product " << productId << ", defaulting to Used_Okay\n";
            }

            Product *product = ProductFactory::CreateProduct(productId, productName, category, basePrice, quality, seller, attribute1, attribute2);

            if (product)
            {
                products[productId] = product;
                seller->addProductForSale(product);
            }
        }
    }

    file.close();
}

/**
 * @brief Loads data for users and products from their respective files.
 *
 * @return void This function prepares the application by loading necessary data.
 */
void Driver::loadData()
{
    // Update paths to look in the "CSV files" directory
    loadUsers("CSV_files/users.csv");
    loadProducts("CSV_files/bids.csv");
}

/**
 * @brief Saves user and product data to their respective CSV files.
 *
 * @return void This function ensures that any changes made during the program are saved.
 */
void Driver::saveData()
{
    // Save users data to CSV
    saveUsers("CSV_files/users.csv");

    // Save products data to CSV
    saveProducts("CSV_files/bids.csv");

    std::cout << "Data saved successfully." << std::endl;
}

/**
 * @brief Saves users data to a CSV file.
 *
 * @param filename The name of the CSV file to write user data to.
 * @return void This function writes user data to a CSV file.
 */
void Driver::saveUsers(const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cout << "ERROR: Could not open file for writing: " << filename << std::endl;
        return;
    }
    

    // Write each user's data
    for (const auto &pair : users)
    {
        User *user = pair.second;
        file << user->getUserId() << ","
             << user->getUsername() << ","
             << user->getUserType() << ","
             << user->getPhoneNumber() << ","
             << user->getAddress() << ","
             << user->getBalance() << std::endl;
    }

    file.close();
}

/**
 * @brief Saves products data to a CSV file.
 *
 * @param filename The name of the CSV file to write product data to.
 * @return void This function writes product data to a CSV file.
 */
void Driver::saveProducts(const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cout << "ERROR: Could not open file for writing: " << filename << std::endl;
        return;
    }

    // Write header row
    file << "Product ID,Category,Attribute 1,Attribute 2,Buyer,Product Name,Base Price,Quality,Seller" << std::endl;

    // Write each product's data
    for (const auto &pair : products)
    {
        Product *product = pair.second;
        Seller *seller = product->getSeller();
        Buyer *buyer = product->getHighestBidder();

        // Convert Quality enum to string
        std::string qualityStr;
        switch (product->getQuality())
        {
        case Quality::New:
            qualityStr = "New";
            break;
        case Quality::Used_VeryGood:
            qualityStr = "Used_VeryGood";
            break;
        case Quality::Used_Good:
            qualityStr = "Used_Good";
            break;
        case Quality::Used_Okay:
            qualityStr = "Used_Okay";
            break;
        default:
            qualityStr = "Unknown";
        }

        // For attribute fields, we don't have direct access in base Product class
        // So we'll leave them empty for now - in a real implementation, derive these from the specific product types
        std::string attribute1 = "";
        std::string attribute2 = "";

        file << product->getProductId() << ","
             << product->getCategory() << ","
             << attribute1 << ","
             << attribute2 << ","
             << (buyer ? buyer->getUsername() : "") << ","
             << product->getName() << ","
             << product->getBasePrice() << ","
             << qualityStr << ","
             << (seller ? seller->getUsername() : "") << std::endl;
    }

    file.close();
}

/****************************************************
 * Helper Functions
 ****************************************************/

/**
 * @brief Helper function to get a valid number from user input
 *
 * @param prompt The prompt to display to the user
 * @param min The minimum valid number
 * @param max The maximum valid number
 * @return T The valid number entered by the user
 */
// Helper function to get a valid number from user input
template <typename T>
T getValidNumberChoice(const std::string &prompt, T min, T max)
{
    T number;
    std::cout << prompt;

    while (!(std::cin >> number) || number < min || number > max)
    {
        // Clear the previous input (Resets cin so we can take a new input)
        std::cin.clear();

        // Discard previous input (Gets rid of the invalid input)
        clearInputBuffer();

        // Explain the error and reprompt
        if (std::cin.fail())
            std::cout << "Error: Invalid input. Please enter a number: ";
        else
            std::cout << "Error: Please enter a number between " << min << " and " << max << ": ";
    }

    clearInputBuffer(); // Add this back to consume the newline after successful input
    return number;
}

template int getValidNumberChoice<int>(const std::string &, int, int);
template double getValidNumberChoice<double>(const std::string &, double, double);

/**
 * @brief Clears the input buffer to prevent issues with getline after cin.
 *
 * This function discards any remaining characters in the input buffer,
 * ensuring that subsequent input operations work correctly.
 *
 * @return void This function does not return a value.
 */
void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Validates the user's input for a yes or no question.
 *
 * This function prompts the user to enter a yes or no answer and validates the input.
 *
 * @param choice The user's input.
 * @return bool True if the input is valid, false otherwise.
 */
bool Driver::validateYesNoInput(char &choice)
{
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        std::cout << "Invalid choice. Please enter 'y' or 'n': ";
        std::cin >> choice;
        std::cin.ignore();
    }

    if (choice == 'y' || choice == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}