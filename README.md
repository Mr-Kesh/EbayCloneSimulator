Jenna and Jeshua's CSCI 3010 HW3

![Build Status](https://github.com/jejo8526/programming-workshop-hw3/actions/workflows/c-cpp.yml/badge.svg)


# BidToBuy: CLI-Based eBay Simulation

Jenna and Jeshua's CSCI 3010 - Intensive Programming Workshop - HW3

## Overview

BidToBuy is a command-line interface (CLI) application that simulates an online auction platform similar to eBay. The application allows buyers to bid on products posted by sellers, with the highest bidder winning once the auction closes. The project incorporates object-oriented programming principles, inheritance, design patterns, and file-based data storage.

## Features

### General Features
* Loads users and products from CSV files
* Users can choose a role: Buyer or Seller
* Implements a Singleton Driver class to manage users, products, and bids

### Seller Features
* Post products for sale with a base price and quality indicator
* View historical prices of similar products
* Check account balance
* Update user information
* View products sold or still available
* Open and close bids on products
* View entire bid history for their products

### Buyer Features
* Browse available products for sale
* Place bids on active listings (limited by account balance)
* Check account balance
* Update user information
* View bid history and purchased products
* Receive notifications on bid status

### Bidding System
* Products accept bids until the seller closes the auction
* Buyers can bid on multiple products
* The highest bidder wins, provided they have sufficient funds
* If the highest bidder defaults, the product is awarded to the next highest bidder
* Unsold products can be relisted by the seller
* Sold products cannot be resold

### Product Categories & Inheritance
* At least 5 product categories with a minimum of 3 levels of inheritance per category
* Products include different quality ratings: New, Used-VeryGood, Used-Good, Used-Okay
* Detailed class structures for robust inheritance design

## Implementation Details
* Programming Language: C++
* Design Patterns Used:
  * Singleton: Driver class to manage application state
  * Factory Pattern: Creating products dynamically
  * Maps: Tracking users, products, and bids efficiently
* File Storage:
  * CSV files store user and product data
  * loadUsers() and loadProducts() functions read from CSV files
* Makefile: For compiling and running the program
* CI/CD Pipeline: Set up for GitHub repository

## File Structure:

```|-- src/
|   |-- main.cpp
|   |-- Driver.cpp
|   |-- Driver.h
|   |-- User.cpp
|   |-- User.h
|   |-- Product.cpp
|   |-- Product.h
|   |-- Buyer.cpp
|   |-- Buyer.h
|   |-- Seller.cpp
|   |-- Seller.h
|   |-- Bid.cpp
|   |-- Bid.h
|
|-- data/
|   |-- users.csv
|   |-- products.csv
|
|-- output/
|   |-- output.txt
|
|-- Makefile
|-- README.md
```


## Running the Program

1. Clone the repository:

```git clone https://github.com/jejo8526/programming-workshop-hw3.git```

2. Compile the program using Makefile:

  ```make main```

3. Run the program:

  ```./main```

## Output
Example game output is in output.txt

## Contributors

Jeshua Dimawea and Jenna Jones


