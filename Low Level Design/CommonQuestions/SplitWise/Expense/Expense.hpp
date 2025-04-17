#ifndef EXPENSEHPP
#define EXPENSEHPP

#include "./Split/Split.hpp"
#include "../User/User.hpp"
#include "ExpenseSplitType.hpp"
#include <bits/stdc++.h>
using namespace std;

class User;
class Split;
enum ExpenseSplitType;

class Expense
{
public:
    string expenseId;
    string description;
    double expenseAmount;
    User *paidByUser;
    ExpenseSplitType splitType;
    vector<Split *> splitDetails = vector<Split *>();

    Expense(string expenseId, double expenseAmount, string description, User *paidByUser, ExpenseSplitType splitType, vector<Split *> splitDetails)
    {
        this->expenseId = expenseId;
        this->expenseAmount = expenseAmount;
        this->description = description;
        this->paidByUser = paidByUser;
        this->splitDetails.insert(this->splitDetails.end(), splitDetails.begin(), splitDetails.end());
        this->splitType = splitType;
    }
};

#endif