#ifndef _SELLER_H_
#define _SELLER_H_

#include "User.h"
#include <vector>
#include <string>
#include "Product.h"

class Seller : public User
{
private:
    std::vector<Product> productsForSale_; // List of products the seller is selling

    /****************************************************
     * Product Detail Functions
     ****************************************************
    */
    Product *addProduct();
    void getElectronicsDetails(std::string &subcategory, std::string &specificType);
    void getClothingDetails(std::string &subcategory, std::string &specificType);
    void getFurnitureDetails(std::string &subcategory, std::string &specificType);
    void getBookDetails(std::string &subcategory, std::string &specificType);
    void getToolDetails(std::string &subcategory, std::string &specificType);
public:

    Seller(const std::string &uname, long phone, const std::string &addr, double bal);

    /****************************************************
     * Product Management Functions
     ****************************************************
    */
    void postProduct();
    void addProductForSale(const Product &product);
    void displayProductsForSale() const;

    /****************************************************
     * Bidding Functions
     ****************************************************
    */
    void openBid(Product &product);
    void closeBid(Product &product);
    void openBidding(int productId);
    void closeBidding(int productId);

    /****************************************************
     * Sales History Functions
     ****************************************************
    */
    void viewSalesHistory(int productId);

    /****************************************************
     * Account Management Functions
     ****************************************************
    */
    double checkAccountBalance() const;
    void updateUserInformation() override;
};

#endif // _SELLER_H_
