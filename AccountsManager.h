#ifndef ACCOUNTSMANAGER_H
#define ACCOUNTSMANAGER_H
#include "Account.h"
#include"StudentsManager.h"
#include"TeachersManager.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
namespace ASM{
const std::string filename = "accounts.txt";
class AccountsManager {
public:
    SSM::StudentManager *SSMinstance;
    AccountsManager() {}
    ~AccountsManager() {
        Destroy();
    }
    // static AccountsManager* getInstance(){
    //     return instance;
    // }
    //一些无用功
    ///<summary>
    ///read all accounts from file , if success ,return true, else return false
    ///</summary>
    bool Init()
    {
        //this->instance = this;
        if (!Load()) {
            return false;
        }
        return true;
    }
    ///<summary>
    ///when destroy the object, save all accounts to file
    ///</summary>
    bool Destroy()
    {
        return Save();
    }
    ///<summary>
    ///save all accounts to file
    ///</summary>
    bool Save()
    {

        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return 0;
        }

        for (const auto& account : accounts_) {
            // 这里假设 Account 类有一个名为 serialize 的方法，用于将对象转换为字符串
            file << account.serialize() << std::endl;
        }

        return true;
    }
    ///<summary>
    ///load all accounts from file
    ///</summary>
    bool Load()
    {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return 0;
        }

        std::string line;
        while (std::getline(file, line)) {
            Account account;
            // 这里假设 Account 类有一个名为 deserialize 的方法，用于将字符串转换为对象
            account.deserialize(line);
            accounts_.push_back(account);
        }
        return true;
    }
    ///<summary>
    ///add a new account
    ///</summary>
    bool AddAccount(const Account& account)
    {
        accounts_.push_back(account);
        return true;
    }
    ///<summary>
    ///delete a account
    ///</summary>
    bool DeleteAccount(const std::string& account)
    {
        for (auto it = accounts_.begin(); it != accounts_.end(); ++it) {
            if (it->getAccount() == account) {
                accounts_.erase(it);
                return true;
            }
        }
        return false;
    }
    bool SignIn(const std::string& account, const std::string& password)
    {
        for (const auto& acc : accounts_) {
            if (acc.getAccount() == account && acc.getPassword() == password) {
                return true;
            }
        }
        printf("failed:account or password error\n");
        return false;
    }
    ///<summary>
    /// signup a new account
    ///</summary>
    bool SignUp(const std::string& account, const std::string& password, int ty)
    {
        if(ty==0&&!this->SSMinstance->isAllowSignUp(account)){
            return 0;
        }
        AccountType type;
        switch (ty) {
        case 0:
            type = AccountType::Student;
            break;
        case 1:
            type = AccountType::Teacher;
            break;
        default:
            return false;
            break;
        }
        for (const auto& acc : accounts_) {
            if (acc.getAccount() == account) {
                return false;
                printf("failed:The account has been registered\n");
            }
        }
        Account newAccount(account, password, type);
        accounts_.push_back(newAccount);
        printf("success:register success\n");
        return true;
    }
    Account& getAccount(const std::string& account)
    {
        for (auto& acc : accounts_) {
            if (acc.getAccount() == account) {
                return acc;
            }
        }
        // return
    }
private:
    std::vector<Account> accounts_;
    //static AccountsManager* instance;
};
}

#endif // ACCOUNTSMANAGER_H
