#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <sstream>
#include <iostream>
enum class AccountType {
    Student,
    Teacher,
    Admin
};
class Account {
public:
    Account(const std::string& account, const std::string& password, AccountType type)
        : account_(account), password_(password), type_(type) {}
    Account() {}
    ~Account() {}
    std::string getAccount() const { return account_; }
    std::string getPassword() const { return password_; }
    AccountType getType() const { return type_; }
    std::string serialize() const {
        return account_ + " " + password_ + " " + std::to_string(static_cast<int>(type_));
    }
    bool deserialize(const std::string& str) {
        std::string account, password;
        int type;
        std::istringstream iss(str);
        iss >> account >> password >> type;
        account_ = account;
        password_ = password;
        type_ = static_cast<AccountType>(type);
        return 1;
    }
    void show() const {
        std::cout << "Account: " << account_
                  << ",\n Password: " << password_
                  << ",\n Type: " << static_cast<int>(type_) << std::endl;
    }
private:
    std::string account_;
    std::string password_;
    AccountType type_;
};
#endif // ACCOUNT_H
