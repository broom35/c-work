
// 用英文是因为不太习惯切中文
// 作者:大号老师
// 时间:2024年6月29日
// 项目:学生管理系统
// 语言:C++
#include "header\Account.h"
#include "header\AccountsManager.h"
#include "header\Student.h"
#include "header\StudentManager.h"
#include <iostream>
bool signIn(AccountsManager& accountsManager);
int signUp(AccountsManager& accountsManager);
int main() {
    AccountsManager accountsManager= AccountsManager();
    accountsManager.Init();
    std::string account,password;
    bool res=0;
   while(true){
    printf("Please enter what mode you want to use:\n");
    printf("1. sign in mode\n"); //登录模式
    printf("2. sign up mode\n"); //注册模式
    printf("3. exit\n"); //退出
    int mode;
    std::cin >> mode;
    switch (mode)
    {
    case 1:
        res= signIn(accountsManager);
        break;
    case 2:
        signUp(accountsManager);
        break;
    case 3:
        printf("Bye!\n");
        return 0;
        break;
    default:

        break;
    }
     if (res)
   {
       printf("correct! now there is your account details\n");
        Account user = accountsManager.getAccount(account);
        user.show();

   }
   }
  
    return 0;
}
bool signIn(AccountsManager& accountsManager) {
    std::string account, password;
    std::cout << "Please enter your account: ";
    std::cin >> account;
    std::cout << "Please enter your password: ";
    std::cin >> password;
    bool isSuccess = accountsManager.SignIn(account, password);
    if (isSuccess) {
        printf("Sign in success!\n");
    }
    return isSuccess;
}
int signUp(AccountsManager& accountsManager) {
    std::string account, password;
    AccountType type;
    int mode;
    std::cout << "Please enter your mod: ";
    std::cin >> mode;
    switch (mode)
    {
    case 1:
        type = AccountType::Student;
        break;
    case 2:
        type = AccountType::Teacher;
        break;
    case 3:
        type = AccountType::Admin;
        break;
    default:
        printf("Please enter the correct mode!\n");   
    }
    std::cout << "Please enter your account: ";
    std::cin >> account;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    bool issuccess = accountsManager.SignUp(account, password,type);
    if (issuccess)
    {
        printf("success:register success\n");
        printf("Please remember your account and password\n");
        printf("Account:%s\n", account.c_str());
        printf("Password:%s\n", password.c_str());
        printf("Type:%d\n", static_cast<int>(type));
        printf("Please sign in again\n");
        return 1;
    }
    printf("Sign up failed!\n");
    return 0;
}