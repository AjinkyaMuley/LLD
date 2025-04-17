#ifndef USER_HPP
#define USER_HPP

#include "../UserExpenseBalanceSheet.hpp"
#include <bits/stdc++.h>
using namespace std;

class UserExpenseBalanceSheet;

class User
{
public:
    string userId;
    string userName;
    UserExpenseBalanceSheet *userExpenseBalanceSheet;

    User(string id, string name)
    {
        this->userId = id;
        this->userName = name;
        this->userExpenseBalanceSheet = new UserExpenseBalanceSheet(); // Initialize the balance sheet
    }

    string getUserId()
    {
        return userId;
    }

    UserExpenseBalanceSheet *getUserExpenseBalanceSheet()
    {
        return userExpenseBalanceSheet;
    }
};

#endif