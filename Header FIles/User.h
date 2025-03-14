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

    // Getters
    std::string getUsername() const;
    long getPhoneNumber() const;
    std::string getAddress() const;
    double getBalance() const; // check account balance

    // Setters
    void setUsername(std::string new_username);
    void setPhoneNumber(long new_phone_no);
    void setAddress(std::string new_address);
    void updateBalance(double amount);
};

#endif  // _USER_H_
