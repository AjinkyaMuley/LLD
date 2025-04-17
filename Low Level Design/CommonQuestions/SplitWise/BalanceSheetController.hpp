#ifndef BALANCESHEETCONTROLLERHPP
#define BALANCESHEETCONTROLLERHPP

#include "./User/User.hpp"
#include "./Expense/Expense.hpp"
#include "UserExpenseBalanceSheet.hpp"
#include <unordered_map>
#include <string>
using namespace std;

class Split;
class User;
class UserExpenseBalanceSheet;

class BalanceSheetController
{
public:
    void updateUserExpenseBalanceSheet(User *expensePaidBy, vector<Split *> splits, double totalExpenseAmount)
    {
        UserExpenseBalanceSheet *paidByUserExpenseSheet = expensePaidBy->getUserExpenseBalanceSheet();
        paidByUserExpenseSheet->setTotalPayment(paidByUserExpenseSheet->getTotalPayment() + totalExpenseAmount);

        for (auto split : splits)
        {
            User *userOwe = split->getUser();
            UserExpenseBalanceSheet *oweUserExpenseSheet = userOwe->getUserExpenseBalanceSheet();
            double oweAmount = split->getAmountOwe();

            if (expensePaidBy->getUserId() == userOwe->getUserId())
            {
                paidByUserExpenseSheet->setTotalYourExpense(paidByUserExpenseSheet->getTotalYourExpense() + oweAmount);
            }
            else
            {
                paidByUserExpenseSheet->setTotalYouGetBack(paidByUserExpenseSheet->getTotalYouGetBack() + oweAmount);

                Balance *userOweBalance;
                if (paidByUserExpenseSheet->userVsBalance.count(userOwe->getUserId()) > 0) // Access directly
                {
                    userOweBalance = paidByUserExpenseSheet->userVsBalance[userOwe->getUserId()];
                }
                else
                {
                    userOweBalance = new Balance();
                    paidByUserExpenseSheet->userVsBalance[userOwe->getUserId()] = userOweBalance;
                }

                userOweBalance->setAmountGetBack(userOweBalance->getAmountGetBack() + oweAmount);

                oweUserExpenseSheet->setTotalYouOwe(oweUserExpenseSheet->getTotalYouOwe() + oweAmount);
                oweUserExpenseSheet->setTotalYourExpense(oweUserExpenseSheet->getTotalYourExpense() + oweAmount);

                Balance *userPaidBalance;
                if (oweUserExpenseSheet->userVsBalance.count(expensePaidBy->getUserId()) > 0) // Access directly
                {
                    userPaidBalance = oweUserExpenseSheet->userVsBalance[expensePaidBy->getUserId()];
                }
                else
                {
                    userPaidBalance = new Balance();
                    oweUserExpenseSheet->userVsBalance[expensePaidBy->getUserId()] = userPaidBalance;
                }
                userPaidBalance->setAmountOwe(userPaidBalance->getAmountOwe() + oweAmount);
            }
        }
    }

    void showBalanceSheetOfUser(User *user)
    {
        cout << "-------------------------------------" << endl;

        cout << "Balance Sheet of User: " << user->getUserId() << endl;

        UserExpenseBalanceSheet *userExpenseBalanceSheet = user->getUserExpenseBalanceSheet();

        cout << "Total Your Expense : " << userExpenseBalanceSheet->getTotalYourExpense() << endl;
        cout << "Total Get Back : " << userExpenseBalanceSheet->getTotalYouGetBack() << endl;
        cout << "Total You Owe : " << userExpenseBalanceSheet->getTotalYouOwe() << endl;
        cout << "Total Payment : " << userExpenseBalanceSheet->getTotalPayment() << endl;

        for (auto entry : userExpenseBalanceSheet->userVsBalance) // Access directly
        {
            string userId = entry.first;
            Balance *balance = entry.second;

            cout << "userId : " << userId << " You Get Back: " << balance->getAmountGetBack() << " You Owe: " << balance->getAmountOwe() << endl;
        }

        cout << "-------------------------------------" << endl;
    }
};

#endif