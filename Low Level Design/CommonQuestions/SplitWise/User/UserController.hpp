#ifndef USERCONTROLLER_HPP
#define USERCONTROLLER_HPP

#include "User.hpp"
#include <bits/stdc++.h>
using namespace std;

class User;

class UserController{
    public:
        vector<User*> userList;

        UserController()
        {
            userList = vector<User*>();
        }

        // add user
        void addUser(User* user)
        {
            userList.push_back(user);
        }

        // get user
        User* getUser(string userId)
        {
            for(auto user : userList)
            {
                if(user->getUserId() == userId)
                {
                    return user;
                }
            }
            return NULL;
        }

        vector<User*> getAllUsers()
        {
            return userList;
        }
};


#endif