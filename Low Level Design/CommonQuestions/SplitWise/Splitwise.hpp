#ifndef SPLITWISE_HPP
#define SPLITWISE_HPP

#include "./Expense/ExpenseSplitType.hpp"
#include "./Expense/Split/Split.hpp"
#include "./Group/Group.hpp"
#include "./Group/GroupController.hpp"
#include "./User/User.hpp"
#include "./User/UserController.hpp"
#include "./Expense/ExpenseSplitType.hpp"
#include "BalanceSheetController.hpp"
#include <bits/stdc++.h>
using namespace std;

enum ExpenseSplitType;
class Split;
class Group;
class GroupController;
class User;
class UserController;
class BalanceSheetController;
enum ExpenseSplitType;

class Splitwise{
    public:
        UserController* userController;
        GroupController* groupController;

        BalanceSheetController* balanceSheetController;

        Splitwise()
        {
            userController = new UserController();
            groupController = new GroupController();
            balanceSheetController = new BalanceSheetController();
        }

        void setupUserAndGroup()
        {
            addUsersToSplitwiseApp();

            User* user1 = userController->getUser("U1001");
            groupController->createNewGroup("G1001","Outing with Friends",user1);
        }

        void demo()
        {
            setupUserAndGroup();

            Group* group = groupController->getGroup("G1001");
            group->addMember(userController->getUser("U2001"));
            group->addMember(userController->getUser("U3001"));

            vector<Split*> splits = vector<Split*>();
            Split* split1 = new Split(userController->getUser("U1001"),300);
            Split* split2 = new Split(userController->getUser("U2001"),300);
            Split* split3 = new Split(userController->getUser("U3001"),300);

            splits.push_back(split1);
            splits.push_back(split2);
            splits.push_back(split3);
            group->createExpense("Exp1001","Breakfast",900,splits,ExpenseSplitType::EQUAL,userController->getUser("U1001"));

            vector<Split*> splits2;
            Split* splits2_1 = new Split(userController->getUser("U1001"),400);
            Split* splits2_2 = new Split(userController->getUser("U2001"),100);

            splits2.push_back(splits2_1);
            splits2.push_back(splits2_2);
            
            group->createExpense("Exp1002","Lunch",500,splits2,ExpenseSplitType::UNEQUAL,userController->getUser("U2001"));

            for(auto user : userController->getAllUsers())
            {
                balanceSheetController->showBalanceSheetOfUser(user);
            }
        }

        private:
            void addUsersToSplitwiseApp()
            {
                User* user1 = new User("U1001","User1");
                User* user2 = new User("U2001","User2");
                User* user3 = new User("U3001","User3");

                userController->addUser(user1);
                userController->addUser(user2);
                userController->addUser(user3);
            }
};

#endif