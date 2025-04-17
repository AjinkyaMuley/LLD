#ifndef USEREXPENSEBALANCESHEET_HPP
#define USEREXPENSEBALANCESHEET_HPP

#include "Balance.hpp"
#include <unordered_map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Balance;

class UserExpenseBalanceSheet{
    public:
        unordered_map<string,Balance*> userVsBalance;
        double totalYourExpense;

        double totalPayment;

        double totalYouOwe;
        double totalYouGetBack;

        UserExpenseBalanceSheet()
        {
            userVsBalance = unordered_map<string,Balance*>();
            totalYourExpense = 0;
            totalYouOwe = 0;
            totalYouGetBack = 0;
        }

        unordered_map<string,Balance*> getUserVsBalance()
        {
            return userVsBalance;
        }

        double getTotalYourExpense()
        {
            return totalYourExpense;
        }

        void setTotalYourExpense(double totalYourExpense)
        {
            this->totalYourExpense = totalYourExpense;
        }

        double getTotalYouOwe()
        {
            return totalYouOwe;
        }

        void setTotalYouOwe(double totalYouOwe)
        {
            this->totalYouOwe = totalYouOwe;
        }

        double getTotalYouGetBack()
        {
            return totalYouGetBack;
        }

        void setTotalYouGetBack(double totalYouGetBack)
        {
            this->totalYouGetBack = totalYouGetBack;
        }

        double getTotalPayment()
        {
            return totalPayment;
        }

        void setTotalPayment(double totalPayment)
        {
            this->totalPayment = totalPayment;
        }
};

#endif