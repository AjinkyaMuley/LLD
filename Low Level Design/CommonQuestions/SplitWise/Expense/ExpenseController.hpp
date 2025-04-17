#ifndef EXPENSECONTROLLERHPP
#define EXPENSECONTROLLERHPP

#include "../User/User.hpp"
#include "./Split/ExpenseSplit.hpp"
#include "./Split/Split.hpp"
#include "../BalanceSheetController.hpp"
#include "ExpenseSplitType.hpp"
#include "SplitFactory.hpp"
#include "Expense.hpp"

class User;
class Split;
class ExpenseSplit;
class BalanceSheetController;
class SplitFactory;
class Expense;
enum ExpenseSplitType;

class ExpenseController{
    public:
        BalanceSheetController* balanceSheetController;
        
        ExpenseController()
        {
            balanceSheetController = new BalanceSheetController();
        }

        Expense* createExpense(string expenseId,string description,double expenseAmount,vector<Split*>& splits,ExpenseSplitType splitType,User* paidByUser)
        {
            ExpenseSplit* expenseSplit = SplitFactory ::getSplitObject(splitType);
            expenseSplit->validateSplitRequest(splits,expenseAmount);

            Expense* expense = new Expense(expenseId,expenseAmount,description,paidByUser,splitType,splits);

            balanceSheetController->updateUserExpenseBalanceSheet(paidByUser,splits,expenseAmount);

            return expense;
        }
};

#endif