#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include <vector>
#include <string>

// Forward declaration
class Product;

class Seller : public User
{
private:
    std::vector<Product *> productsForSale_; // List of products the seller is selling

    /****************************************************
     * Product Detail Functions
     ****************************************************
     */
    void getElectronicsDetails(std::string &subcategory, std::string &specificType);
    void getClothingDetails(std::string &subcategory, std::string &specificType);
    void getFurnitureDetails(std::string &subcategory, std::string &specificType);
    void getBookDetails(std::string &subcategory, std::string &specificType);
    void getToolDetails(std::string &subcategory, std::string &specificType);

public:
    Seller(const std::string &username, long phoneNumber, const std::string &address, double balance);

    /****************************************************
     * Product Management Functions
     ****************************************************
     */
    Product *addProduct();
    void postProduct();
    void displayProductsForSale() const;
    void addProductForSale(Product *product);

    /****************************************************
     * Bidding Functions
     ****************************************************
     */
    void openBid(Product *product);
    void closeBid(Product *product);
    void openBidding(int productId);
    void closeBidding(int productId);

    /****************************************************
     * Sales History Functions
     ****************************************************
     */
    void viewHistoricalPrices(const std::string &category) const;
    void viewSalesHistory(int productId);
    void viewSalesHistory(const Product &product) const;

    /****************************************************
     * Account Management Functions
     ****************************************************
     */
    double checkAccountBalance() const;
    void updateUserInformation() override;

    /****************************************************
     * Helper Functions
     ****************************************************
     */
    bool soldOrNot(const Product *product) const;
    int getNextProductId();
    static Seller *getSellerByUsername(const std::string &username);
};

#endif // SELLER_H
