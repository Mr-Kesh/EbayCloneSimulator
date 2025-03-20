#include "Seller.h"
#include <iostream>
#include <limits>
#include "ProductFactory.h"
#include "User.h"
#include "Driver.h"

// Constructor
Seller::Seller(const std::string &uname, long phone, const std::string &addr, double bal) : User(uname, phone, addr, bal)
{
    user_type_ = "Seller";
}

// Makes sure that the user can only enter a number between a min and max value and is valid
extern double getValidNumberChoice(const std::string &prompt, double min, double max);

/**
 * @brief Posts a product for sale.
 *
 * This function posts a product for sale.
 *
 * @param name The name of the product.
 * @param category The category of the product.
 * @param startingPrice The starting price of the product.
 * @param quality The quality of the product.
 */
void Seller::postProduct()
{
    std::cout << "Posting a new product for sale!" << std::endl;
    addProduct(this); 
}


/**
 * @brief Opens bidding on a product.
 *
 * This function sets the product as available for bidding.
 *
 * @param product The product to open bidding on.
 */
void Seller::openBid(Product &product)
{
    // Set product as available for bidding
    product.setIsActive(true);
}

/**
 * @brief Closes bidding on a product.
 *
 * This function sets the product as unavailable for bidding.
 *
 * @param product The product to close bidding on.
 */
void Seller::closeBid(Product &product)
{
    // Close bidding on a product
    product.setIsActive(false);
}

/**
 * @brief Checks if a product has been sold.
 *
 * This function returns true if the product has been sold, otherwise it returns false.
 *
 * @param product The product to check.
 */
bool Seller::soldOrNot(const Product &product) const
{
    // Check if a product has been sold
    return product.isSold();
}

/**
 * @brief Checks the seller's account balance.
 *
 * This function returns the seller's account balance.
 *
 * @return double The seller's account balance.
 */
double Seller::checkAccountBalance() const
{
    // Return the seller's account balance
    return getBalance();
}

/**
 * @brief Adds a product to the seller's list of products for sale.
 *
 * This function adds a product to the seller's list of products for sale.
 *
 * @param product The product to add to the seller's list of products for sale.
 */
void Seller::addProductForSale(const Product &product)
{
    productsForSale_.push_back(product);
}

/**
 * @brief Displays the products listed by the seller.
 *
 * This function iterates through the products listed by the seller and displays their information.
 *
 * @return void This function does not return any value.
 */
void Seller::displayProductsForSale() const
{
    std::cout << "===================================" << std::endl;
    std::cout << "  Your Products for Sale  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "Products listed by " << getUsername() << ":" << std::endl;
    for (const auto &product : productsForSale_)
    {
        product.displayProductInfo();
    }
}

/**
 * @brief Updates the user's information.
 *  
 * This function allows the user to update their username, phone number, and address.
 * It prompts the user to enter new values for these fields, and only updates them if
 * new values are provided.
 *
 */
void Seller::updateUserInformation()
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

/**
 * @brief Adds a new product to the system for a seller.
 *
 * @param seller A pointer to the Seller object who is adding the product.
 * @return void This function adds the product to the system.
 */
void Seller::addProduct(Seller *seller)
{
    std::string name, category, subcategory, specificType, attribute1, attribute2;
    std::string customCategory;
    double price;
    int qualityChoice;

    std::cout << "===================================" << std::endl;
    std::cout << "  Add a Product!  " << std::endl;
    std::cout << "===================================" << std::endl;

    std::cout << "Enter the name of the product: ";
    std::getline(std::cin, name);

    // Get main category choice using the new function
    int categoryChoice = getValidNumberChoice("Select category:\n1. Electronics\n2. Clothing\n3. Furniture\n4. Books\n5. Tools\nEnter choice: ", 1, 5);
    // Process category selection using helper functions
    switch (categoryChoice)
    {
    case 1:
        category = "Electronics";
        getElectronicsDetails(subcategory, specificType);
        break;
    case 2:
        category = "Clothing";
        getClothingDetails(subcategory, specificType);
        break;
    case 3:
        category = "Furniture";
        getFurnitureDetails(subcategory, specificType);
        break;
    case 4:
        category = "Books";
        getBookDetails(subcategory, specificType);
        break;
    case 5:
        category = "Tools";
        getToolDetails(subcategory, specificType);
        break;
    default:
        std::cout << "Invalid category.\n";
        return;
    }

    // Get price with validation
    price = getValidNumberChoice("Enter base price: ", 0.01, std::numeric_limits<double>::max());

    // Get quality with validation
    qualityChoice = getValidNumberChoice("Select product quality:\n0: New\n1: Used_VeryGood\n2: Used_Good\n3: Used_Okay\nEnter choice: ", 0, 3);
    Quality quality = static_cast<Quality>(qualityChoice);

    // Step 5: Create the product using `ProductFactory`
    // This line creates a formatted string for the product's category. specificType is only added if it's not empty so we don't end up with an extra colon at the end.
    std::string formattedCategory = category + ":" + subcategory + (specificType.empty() ? "" : (":" + specificType));

    // Generate a product ID the next available one so if the previous productID was 1001, the new one will be 1002
    int productId = getNextProductId();
    // Create a new product using the ProductFactory with all the details we gathered
    Product *newProduct = ProductFactory::CreateProduct(productId, formattedCategory, name, price, quality, seller, attribute1, attribute2);

    // Check if the product was created successfully
    if (newProduct)
    {
        // Add the new product to our products map using its ID
        products[newProduct->getProductId()] = newProduct;
        // Save the updated product list to a CSV file
        saveData();

        std::cout << "Product " << name << " listed for sale under " << category << " successfully!\n";
    }
    else
    {

        std::cout << "Error creating product.\n";
    }
}

/**
 * @brief Helper function to get details for Electronics products.
 *
 * @param subcategory Reference to store the subcategory.
 * @param specificType Reference to store the specific type.
 */
void Seller::getElectronicsDetails(std::string &subcategory, std::string &specificType)
{
    // Get subcategory with validation
    int subcategoryChoice = getValidNumberChoice("Select subcategory:\n1. Computer\n2. Phone\n3. TV\n", 1, 3);

    std::string customCategory;
    int typeChoice;

    // Process based on subcategory choice
    if (subcategoryChoice == 1)
    { // Computer
        subcategory = "Computer";
        typeChoice = getValidNumberChoice("Select computer type:\n1. Laptop\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Laptop";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of computer you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 2)
    { // Phone
        subcategory = "Phone";
        typeChoice = getValidNumberChoice("Select phone type:\n1. Smartphone\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Smartphone";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of phone you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 3)
    { // TV
        subcategory = "TV";
        typeChoice = getValidNumberChoice("Select TV type:\n1. Smart TV\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Smart TV";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of TV you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
}

/**
 * @brief Helper function to get details for Clothing products.
 *
 * @param subcategory Reference to store the subcategory.
 * @param specificType Reference to store the specific type.
 */
void Seller::getClothingDetails(std::string &subcategory, std::string &specificType)
{
    // Get subcategory with validation
    int subcategoryChoice = getValidNumberChoice("Select type:\n1. Shirt\n2. Pants\n3. Shoes\n", 1, 3);

    std::string customCategory;
    int typeChoice;

    // Process based on subcategory choice
    if (subcategoryChoice == 1)
    { // Shirt
        subcategory = "Shirt";
        typeChoice = getValidNumberChoice("Select shirt type:\n1. T-Shirt\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "T-Shirt";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of shirt you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 2)
    { // Pants
        subcategory = "Pants";
        typeChoice = getValidNumberChoice("Select pants type:\n1. Jeans\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Jeans";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of pants you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 3)
    { // Shoes
        subcategory = "Shoes";
        typeChoice = getValidNumberChoice("Select shoes type:\n1. Sneakers\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Sneakers";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of shoes you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
}

/**
 * @brief Helper function to get details for Furniture products.
 *
 * @param subcategory Reference to store the subcategory.
 * @param specificType Reference to store the specific type.
 */
void Seller::getFurnitureDetails(std::string &subcategory, std::string &specificType)
{
    // Get subcategory with validation
    int subcategoryChoice = getValidNumberChoice("Select furniture type:\n1. Chair\n2. Table\n3. Bed\n", 1, 3);

    std::string customCategory;
    int typeChoice;

    // Process based on subcategory choice
    if (subcategoryChoice == 1)
    { // Chair
        subcategory = "Chair";
        typeChoice = getValidNumberChoice("Select chair type:\n1. Office Chair\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Office Chair";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of chair you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 2)
    { // Table
        subcategory = "Table";
        typeChoice = getValidNumberChoice("Select table type:\n1. Coffee Table\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Coffee Table";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of table you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 3)
    { // Bed
        subcategory = "Bed";
        typeChoice = getValidNumberChoice("Select bed type:\n1. Twin Bed\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Twin Bed";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of bed you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
}

/**
 * @brief Helper function to get details for Book products.
 *
 * @param subcategory Reference to store the subcategory.
 * @param specificType Reference to store the specific type.
 */
void Seller::getBookDetails(std::string &subcategory, std::string &specificType)
{
    // Get subcategory with validation
    int subcategoryChoice = getValidNumberChoice("Select book type:\n1. Fiction\n2. Non-Fiction\n3. Comic\n", 1, 3);

    std::string customCategory;
    int typeChoice;

    // Process based on subcategory choice
    if (subcategoryChoice == 1)
    { // Fiction
        subcategory = "Fiction";
        typeChoice = getValidNumberChoice("Select fiction type:\n1. Novel\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Novel";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of fiction you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 2)
    { // Non-Fiction
        subcategory = "Non-Fiction";
        typeChoice = getValidNumberChoice("Select non-fiction type:\n1. Textbook\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Textbook";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of non-fiction you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 3)
    { // Comic
        subcategory = "Comic";
        typeChoice = getValidNumberChoice("Select comic type:\n1. Graphic Novel\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Graphic Novel";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of comic you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
}

/**
 * @brief Helper function to get details for Tool products.
 *
 * @param subcategory Reference to store the subcategory.
 * @param specificType Reference to store the specific type.
 */
void Seller::getToolDetails(std::string &subcategory, std::string &specificType)
{
    // Get subcategory with validation
    int subcategoryChoice = getValidNumberChoice("Select tool type:\n1. Hand Tool\n2. Power Tool\n3. Garden Tool\n", 1, 3);

    std::string customCategory;
    int typeChoice;

    // Process based on subcategory choice
    if (subcategoryChoice == 1)
    { // Hand Tool
        subcategory = "Hand Tool";
        typeChoice = getValidNumberChoice("Select hand tool type:\n1. Hammer\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Hammer";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of hand tool you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 2)
    { // Power Tool
        subcategory = "Power Tool";
        typeChoice = getValidNumberChoice("Select power tool type:\n1. Drill\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Drill";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of power tool you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
    else if (subcategoryChoice == 3)
    { // Garden Tool
        subcategory = "Garden Tool";
        typeChoice = getValidNumberChoice("Select garden tool type:\n1. Lawn Mower\n2. Custom\n", 1, 2);

        if (typeChoice == 1)
        {
            specificType = "Lawn Mower";
        }
        else if (typeChoice == 2)
        {
            std::cout << "Please enter the type of garden tool you want to create: ";
            std::getline(std::cin, customCategory);
            specificType = customCategory;
        }
    }
}

/**
 * @brief Opens bidding on a product.
 *
 * @param seller A pointer to the Seller object who owns the product.
 * @param productId The ID of the product that is being opened for bidding.
 * @return void This function opens the bidding process for the product.
 */
void Seller::openBidding(Seller *seller, int productId)
{
    Product *product = getProductById(productId);
    if (product)
    {
        product->openBidding();
    }
    else
    {
        std::cout << "Product not found.\n";
    }
}

/**
 * @brief Closes bidding on a product and determines the winner.
 *
 * @param seller A pointer to the Seller object who owns the product.
 * @param productId The ID of the product that is being closed for bidding.
 * @return void This function finalizes the bidding process for the product.
 */
void Seller::closeBidding(Seller *seller, int productId)
{
    Product *product = getProductById(productId);
    if (product)
    {
        product->closeBidding();
    }
    else
    {
        std::cout << "Product not found.\n";
    }
}

/**
 * @brief Displays the sales history of a product.
 *
 * @param seller A pointer to the Seller object who owns the product.
 * @param productId The ID of the product that is being viewed.
 * @return void This function displays the sales history of the product.
 */
void Seller::viewSalesHistory(Seller *seller, int productId)
{
    Product *product = getProductById(productId);
    if (product)
    {
        product->viewSalesHistory();
    }
}


/**
 * @brief Gets a seller by their username.
 *
 * @param username The username of the seller we want to find.
 * @return Seller* A pointer to the Seller object if found, or nullptr if the seller doesn't exist.
 */
Seller *Seller::getSellerByUsername(const std::string &username)
{
    // Use the sellers collection to find the seller by username
    for (Seller *seller : sellers)
    {
        if (seller->getUsername() == username)
        {
            return seller; // Return the matching seller
        }
    }
    return nullptr;
}

/**
 * @brief Helper function to get the next available product ID
 *
 * @return int The next available product ID
 */
int Seller::getNextProductId()
{
    int maxId = 0;
    for (const auto &pair : products)
    {
        if (pair.first > maxId)
        {
            maxId = pair.first;
        }
    }
    return maxId + 1;
}


