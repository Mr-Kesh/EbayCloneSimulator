#ifndef PRODUCT_FACTORY_H_
#define PRODUCT_FACTORY_H_

// Forward declaration
class Seller;

#include "Product.h"
#include "Electronics.h"
#include "Clothing.h"
#include "Furniture.h"
#include "Books.h"
#include "Tools.h"

class ProductFactory
{
public:

    // Main factory method with consistent parameter order
    static Product *CreateProduct(int productId, const std::string &name, const std::string &category, double base_price,
                                  const Quality quality, Seller *seller, const std::string &attribute1 = "", const std::string &attribute2 = "")
    {
        // We need to break down the category string into parts: main, sub, and specific type
        std::string mainCategory, subCategory, specificType;

        // Find the position of the first colon (:) to separate main category
        size_t posMainCategory = category.find(":");

        // Find the position of the second colon (:) for sub-category
        size_t posSubCategory = category.find(":", posMainCategory + 1);

        // Find the position of the third colon (:) for specific type
        size_t posSpecificType = category.find(":", posSubCategory + 1);

        // If we found the main category
        if (posMainCategory != std::string::npos)
        {
            // Get the main category from the start to the first colon
            mainCategory = category.substr(0, posMainCategory);
        }
        else
        {
            // If there's no colon, the whole string is the main category
            mainCategory = category;
        }

        // If we found the sub-category
        if (posSubCategory != std::string::npos)
        {
            // Get the sub category from the first colon to the second colon
            subCategory = category.substr(posMainCategory + 1, posSubCategory - posMainCategory - 1);
        }
        else if (posMainCategory != std::string::npos)
        {
            // If there's no sub category, just take what's after the main category
            subCategory = category.substr(posMainCategory + 1);
        }

        // If we found the specific type
        if (posSpecificType != std::string::npos)
        {
            // Get the specific type from the second colon to the third colon
            specificType = category.substr(posSubCategory + 1, posSpecificType - posSubCategory - 1);
        }

        // Product factory based on the main category, sub category, and specific type
        // Alright, let's check out the main category first
        if (mainCategory == "Electronics") // If it's electronics
        {
            if (subCategory == "Phone") // And it's a phone
            {
                if (specificType == "Smartphone")
                {                                                                                                // If it's a smartphone
                    return new Smartphone(productId, name, base_price, quality, seller, attribute1, attribute2); // Create a smartphone
                }
                return new Phone(productId, name, base_price, quality, seller, attribute1, attribute2); // Otherwise, just a regular phone
            }
            else if (subCategory == "Computer") // If it's a computer
            {
                if (specificType == "Laptop")
                {                                                                                            // And it's a laptop
                    return new Laptop(productId, name, base_price, quality, seller, attribute1, attribute2); // Create a laptop
                }
                return new Computer(productId, name, base_price, quality, seller, attribute1, attribute2); // Otherwise, just a regular computer
            }
            else if (subCategory == "TV") // If it's a TV
            {
                if (specificType == "Smart TV")
                {                                                                                             // And it's a smart TV
                    return new SmartTV(productId, name, base_price, quality, seller, attribute1, attribute2); // Create a smart TV
                }
                return new TV(productId, name, base_price, quality, seller, attribute1, attribute2); // Otherwise, just a regular TV
            }
            return new Electronics(productId, name, base_price, quality, seller, attribute1, attribute2); // If none of the above, just create a generic electronics item
        }

        if (mainCategory == "Clothing") // Now, let's check if it's clothing
        {
            if (subCategory == "Shoes") // If it's shoes
            {
                if (specificType == "Sneakers")
                {                                                                                                 // And it's sneakers
                    return new Clothing(productId, name, base_price, quality, seller, subCategory, specificType); // Create sneakers
                }
                return new Clothing(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just regular shoes
            }
            else if (subCategory == "Pants")
            { // If it's pants
                if (specificType == "Jeans")
                {                                                                                                 // And it's jeans
                    return new Clothing(productId, name, base_price, quality, seller, subCategory, specificType); // Create jeans
                }
                return new Clothing(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just regular pants
            }
            else if (subCategory == "Shirt")
            { // If it's a shirt
                if (specificType == "TShirt")
                {                                                                                                 // And it's a T-shirt
                    return new Clothing(productId, name, base_price, quality, seller, subCategory, specificType); // Create a T-shirt
                }
                return new Clothing(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just a regular shirt
            }
            return new Clothing(productId, name, base_price, quality, seller, subCategory, attribute1); // If none of the above, create a generic clothing item
        }

        if (mainCategory == "Books") // Next up, books
        {
            if (subCategory == "Fiction") // If it's fiction
            {
                if (specificType == "Novel")
                {                                                                                              // And it's a novel
                    return new Books(productId, name, base_price, quality, seller, subCategory, specificType); // Create a novel
                }
                return new Books(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just a fiction book
            }
            else if (subCategory == "Non-Fiction")
            { // If it's non-fiction
                if (specificType == "Textbook")
                {                                                                                              // And it's a textbook
                    return new Books(productId, name, base_price, quality, seller, subCategory, specificType); // Create a textbook
                }
                return new Books(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just a non-fiction book
            }
            else if (subCategory == "Comic")
            { // If it's a comic
                if (specificType == "Graphic Novel")
                {                                                                                              // And it's a graphic novel
                    return new Books(productId, name, base_price, quality, seller, subCategory, specificType); // Create a graphic novel
                }
                return new Books(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just a comic
            }
            return new Books(productId, name, base_price, quality, seller, subCategory, attribute1); // If none of the above, create a generic book
        }

        if (mainCategory == "Furniture") // Now, furniture time
        {
            if (subCategory == "Chair") // If it's a chair
            {
                if (specificType == "Office Chair")
                {                                                                                                  // And it's an office chair
                    return new Furniture(productId, name, base_price, quality, seller, subCategory, specificType); // Create an office chair
                }
                return new Furniture(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just a regular chair
            }
            else if (subCategory == "Table")
            { // If it's a table
                if (specificType == "Coffee Table")
                {                                                                                                  // And it's a coffee table
                    return new Furniture(productId, name, base_price, quality, seller, subCategory, specificType); // Create a coffee table
                }
                return new Furniture(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just a regular table
            }
            else if (subCategory == "Bed")
            { // If it's a bed
                if (specificType == "Twin Bed")
                {                                                                                                  // And it's a twin bed
                    return new Furniture(productId, name, base_price, quality, seller, subCategory, specificType); // Create a twin bed
                }
                return new Furniture(productId, name, base_price, quality, seller, subCategory, "Generic"); // Otherwise, just a regular bed
            }
            return new Furniture(productId, name, base_price, quality, seller, subCategory, attribute1); // If none of the above, create a generic furniture item
        }

        if (mainCategory == "Tools") // Finally, tools
        {
            // For simplicity, we'll just create a generic Tools object
            return new Tools(productId, name, base_price, quality, seller, attribute1);
        }

        return product;
    }
};

#endif // PRODUCT_FACTORY_H_