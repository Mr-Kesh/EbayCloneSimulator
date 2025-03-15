#ifndef _USER_H_
#define _USER_H_

#include <vector>
#include <iostream>
#include <string>

class User {
protected:
    std::string username_;
    long phone_no_;
    std::string address_;
    double account_balance_;
    

public:

    // Constructor
    User(const std::string& username, long phoneNumber, const std::string& address, double balance);

    // Virtual destructor (important for base classes)
    virtual ~User() {}

    //virtual std::string getUserType() const = 0;  // Pure virtual function


    // Getters - inline implementation
    std::string getUsername() const { return username_; }
    long getPhoneNumber() const { return phone_no_; }
    std::string getAddress() const { return address_; }
    double getBalance() const { return account_balance_; } // check account balance

    // Setters
    void setUsername(std::string new_username);
    void setPhoneNumber(long new_phone_no);
    void setAddress(std::string new_address);
    void updateBalance(double amount);
};

#endif  // _USER_H_
