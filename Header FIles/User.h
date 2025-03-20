#ifndef _USER_H_
#define _USER_H_

#include <vector>
#include <iostream>
#include <string>

class User
{
protected:
    int user_id_;
    std::string username_;
    long phone_no_;
    std::string address_;
    double account_balance_;
    std::string user_type_;

public:
    // Constructor
    User(const std::string &username, long phoneNumber, const std::string &address, double balance);

    // Virtual destructor (important for base classes)
    virtual ~User() {}

    // Getters - inline implementation
    std::string getUsername() const { return username_; }
    long getPhoneNumber() const { return phone_no_; }
    std::string getAddress() const { return address_; }
    double getBalance() const { return account_balance_; }
    virtual std::string getUserType() const { return user_type_; }
    // Setters
    void setUsername(std::string new_username) { username_ = new_username; }
    void setPhoneNumber(long new_phone_no) { phone_no_ = new_phone_no; }
    void setAddress(std::string new_address) { address_ = new_address; }
    void updateBalance(double amount) { account_balance_ += amount; }
    virtual void updateUserInformation();
};

#endif // _USER_H_
