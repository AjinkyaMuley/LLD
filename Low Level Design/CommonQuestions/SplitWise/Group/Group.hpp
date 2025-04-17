#ifndef GROUP_HPP
#define GROUP_HPP

#include "../User/User.hpp"
#include "../Expense/Expense.hpp"
#include "../Expense/ExpenseController.hpp"
#include "../Expense/ExpenseSplitType.hpp"
#include "../Expense/Split/Split.hpp"
#include<bits/stdc++.h>
using namespace std;

class User;
class Expense;
class ExpenseController;
enum ExpenseSplitType;
class Split;

class Group{
    public:
        string groupId;
        string groupName;
        vector<User*> groupMembers;

        vector<Expense*> expenseList;

        ExpenseController* expenseController;

        Group()
        {
            groupMembers = vector<User*>();
            expenseList = vector<Expense*>();
            expenseController = new ExpenseController();
        }

        void addMember(User* member)
        {
            groupMembers.push_back(member);
        }

        string getGroupId()
        {
            return groupId;
        }
        void setGroupId(string groupId)
        {
            this->groupId = groupId;
        }

        void setGroupName(string groupName)
        {
            this->groupName = groupName;
        }

        Expense* createExpense(string expenseId,string description,double expenseAmount,vector<Split*>& splits,ExpenseSplitType splitType,User* paidByUser)
        {
            Expense* expense = expenseController->createExpense(expenseId,description,expenseAmount,splits,splitType,paidByUser);
            expenseList.push_back(expense);
            return expense;
        }
};


#endif